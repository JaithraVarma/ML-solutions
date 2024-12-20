import timm
import torch
import pandas as pd
from torchinfo import summary

#name of the model
modelname = 'inception_v4'

#load your model
def get_model():
    model = timm.create_model('inception_v4.tf_in1k', pretrained=True)
    model = model.eval()
    return model

#give the sample input shape
def get_input():
    return torch.randn((1, 3, 224, 224))


def process_excel(input_file, output_file):
    # Read the Excel file into a pandas DataFrame
    df = pd.read_excel(input_file)

    # Create a new column 'duplicated_layers' with empty values
    df['duplicated_layers'] = ''

    # Iterate through each row to find duplicates
    for index, row in df.iterrows():
        # Create a mask to filter rows with matching properties
        mask = (df['operator_name'] == row['operator_name']) & \
               (df['input_size'] == row['input_size']) & \
               (df['output_size'] == row['output_size']) & \
               (df['macs'] == row['macs']) & \
               (df['attributes'] == row['attributes'])

        # Get the matching layers excluding the current layer
        duplicate_layers = '   '.join(df.loc[mask, 'layer'].tolist())
        duplicate_layers = duplicate_layers.replace(row['layer'], '')  # Exclude the current layer

        # Update the 'duplicated_layers' column with matching layers
        df.at[index, 'duplicated_layers'] = duplicate_layers

    # Drop duplicate rows based on selected columns and keep the first occurrence
    df.drop_duplicates(subset=['operator_name', 'input_size', 'output_size', 'macs', 'attributes'], keep='first', inplace=True)

    # Save the modified DataFrame to a new Excel file
    df.to_excel(output_file, index=False)

    return


def main():

    model = get_model()
    sample_input = get_input()

    results = summary(model, input_data=sample_input, depth=100, col_names=["input_size", "output_size", "mult_adds", "num_params"])
    summary_list = results.summary_list

    df = pd.DataFrame()
    layer_num = 0
    # Iterate over each class in the summary_list
    for i, class_obj in enumerate(summary_list):
        # Create a dictionary to store the variable values
        if class_obj.is_leaf_layer == True and class_obj.class_name == 'Conv2d':
            layer_num = layer_num + 1
            class_data = {
                "layer": f"L{layer_num}",
                "operator_name": class_obj.class_name,
                "input_size": class_obj.input_size,
                "output_size": class_obj.output_size,
                "macs": class_obj.macs,
                "attributes": class_obj.module
            }
            # Append the class data as a new row in the DataFrame
            temp = pd.DataFrame(data=[class_data])
            df = pd.concat([df, temp], ignore_index=True)

    # Create an Excel writer object
    temp = modelname.split('/')
    if len(temp)==2:
        excel_name = "models--" + temp[1] + "--" + temp[0] + ".xlsx"
        txt_name = "models--" + temp[1] + "--" + temp[0] + ".txt"
    else:
        excel_name = "models--" + temp[0] + ".xlsx"
        txt_name = "models--" + temp[0] + ".txt"
    excel_name = str(excel_name)
    txt_name = str(txt_name)
    with pd.ExcelWriter(excel_name, engine="xlsxwriter") as writer:
        # Write the DataFrame to the Excel sheet
        df.to_excel(writer, index=False, sheet_name="Summary")
    with open(txt_name, "w+") as txtfile:
        # Write the model architecture to .txt file
        txtfile.write(str(results))

    process_excel(excel_name, excel_name)

    return

if __name__ == '__main__':
    main()