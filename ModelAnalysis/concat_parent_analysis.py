import pandas as pd
import sys

def filter_excel(input_file, output_file):
    print("\nStarting Concat Parent Analysis\n")
    df = pd.read_excel(input_file)
    #import pdb; pdb.set_trace()
    df['inputs'].fillna('[]', inplace=True)
    df['outputs'].fillna('[]', inplace=True)
    df['inputs'] = df['inputs'].astype(str).apply(eval)
    df['outputs'] = df['outputs'].astype(str).apply(eval)
    concat_rows = df[df['opType'] == 'Concat']
    parent_nodes = []
    for index, row in concat_rows.iterrows():
        concat_inputs = row['inputs']
        for input_val in concat_inputs:
            parent_rows = df[(df['outputs'].apply(lambda x: input_val in x)) & (df['model_name'] == row['model_name'])]
            parent_nodes.extend(parent_rows.to_dict(orient='records'))

    if len(parent_nodes) == 0:
        return 0
    
    result_df = pd.DataFrame(parent_nodes)
    
    result_df['weight+fm (MB)'] = round(result_df['weights (MB)'] + result_df['ifm+ofm (MB)'],2)

    selected_columns = ['model_name', 'operator_name', 'opType',
                         'in (MB)', 'out (MB)', 'weights (MB)', 'ifm+ofm (MB)',
                         'Wts>1MB & FM>1.5', 'weight+fm (MB)', 'Remark']
    
    result_df = result_df[selected_columns]
    result_df.to_excel(output_file, index=False)

    selected_models = result_df[(result_df['ifm+ofm (MB)'] > 1.5) | (result_df['weight+fm (MB)'] >= 2)]
    selected_models = list(set(selected_models['model_name'].tolist()))
    print("\nModels with 'ifm+ofm (MB)' > 1.5MB or 'weight+fm (MB)' >= 2MB:")
    print(selected_models)
    print("\nCount of selected models:", len(selected_models))
    return selected_models

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Expected Usage: python concat_filterer.py input_file.xlsx output_file.xlsx")
        sys.exit(1)

    input_file_path = sys.argv[1]
    output_file_path = sys.argv[2]
    shortlisted_models = ["draw_linear-v1-fp32-512x512-ox",
                          "isoa-v1-fp32-512x512",
                          "sm_auto-v1-fp32-512x512",
                          "slsp-v3-fp32-512x512-ox",
                          "smb-v1-fp32-512x512",
                          "gmp-v2-fp32-192x192-2x",
                          "ggi-v2-fp32-192x192-4x",
                          "ghq-v5-gaia-fp16-576x672-4x"]

    selected_models = filter_excel(input_file_path, output_file_path)

    if selected_models != 0:
        selected_shortlisted_models = [model for model in selected_models if any(model.startswith(name) for name in shortlisted_models)]
        print("\n Shortlisted Models with 'ifm+ofm (MB)' > 1.5MB or 'weight+fm (MB)' >= 2MB:")
        print(selected_shortlisted_models)
        print("\nCount of shortlisted models:", len(selected_shortlisted_models))
