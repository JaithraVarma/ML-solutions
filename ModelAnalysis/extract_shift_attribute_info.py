import pandas as pd
import onnx_graphsurgeon as gs
import onnx
import math
import os
import argparse
import onnx_graphsurgeon
import numpy as np

def extract_model_info_bf16(path):
	# Load the ONNX model
	files = os.listdir(path)

	# Initialize a dictionary to store shift factors for each model
	model_shift_factors = {}
	op_name_shape_attr_mapping={}
	for file in files:
		print(file)
		operator_shift_factors={}
		onnx_model = onnx.load(os.path.join(path, file))
		gs_graph=gs.import_onnx(onnx_model)
		op_name_shape_attr_mapping={}
		for node in gs_graph.nodes:
			if node.op=='Constant':
				continue
			op_name_shape_attr_mapping[node.name]={}
			op_name_shape_attr_mapping[node.name]['Attribute']=node.attrs
			inputs=node.inputs
			if len(inputs)==0:
				continue
			else:
				inp_shapes=[]
				for inp in node.inputs:
					if inp.shape:
						if len(inp.shape)>0:
							inp_shapes.append(inp.shape)
					elif isinstance(inp,onnx_graphsurgeon.ir.tensor.Constant):
						inp_shapes.append(np.array([inp.values]).shape)
				op_name_shape_attr_mapping[node.name]['Shape']=inp_shapes
		for curr_node in onnx_model.graph.node:
			ifm_shifts = {}
			ofm_shifts = {}
			#print(curr_node.name)
			if curr_node.op_type=='Conv':
				shape=op_name_shape_attr_mapping[curr_node.name]['Shape'][0]
				group_val=1
				if 'group' in op_name_shape_attr_mapping[curr_node.name]['Attribute'].keys():
					group_val=op_name_shape_attr_mapping[curr_node.name]['Attribute']['group']
				if group_val>1 and group_val==shape[1]:
					ConvType='DConv'
				elif group_val>1 and group_val!=shape[1]:
					ConvType='GConv'
				else:
					ConvType='Conv'
				op_name_shape_attr_mapping[curr_node.name]['Attribute']['ConvType']=ConvType
			if curr_node.op_type in ['Add','Mul','Div','Sub']:
				shape_0=op_name_shape_attr_mapping[curr_node.name]['Shape'][0]
				shape_1=op_name_shape_attr_mapping[curr_node.name]['Shape'][1]
				if shape_0==shape_1:
					op_name_shape_attr_mapping[curr_node.name]['Attribute']={'Type':curr_node.op_type}
				else:
					op_name_shape_attr_mapping[curr_node.name]['Attribute']={'Type':'Broadcast_'+curr_node.op_type}
			operator_shift_factors[str(curr_node.name)] = {"OP_Type": str(curr_node.op_type),'OP_Attribute':op_name_shape_attr_mapping[curr_node.name]['Attribute'],"Shape_Info":op_name_shape_attr_mapping[curr_node.name]['Shape'],"ifm_shifts": ifm_shifts, "ofm_shifts": ofm_shifts}
		model_shift_factors[file]=operator_shift_factors
	return model_shift_factors
