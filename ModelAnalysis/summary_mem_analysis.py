import pandas as pd
import glob
import os
from collections import Counter

def summarize_mem_analysis(folder_path):
    combined_data = pd.DataFrame()
    
    column_names = ['model_name',
                    'Max IFM (MB)', 
                    'Max OFM (MB)',
                    'Max IFM+OFM (MB)',
                    'Max Wts (MB)',
                    'Total Ops',
                    'is_supported',
                    'Spilling(IFM+OFM > 1.5MB)',
                    '%Spilling(IFM+OFM > 1.5MB)',
                    'Wts Super Itr(wts > 1MB)',
                    '%Wts Super Itr(wts > 1MB)',
                    'FM > 1.5 & Wts > 1MB',
                    'opType (FM > 1.5 & Wts > 1MB)',
                    '(FM > 1.5 & Wts > 1MB)%',
                    'Remarks'
                    ]
    
    excel_files = glob.glob(f"{folder_path}/*.xlsx")
    empty_df = pd.DataFrame(columns=column_names)
    
    for file in excel_files:
        df = pd.read_excel(file)
        
        op_types = df[df['Wts>1MB & FM>1.5'] > 0]['opType'].tolist()
        op_type_counts = Counter(op_types)

        support = True
        no_support_nodes = df[df['is_supported'] == False]
        if len(no_support_nodes) != 0:
            support = False

        # Filter rows where 'remark' column is not empty
        non_empty_remarks = df[df['Remark'] == 'Not Shape Inferred']
        if len(non_empty_remarks) != 0:
            remark = 'Not Shape Inferred'
        else:
            remark = "NA"
        
        # Transform opType counts into the desired format
        transformed_op_types = [f"{op_type}:{op_type_counts[op_type]}" for op_type in op_type_counts]
        op_types_str = '\n'.join(transformed_op_types)
        percentage_1 = (df['ifm+ofm (MB)'].gt(1.5).sum()/df['operator_name'].count())*100
        percentage_2 = (df['weights (MB)'].gt(1).sum()/df['operator_name'].count())*100
        percentage_3 = ((df['Wts>1MB & FM>1.5'] == 1).sum()/df['operator_name'].count())*100
        row_data = [df['model_name'].iloc[0],
                    round(df['in (MB)'].max(), 2),
                    round(df['out (MB)'].max(), 2),
                    round(df['ifm+ofm (MB)'].max(), 2),
                    round(df['weights (MB)'].max(), 2),
                    df['operator_name'].count(),
                    support,
                    df['ifm+ofm (MB)'].gt(1.5).sum(),
                    f'{percentage_1:.2f}%',
                    df['weights (MB)'].gt(1).sum(),
                    f'{percentage_2:.2f}%',
                    (df['Wts>1MB & FM>1.5'] == 1).sum(),
                    op_types_str if op_types_str else "NA",
                    f'{percentage_3:.2f}%',
                    remark if remark else "NA"
                    ]
        
        empty_df.loc[len(empty_df)] = row_data
        
    print(empty_df)
    empty_df.to_excel("memory_analysis_summary.xlsx", index=False, float_format='%g')
