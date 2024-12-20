import re
import pandas as pd

class LogExtractor:
    def __init__(self):
        # Initialize dictionaries for CPU and AIE operations for each partition from 1 to 7
        self.partition_wise_cpu_ops = {i: {} for i in range(1, 8)}
        self.partition_wise_aie_ops = {i: {} for i in range(1, 8)}
        # Tracking the order of partitions as they appear
        self.partition_order = {}
        self.partition_count = 0

    def extract_operations(self, lines, start_index, end_index, operation_type):
        # Extract operations based on the specified type (CPU or AIE)
        operation_start = False
        operation_string = ""
        operation_count = 0

        for i in range(start_index, end_index):
            line = lines[i].strip()

            if f"Operation statistics for {operation_type}" in line:
                operation_start = True
                operation_count = 0
                continue

            if operation_start and operation_count < 2:  # Skip initial lines after operation section starts
                operation_count += 1
                continue

            if operation_start:
                if "-----------------------" in line:  # End of operation section
                    break
                operation_string += line.strip() + "\n"

        return operation_string.strip()

    def get_dict(self, string):
        if pd.isna(string):
            return 'NAN'
        temp=re.sub(' ','',string).split('\n')
        if len(temp[0])==0:
            return 'NAN'

        try:
            list_temp=[(','.join(':'.join(','.join(i.split(',')[1:]).split(":")[3:]).split(',')[:-1]),':'.join(','.join(i.split(',')[1:]).split(":")[3:]).split(',')[-1]) for i in temp]
            # list_temp = [(','.join(i.split(',')[:-1]), i.split(',')[-1]) for i in temp]
        except:
            
            list_temp = [(i.split(',')[0],i.split(',')[1]) for i in temp]
        # print(dict(list_temp))
        return dict(list_temp)

    def process_log(self, text):
        lines = text.split('\n')
        i = 0

        while i < len(lines):
            match = re.search(r"vaiml_par_(\d+)/OnnxModel.chained_kernel.tosa.mlir", lines[i])
            if match:
                partition_num = int(match.group(1))

                if partition_num not in self.partition_order and self.partition_count < 7:
                    self.partition_count += 1
                    self.partition_order[partition_num] = self.partition_count

                mapped_partition_num = self.partition_order.get(partition_num)
                
                next_partition_index = i + 1
                while next_partition_index < len(lines) and not re.search(r"vaiml_par_(\d+)/OnnxModel.chained_kernel.tosa.mlir", lines[next_partition_index]):
                    next_partition_index += 1

                cpu_ops = self.extract_operations(lines, i + 1, next_partition_index, "CPU")
                aie_ops = self.extract_operations(lines, i + 1, next_partition_index, "AIE")
                
                cpu_ops_dict = self.get_dict(cpu_ops)
                aie_ops_dict = self.get_dict(aie_ops)

                if mapped_partition_num:
                    self.partition_wise_cpu_ops[mapped_partition_num] = cpu_ops_dict
                    self.partition_wise_aie_ops[mapped_partition_num] = aie_ops_dict

                i = next_partition_index
            else:
                i += 1

    # def display_operations(self):
    #     print("Partition-wise CPU Operations:")
    #     for partition, ops in self.partition_wise_cpu_ops.items():
    #         print(f"Partition {partition}: {ops}")

    #     print("\nPartition-wise AIE Operations:")
    #     for partition, ops in self.partition_wise_aie_ops.items():
    #         print(f"Partition {partition}: {ops}")

    def process_output_file(self, file_path):
        try:
            with open(file_path, 'r') as file:
                log_content = file.read()
            self.process_log(log_content)
            # self.display_operations()  # Display the results
            return self.partition_wise_cpu_ops, self.partition_wise_aie_ops
        except FileNotFoundError:
            print(f"File at {file_path} not found.")
        except Exception as e:
            print(f"An error occurred while processing the file: {e}")