def extract_model_info_int8(path):
	# Load the ONNX model
	files = os.listdir(path)

	# Initialize a dictionary to store shift factors for each model
	model_shift_factors = {}
	op_name_shape_attr_mapping={}
		
	for file in files:
		print(file)
		onnx_model = onnx.load(os.path.join(path, file))
		gs_graph=gs.import_onnx(onnx_model)
		op_name_shape_attr_mapping={}
		for node in gs_graph.nodes:
			if node.op=='Constant':
				continue
			op_name_shape_attr_mapping[node.name]={}
			op_name_shape_attr_mapping[node.name]['Attribute']=node.attrs
			inputs=node.inputs
			if len(inputs)==0:
				continue
			else:
				inp_shapes=[]
				for inp in node.inputs:
					if inp.shape:
						if len(inp.shape)>0:
							inp_shapes.append(inp.shape)
					elif isinstance(inp,onnx_graphsurgeon.ir.tensor.Constant):
						inp_shapes.append(np.array([inp.values]).shape)
				op_name_shape_attr_mapping[node.name]['Shape']=inp_shapes
		
		#print(op_name_shape_attr_mapping)
		# Initialize a dictionary to store shift factors for current model
		operator_shift_factors = {}

		# Define excluded operator types
		excluded_operator_types = []
		tensor_name_tensor_mapping={}
		
		for tensor in onnx_model.graph.initializer:
			tensor_name_tensor_mapping[tensor.name]=tensor
		
		nodes_input_mapping={}
		nodes_output_mapping={}
		for nodes_map in onnx_model.graph.node:
			for value in nodes_map.input:
				if value:
					nodes_input_mapping[value]=nodes_map
			for value in nodes_map.output:
				if value:
					nodes_output_mapping[value]=nodes_map
					
		# Iterate through the graph nodes
		
		for curr_node in onnx_model.graph.node:
			if curr_node.op_type=='QuantizeLinear':
				continue
			if curr_node.op_type=='DequantizeLinear':
				continue
			curr_node_str=str(curr_node.name)
			if curr_node.op_type in excluded_operator_types:
				continue
			if curr_node.op_type in ['Constant']:
				continue
			# Initialize dictionaries to store shift factors for each input/output
			ifm_shifts = {}
			ofm_shifts = {}
			# Iterate through each input of the current node
		   
			for input_name in curr_node.input:
				# Find the input node in the graph
				input_node = None
				if input_name and input_name in nodes_output_mapping.keys():
					
					input_node=nodes_output_mapping[input_name]

				if input_node and input_node.op_type == "DequantizeLinear":
					
					# Extract scale value from initializer tensor
					x_scale_tensor = None
					x_scale_tensor=tensor_name_tensor_mapping[input_node.input[1]]
				   
					if x_scale_tensor:
						# Convert scale tensor value to float
						x_scale = float(x_scale_tensor.float_data[0])
						# Calculate shift factor
						if curr_node.op_type=='Conv':
							x_shift=x_scale
						else:
							x_shift = -1 * math.log2(x_scale)
						# Store shift factor for the input
						ifm_shifts[input_name] = x_shift
			# Iterate through each output of the current node
		   
			for output_name in curr_node.output:
				# Find the output node in the graph
				output_node = None
				if output_name and output_name in nodes_input_mapping.keys():
					output_node=nodes_input_mapping[output_name]
					for next_output_name in output_node.output:
						if next_output_name and next_output_name in nodes_input_mapping.keys():
							next_output_node=nodes_input_mapping[next_output_name]
				if output_node and output_node.op_type == "QuantizeLinear":
					# Extract scale value from initializer tensor
					y_scale_tensor = None
					y_scale_tensor=tensor_name_tensor_mapping[output_node.input[1]]
					
					if y_scale_tensor:
						# Convert scale tensor value to float
						y_scale = float(y_scale_tensor.float_data[0])
						# Calculate shift factor
						if curr_node.op_type=='Conv':
							y_shift=y_scale
						else:
							y_shift = -1 * math.log2(y_scale)
						# Store shift factor for the output
						ofm_shifts[output_name] = y_shift
				
				if output_node and output_node.op_type in ['Relu','LeakyRelu','Linear','Mul','Clip','Clamp','Sigmoid','HardSigmoid']:
					if next_output_node and next_output_node.op_type=='QuantizeLinear':
						y_scale_tensor = None
						y_scale_tensor=tensor_name_tensor_mapping[next_output_node.input[1]]
						
						if y_scale_tensor:
							# Convert scale tensor value to float
							y_scale = float(y_scale_tensor.float_data[0])
							# Calculate shift factor
							if curr_node.op_type=='Conv':
								y_shift=y_scale
							else:
								y_shift = -1 * math.log2(y_scale)
							ofm_shifts[next_output_node.input[0]] = y_shift
			if curr_node.op_type=='Conv':
			  
				shape=op_name_shape_attr_mapping[curr_node_str]['Shape'][0]
				group_val=1
				if 'group' in op_name_shape_attr_mapping[curr_node.name]['Attribute'].keys():
					group_val=op_name_shape_attr_mapping[curr_node.name]['Attribute']['group']
				
				group_val=op_name_shape_attr_mapping[curr_node_str]['Attribute']['group']
				if group_val>1 and group_val==shape[1]:
					ConvType='DConv'
				elif group_val>1 and group_val!=shape[1]:
					ConvType='GConv'
				else:
					ConvType='Conv'
				
				ifm_scale_list=list(ifm_shifts.values())
				output_scale_factor=list(ofm_shifts.values())[0]
				input_scale_factor=ifm_scale_list[0]
				weight_scale_factor=ifm_scale_list[1]
				
				bias_scale_factor=1
				if len(ifm_scale_list)==3:
					bias_scale_factor=ifm_scale_list[2]
				shift_bias_init=math.log2((input_scale_factor*weight_scale_factor)/bias_scale_factor)
				shift_out=math.log2(output_scale_factor/(input_scale_factor*weight_scale_factor))
				op_name_shape_attr_mapping[curr_node_str]['Attribute']['ConvType']=ConvType
				operator_shift_factors[curr_node_str] = {"OP_Type": str(curr_node.op_type),'OP_Attribute':op_name_shape_attr_mapping[curr_node.name]['Attribute'],"Shape_Info":op_name_shape_attr_mapping[curr_node.name]['Shape'] ,"ifm_shifts": {'shift_bias_init':shift_bias_init}, "ofm_shifts":{"shift_out":shift_out}}
			
			elif curr_node.op_type in ['Add','Mul','Div','Sub']:
				try:
					#print(curr_node_str,op_name_shape_attr_mapping[curr_node_str])
					shape_0=op_name_shape_attr_mapping[curr_node_str]['Shape'][0]
					shape_1=op_name_shape_attr_mapping[curr_node_str]['Shape'][1]
					if shape_0==shape_1:
						op_name_shape_attr_mapping[curr_node_str]['Attribute']={'Type':curr_node.op_type}
					else:
						op_name_shape_attr_mapping[curr_node_str]['Attribute']={'Type':'Broadcast_'+curr_node.op_type}
				except:
					op_name_shape_attr_mapping[curr_node_str]['Attribute']={'Type':'Broadcast_'+curr_node.op_type}
				operator_shift_factors[curr_node_str] = {"OP_Type": str(curr_node.op_type),'OP_Attribute':op_name_shape_attr_mapping[curr_node.name]['Attribute'],"Shape_Info":op_name_shape_attr_mapping[curr_node.name]['Shape'] ,"ifm_shifts": ifm_shifts, "ofm_shifts": ofm_shifts}
			else:
				operator_shift_factors[curr_node_str] = {"OP_Type": str(curr_node.op_type),'OP_Attribute':op_name_shape_attr_mapping[curr_node.name]['Attribute'],"Shape_Info":op_name_shape_attr_mapping[curr_node.name]['Shape'] ,"ifm_shifts": ifm_shifts, "ofm_shifts": ofm_shifts}

		# Store shift factors for the current model in the model_shift_factors dictionary
		model_shift_factors[file] = operator_shift_factors
	return model_shift_factors
	
