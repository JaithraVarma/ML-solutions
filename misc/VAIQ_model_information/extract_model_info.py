###
# Copyright (C) 2022 Xilinx, Inc
#
# Licensed under the Apache License, Version 2.0 (the "License"). You may
# not use this file except in compliance with the License. A copy of the
# License is located at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations
# under the License.
###

import json
import csv
from onnx2json import convert

models_file = open('models.txt', 'r')
model_names = models_file.read()
model_names = model_names.split('\n')
model_names = [i for i in model_names if i]

all_operators = []

def operator_extraction(jsonFile, csvFile):
    with open(jsonFile) as f:
        d = json.load(f)
    f.close()

    for nodeData in d["graph"]["node"]:
        data = nodeData.get("attribute")
        if data:
            for attrbData in nodeData["attribute"]:
                tdata = attrbData.get("t")
                if tdata:
                    del attrbData["t"]

    if "initializer" in d["graph"]:
        for initData in d["graph"]["initializer"]:
            data = initData.get("rawData")
            if data:
                del initData["rawData"]


    operator_list_all = []
    fields = ['operator', 'occurence']
    rows = []

    for nodeData in d["graph"]["node"]:
        data = nodeData.get("opType")
        if data:
            operator_list_all.append(nodeData["opType"])

    operator_list = []
    operator_list = list(dict.fromkeys(operator_list_all))
    all_operators.append(operator_list)
    for element in operator_list:
        cnt  = operator_list_all.count(element)
        eachOpCnt = []
        eachOpCnt.append(element)
        eachOpCnt.append(cnt)
        rows.append(eachOpCnt)

    with open(jsonFile, "w") as outfile:
        json.dump(d, outfile, indent=2)
    outfile.close()

    with open(csvFile, "w") as operFile:
        csvwriter = csv.writer(operFile)
        csvwriter.writerow(fields)
        csvwriter.writerows(rows)
    operFile.close()

def models_unique_operators():
    model_operators = []
    model_operators = [item for sublist in all_operators for item in sublist]
    model_operators = list(dict.fromkeys(model_operators))
    model_operators = [[el] for el in model_operators]
    print (model_operators)

    fields = ['unique_operator']
    with open("unique_operators.csv", "w") as operFile:
        csvwriter = csv.writer(operFile)
        csvwriter.writerow(fields)
        csvwriter.writerows(model_operators)
    operFile.close()


def main():
    # iterate over onnx models 
    for model in model_names:
        model_net = model.split("/")
        print (str(model_net[-1]) + " model")
        onnx_file = model + "_vaiq.onnx"
        json_file = model + "_vaiq.json"
        csv_file  = model + "_vaiq.csv"
        onnx_json = convert(input_onnx_file_path=onnx_file,
                            output_json_path=json_file,
                            json_indent=2,
                            )
        print ("Extracting operator info for " + str(model_net[-1]) + " model")
        operator_extraction(json_file, csv_file)
        print (str(model_net[-1]) + " model information in json format is available in " + str(json_file))
        print ("Operator information and its occurence are captured in " + str(csv_file) + "\n")

    # to get unique operators from all models run
    models_unique_operators()

if __name__ == "__main__":
    main()
