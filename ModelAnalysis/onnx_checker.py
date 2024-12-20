import onnx
import os
import math
import onnxruntime
import numpy as np
from collections import Counter
import csv
import pandas as pd

class OnnxChecker:
    def __init__(self, model_path, csv_file_path):
        self.model_path=model_path
        self.csv_file_path = csv_file_path
        self.model = onnx.load(self.model_path)

    def check_onnx(self):
        try:
            onnx.checker.check_model(self.model)
            return True
        except Exception as e:
            return False

    def check_opset(self):
        opset_version = self.model.opset_import[0].version if self.model.opset_import else None
        if opset_version == 17:
            return True
        else:
            return False
        
    def check_model_precision(self):
        for node in self.model.graph.node:
            if node.op_type == "QuantizeLinear":
                return "INT8"
        return "FP32"
 
    def get_node_names(self):
        scale = []
        zero_pt = []
        for node in self.model.graph.node:
            if node.op_type == 'QuantizeLinear' or node.op_type == 'DequantizeLinear':
                scale.append(node.input[1])
                zero_pt.append(node.input[2])
        return scale, zero_pt

    def check_power_of_two(self):
        scale, _ = self.get_node_names()
        fault_scale = []
        write_stop = 0
        for node in self.model.graph.node:
            if node.output[0] in scale:
                # print(f"{self.model_path}    :  {node.name}            : {node.attribute}")  
                # if there is an error occuring at scale value for a node, the error gets printed at error log in model analysis and then moves onto the next node.
                try:
                    scale_value = onnx.numpy_helper.to_array(node.attribute[0].t)

                except Exception as e:
                    if write_stop:
                        continue
                    file_name = self.model_path[self.model_path.rfind('/') + 1: ]
                    with open(self.csv_file_path, mode='a', newline='') as file:
                        writer = csv.writer(file)
                        writer.writerow(['model_info_analysis', file_name.replace('.onnx', ''), str(e)])
                        write_stop = 1
                    continue
                if not math.log2(scale_value).is_integer():
                    fault_scale.append(node.output[0])
        if len(fault_scale) != 0:
            return 'scale fault at {}'.format(fault_scale)
        else:
            return 'Pass'

    def check_zero_point(self):
        _, zero_pt = self.get_node_names()
        non_zero_pt = []
        write_stop = 0
        for node in self.model.graph.node:
            if node.output[0] in zero_pt:
                # if there is an error occuring at scale value for a node, the error gets printed at error log in model analysis and then moves onto the next node.
                try:
                    scale_value = onnx.numpy_helper.to_array(node.attribute[0].t)
                except Exception as e:

                    if write_stop:
                        continue
                    file_name = self.model_path[self.model_path.rfind('/') + 1: ]
                    with open(self.csv_file_path, mode='a', newline='') as file:
                        writer = csv.writer(file)
                        writer.writerow(['model_info_analysis', file_name.replace('.onnx', ''), str(e)])
                        write_stop = 1
                    continue
                if scale_value != 0:
                    non_zero_pt.append(node.output[0])
        if len(non_zero_pt) != 0:
            return 'zero point fault at {}'.format(non_zero_pt)
        else:
            return 'Pass'

    def get_precision_dtype(self, input_type):
        ''' Takes the input type of the onnx model and returns the respective precision'''
        precision_dict = {
            'tensor(float)': np.float32,
            'tensor(float16)': np.float16,
            'tensor(int32)': np.int32,
            'tensor(int64)': np.int64,
            'tensor(double)': np.float64
        }
        return precision_dict.get(input_type, np.float32)
    
    def infer_check(self):
      try:
        session = onnxruntime.InferenceSession(self.model_path)

        input_infos = session.get_inputs()

        # Create a dictionary with input names and shapes
        input_arrays_dict = {}
        for input_info in input_infos:
            shape = input_info.shape
            model_type = input_info.type
            precision_dtype = self.get_precision_dtype(model_type)
            input_arrays_dict[input_info.name] = np.random.randn(*shape).astype(precision_dtype)

        # Print input names and shapes
        for input_name, input_array in input_arrays_dict.items():
            print(f"Input name: {input_name}, Array shape: {input_array.shape}")
        
        output = session.run(None, input_arrays_dict)
        return 'pass', None
      except Exception as e:
        return 'Fail', str(e)

    def check_batch_size(self):
        input_shapes = [input_tensor.type.tensor_type.shape.dim for input_tensor in self.model.graph.input]
        batch_size = input_shapes[0][0].dim_value if input_shapes[0][0].dim_value else "Dynamic"
        if batch_size == 1:
            return True
        else:
            return f'batch_size is {batch_size}'


    def check_shape_infer(self):
        "check model shape infered or not.  check for unk_ and ? in shapes"
        if len(self.model.graph.value_info) == 0:
            return False
        for node_op in self.model.graph.value_info:
            dynamic_operator = None
            shape = [x.dim_value for x in node_op.type.tensor_type.shape.dim]
            if len(shape)!=0 and 0 in shape:
                xx = node_op.name
                for node in self.model.graph.node:
                    if node.output[0] == xx:
                        dynamic_operator = node.op_type
    
            if dynamic_operator != None:
                return 'Partial'
        return True
    
    def check_repeated_node_names(self):
        model = onnx.load(self.model_path)
        node_names = [node.name for node in model.graph.node]
        name_counts = Counter(node_names)
        repeated_names = {name: count for name, count in name_counts.items() if count > 1}
        if repeated_names:
            return f"Repeated node names found: {repeated_names}"
        else:
            return None