def generate_info_excel(path,filename,dtype='int8'):
	if dtype=='int8':
		model_shift_factors=extract_model_info_int8(path)
	elif dtype=='bf16':
		print("Inside")
		model_shift_factors=extract_model_info_bf16(path)

	Model_Name_List=[]
	for model in model_shift_factors.keys():
		length=len(model_shift_factors[model])
		model_list=[model for j in range(length)]
		Model_Name_List=Model_Name_List+model_list
	Operator_Name=[]
	Operator_Type=[]
	Ifm_Shift=[]
	Ofm_Shift=[]
	Input_Names=[]
	Output_Names=[]
	Attribute_Names=[]
	Shape_Info=[]

	for i in model_shift_factors.keys():
		op_name_list=list(model_shift_factors[i].keys())
		Operator_Name=Operator_Name+op_name_list
		for j in op_name_list:
			Operator_Type.append(model_shift_factors[i][j]['OP_Type'])
			Ifm_Shift.append(list(model_shift_factors[i][j]['ifm_shifts'].values()))
			Ofm_Shift.append(list(model_shift_factors[i][j]['ofm_shifts'].values()))
			Attribute_Names.append(dict(model_shift_factors[i][j]['OP_Attribute']))
			Shape_Info.append(list(model_shift_factors[i][j]['Shape_Info']))


	df=pd.DataFrame()
	df['Model_Name']=Model_Name_List
	df['Operator_Name']=Operator_Name
	df['Operator_Type']=Operator_Type
	df['Operator_Attributes']=Attribute_Names
	df['Input_Shape']=Shape_Info
	df['Ifm_Shift']=Ifm_Shift
	df['Ofm_Shift']=Ofm_Shift

		# Create a summary dataframe
	operator_shift_summary={}
	for idx, row in df.iterrows():
		if row['Operator_Type'] not in operator_shift_summary.keys():
			operator_shift_summary[row['Operator_Type']]={'ifm_shift':[],'ofm_shift':[]}
			operator_shift_summary[row['Operator_Type']]['ifm_shift']+=row['Ifm_Shift']
			operator_shift_summary[row['Operator_Type']]['ofm_shift']+=row['Ofm_Shift']
		else:
			operator_shift_summary[row['Operator_Type']]['ifm_shift']+=row['Ifm_Shift']
			operator_shift_summary[row['Operator_Type']]['ofm_shift']+=row['Ofm_Shift']
	for i in operator_shift_summary.keys():
		operator_shift_summary[i]['ifm_shift']=list(set(operator_shift_summary[i]['ifm_shift']))
		operator_shift_summary[i]['ofm_shift']=list(set(operator_shift_summary[i]['ofm_shift']))

	# Convert dictionary to DataFrame
	df_shift_summary = pd.DataFrame.from_dict(operator_shift_summary, orient='index').reset_index()

	# Rename the 'index' column to 'Operator_Type'
	df_shift_summary= df_shift_summary.rename(columns={'index': 'Operator_Type'})

	# Create a Pandas Excel writer using XlsxWriter as the engine.
	with pd.ExcelWriter(filename+'.xlsx') as writer:
		# Write each dataframe to a different worksheet.
		df.to_excel(writer, sheet_name='Model_Info', index=False)
		df_shift_summary.to_excel(writer, sheet_name='Shift_Value_Summary', index=False)


