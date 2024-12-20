import pandas as pd
import os
import json as js
import argparse

def get_tiling_info(tensor_dims_path, df):
    with open(tensor_dims_path, 'r') as f:
        data = js.load(f)
    for key in data.keys():
        if key != '__VERSION__': # ClipBf16 AddBf16 Conv2D Conv2DBf16
            if 'Conv2DBf16' in data[key].keys():
                wts_attr_list = ['kernel_height', 'kernel_width', 'ifm_sv_depth', 'ofm_sv_depth']
                wts_attrs = [data[key]['wts_reader'][attr] if attr in data[key]['wts_reader'].keys() else '-' for attr in wts_attr_list]
                # print(attrs)
                wts_sv = 'x'.join([str(a) for a in wts_attrs[:4]]) if '-' not in wts_attrs[:4] else '-'


                # print(key)
                # print(data[key].keys())
                attr_list = ['num_ifm_height_iters', 'num_ifm_width_iters', 'num_ifm_depth_iters', 'num_ofm_depth_iters', 'ifm_sv_height', 'ifm_sv_width', 'ifm_sv_depth', 'ofm_sv_height', 'ofm_sv_width', 'ofm_sv_depth']
                attrs = [data[key]['Conv2DBf16'][attr] if attr in data[key]['Conv2DBf16'].keys() else '-' for attr in attr_list]
                # print(attrs)
                ifm_sv = 'x'.join([str(a) for a in attrs[4:7]]) if '-' not in attrs[:3] else '-'
                ofm_sv = 'x'.join([str(a) for a in attrs[7:10]]) if '-' not in attrs[3:6] else '-'
                iters = 'x'.join([str(a) for a in attrs[:4]]) if '-' not in attrs[3:6] else '-'
                df.loc[len(df)] = [key, ifm_sv, ofm_sv, wts_sv, iters ]
            
            elif 'AddBf16' in data[key].keys():
                attr_list = ['ifmsv_height', 'ifmsv_width', 'ifmsv_depth', 'num_kernel_iters']
                attrs = [data[key]['AddBf16'][attr] if attr in data[key]['AddBf16'].keys() else '-' for attr in attr_list]
                ifm_sv = 'x'.join([str(a) for a in attrs[:3]]) if '-' not in attrs[:3] else '-'
                ofm_sv = ifm_sv
                iters = attrs[3]
                wts_sv = '-'
                df.loc[len(df)] = [key, ifm_sv, ofm_sv, wts_sv, iters ]
            elif 'ClipBf16' in data[key].keys():
                attr_list = ['ifmsv_height', 'ifmsv_width', 'ifmsv_depth', 'num_kernel_iters']
                attrs = [data[key]['ClipBf16'][attr] if attr in data[key]['ClipBf16'].keys() else '-' for attr in attr_list]
                ifm_sv = 'x'.join([str(a) for a in attrs[:3]]) if '-' not in attrs[:3] else '-'
                ofm_sv = ifm_sv
                iters = attrs[3]
                wts_sv = '-'
                df.loc[len(df)] = [key, ifm_sv, ofm_sv, wts_sv, iters ]
            elif 'MaxPool2DBf16' in data[key].keys():
                attr_list = ['num_iter', 'ifm_sv_height', 'ifm_sv_width', 'ifm_sv_depth', 'ofm_sv_height', 'ofm_sv_width', 'ofm_sv_depth']
                attrs = [data[key]['MaxPool2DBf16'][attr] if attr in data[key]['MaxPool2DBf16'].keys() else '-' for attr in attr_list]
                # print(attrs)
                ifm_sv = 'x'.join([str(a) for a in attrs[1:4]]) if '-' not in attrs[:3] else '-'
                ofm_sv = 'x'.join([str(a) for a in attrs[4:]]) if '-' not in attrs[3:6] else '-'
                iters = attrs[0]
                wts_sv = '-'
                df.loc[len(df)] = [key, ifm_sv, ofm_sv, wts_sv, iters ]

            # print(ifm_dim, ofm_dim, num_kernel_iteration)

    return df


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--config_path', required = True)
    args = parser.parse_args()

    data = js.load(open(args.config_path, 'r'))

    basepath = data['basepath']
    num_pars = data['num_pars']
    df = pd.DataFrame(columns = ['conv_name', 'ifm_sv', 'ofm_sv', 'wts_sv', 'iters'])
    for i in range(num_pars):
        tensor_dims_path = os.path.join(basepath, f'vaiml_par_{i}/0/tensor_dims.json')
        get_tiling_info(tensor_dims_path, df)

    df.to_excel('tiling_info.xlsx', index = False)

if __name__=='__main__':
    main()
