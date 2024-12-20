import re
import argparse
import linecache

def search(fms, line, data):
    if fms in line:
        result = re.search('{(.*)}', line)
        temp = result.group(1)
        ip = temp.split(',')
        input = list(map(int, ip))
        #(input)
        data.append(input)
    return data

def get_fmsv(ifmsv, ofmsv, tiling_file):
    with open(tiling_file) as header_file:
        dataInput = []
        dataOutput = []
        for line in header_file.readlines():
            dataInput = search(ifmsv, line, dataInput)
            dataOutput = search(ofmsv, line, dataOutput)
    dataLog = list(zip(dataInput, dataOutput))
    return dataLog

def get_lines(mlo_file):
    lines = []
    start_line = "std::vector<uint32_t> wts_ddr_offset = {"
    end_line = "};"
    f = open(mlo_file, 'r')
    # Skip lines until the start line is found
    for line in f:
        if line.strip() == start_line:
            break
    # Read lines until the end line is found
    for line in f:
        if line.strip() == end_line:
            break
        lines.append(line.strip())
    return lines

def get_offset(dataOffset, mlo_file):
    with open(mlo_file, 'r') as file:
        lines = get_lines(mlo_file)
        lines[-1] = lines[-1].replace('/4//', '/4,//')
        lines = [s.split('/4,//')[0] for s in lines]
        lines = [int(s) for s in lines]
        dataOffset = [int(x/4) for x in lines]
        return dataOffset

def get_wts(lst, offset, wts_file):
    #print(offset)
    for i in offset:
        # linecache access line 1 as first so i+1
        line = linecache.getline(wts_file, i+1)
        lst.append(line.replace('\n', ''))
    return lst

# getting parameters of a single layer
def get_layer_wts(l_offset, wts_file):
    lst = []
    for i in range(32):
        line = linecache.getline(wts_file, l_offset+1+i)
        lst.append(line.replace('\n', ''))
    return lst

def convert_wts(l_wts):
    l_int_wts = []
    for number in l_wts:
        # Example 8-digit number
        # Convert the number to a string
        number_string = str(number)
        # Extract each 2-digit number using string slicing
        number_4 = int(number_string[0:2], 16)
        number_3 = int(number_string[2:4], 16)
        number_2 = int(number_string[4:6], 16)
        number_1 = int(number_string[6:8], 16)
        # Print the result
        l_int_wts.append(number_1)
        l_int_wts.append(number_2)
        l_int_wts.append(number_3)
        l_int_wts.append(number_4)
    return l_int_wts

def get_mllib_conv_type(mlir_file):
    rfile = open(mlir_file, 'r')
    mllib_conv_type = []
    for line in rfile:
        try:
            result = re.search('mllib_conv_type = (.*)', line)
            temp = result.group(1)
            mllib_conv_type.append(int(temp[0]))
        except:
            continue
    return mllib_conv_type

def get_conv_type(offset, wts_file):
    wts = []
    for i in offset:
        # linecache access line 1 as first so i+1
        line = linecache.getline(wts_file, i+8)
        temp = line.replace('\n', '')
        op = int(temp[6:], 16)
        wts.append(op)
    return wts

def check(x, y, layer, lst):
    if x != y:
        lst.append(layer)
    return lst

def result(parameter, lst, file):
    if len(lst) != 0:
        file.write('"{}" mismatch for following Layers:\n{}\n'.format(parameter, lst))


parser = argparse.ArgumentParser()
parser.add_argument(
    '--wts',
    default="wts32.txt",
    help='path to the wts file')

parser.add_argument(
    '--tiling',
    default="tiling.h",
    help='path to the tiling file')
    
parser.add_argument(
    '--mlo',
    default="multi_layer_overlay.h",
    help='path to the multi layer overlay file')

parser.add_argument(
    '--mlir',
    default="dse.subgraph.mlir",
    help='path to the linalg.mlir file')
parser.add_argument(
    '--diff',
    default="None",
    help='layer1,layer2 to be checked for similarity')

args, _ = parser.parse_known_args()
wts_file = args.wts
tiling_file = args.tiling
mlo_file = args.mlo
mlir_file = args.mlir

ifmsv = 'ifmsv_dim_' 
ofmsv = 'ofmsv_dim_'
fmsv_dim = get_fmsv(ifmsv, ofmsv, tiling_file)

dataOffset = []
offset = get_offset(dataOffset, mlo_file)

weights = []
wts = get_wts(weights, offset, wts_file)

conv_type = get_conv_type(offset, wts_file)
mllib_conv_type = get_mllib_conv_type(mlir_file)
print('Running wts checker...\n')

# checking Layer 1 & Layer 2 for similarity    
layers = args.diff
if layers == 'None':
    ct_mm = []
    iw_mm = []
    ih_mm = []
    id_mm = []
    od_mm = []

    count = len(offset)
    the_file = open('wts_checker.log', 'w+')
    for i in range(count):
        input = fmsv_dim[i][0]
        output = fmsv_dim[i][1]

        ifm_width = input[1]
        ifm_height = input[3]
        ifm_depth = input[0] * input[2]
        ofm_depth = output[0] * output[2]

        temp = wts[i]
        wts_oDepth = int(temp[0:2], 16)
        wts_iDepth = int(temp[2:4], 16)
        wts_iHeight = int(temp[4:6], 16)
        wts_iWidth = int(temp[6:], 16)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        

        iw_mm = check(wts_iWidth, ifm_width, i+1, iw_mm)
        ih_mm = check(wts_iHeight, ifm_height, i+1, ih_mm)
        id_mm = check(wts_iDepth, ifm_depth, i+1, id_mm)
        od_mm = check(wts_oDepth, ofm_depth, i+1, od_mm)

        if conv_type[i] != mllib_conv_type[i]:
            ct_mm.append(i+1)

    if len(ct_mm) + len(id_mm) + len(iw_mm) + len(ih_mm) + len(od_mm) == 0:
        print("All parameters checked sucessfully!!")
        print("No parameter mismatch detected")
    else:
        print('Parameter mismatch detected!!')
        print("Mismatched parameters can be found in wts_checker.log file") 

    for param, xx_mm in zip(['ifm_sv_height', 'ifm_sv_width', 'ifm_sv_depth', 'ofm_sv_depth', 'mllib_conv_type'], [ih_mm, iw_mm, id_mm, od_mm, ct_mm]):
        result(param, xx_mm, the_file)

    the_file.close()

else:
    arg_parts = layers.split(',')
    lyr1 = int(arg_parts[0])
    lyr2 = int(arg_parts[1])
    l1_offset = offset[lyr1 - 1]
    l2_offset = offset[lyr2 - 1]
    l1_wts = get_layer_wts(l1_offset, wts_file)
    l2_wts = get_layer_wts(l2_offset, wts_file)
    l1_int_wts = convert_wts(l1_wts)
    l2_int_wts = convert_wts(l2_wts)
    mismatch = [i for i in range(len(l1_int_wts)) if l1_int_wts[i] != l2_int_wts[i]]
    if len(mismatch) == 0:
        print('The parameters for both the layers {} & {} matches perfectly'.format(lyr1, lyr2))
    else:
        filename = str(lyr1) + '_wts_diff_' + str(lyr2) + '.log'
        print('Mismatch in the parameters for layer {} & {}'.format(lyr1, lyr2))
        print('Mismatched parameters can be found in the {} file.'.format(filename))
        file = open(filename, 'w+')
        for i in mismatch:
            if i<=31:
                conv_mapping_lst = ['ifm_sv_width', 'ifm_sv_height', 'ifm_sv_depth ', 'ofm_sv_depth', 'ksize', 'stride_bits', 'shift_out', 'out_mode', 'shift_bias_init', 'shift_psum_in', 'shift_psum', 'psum_buff_offset', 'alpha', 'alpha', 'shift_lrelu_alpha','shift_lrelu_input', 'shift_lrelu_out', 'num_ofm_depth_iters', 'num_ifm_depth_iters', 'op_type', 'ofm_len', 'ofm_len', 'num_height_iter', 'num_width_iter', 'ifm_len', 'ifm_len', 'ofm_width_pad', 'act', 'conv_type', 'zero_ifm2 | row_offset', 'ifm_sign | ifm2_sign', 'ofm_offset_packed']
                file.write('Byte {} mismatch i.e. "{}" : Conv2D\n'.format(i, conv_mapping_lst[i]))
                file.write('Layer {} : {}\n'.format(lyr1, l1_int_wts[i]))
                file.write('Layer {} : {}\n\n'.format(lyr2, l2_int_wts[i]))
            elif 31<i<=53:
                j = i-32
                MPxPad_lst = ['ifm_sv_width', 'ifm_sv_height', 'ifm_sv_depth ', 'Reserved', 'ksize', 'stride_bits', 'padding_sv_width', 'padding_sv_height', 'cool_pad_mask', 'enable_padding', 'pad_val', 'pad_top', 'pad_bot', 'pad_left', 'pad_right', 'pad_mask_l', 'pad_mask_r', 'manual_ba_pad_val', 'wts_sv_len', 'wts_sv_len', 'ofm_len', 'ofm_len']
                file.write('Byte {} mismatch i.e. "{}" : MaxPool2D + Padding kernel\n'.format(i, MPxPad_lst[j]))
                file.write('Layer {} : {}\n'.format(lyr1, l1_int_wts[i]))
                file.write('Layer {} : {}\n\n'.format(lyr2, l2_int_wts[i]))
            elif 53<i<=63:
                j = i-54
                GAP_lst = ['ifm_sv_width', 'ifm_sv_width_eff', 'ifm_sv_height', 'ifm_sv_depth ', 'div_factor', 'div_factor', 'out_shift', 'shift_in_EW2', 'Reserved', 'exec_type']
                file.write('Byte {} mismatch i.e. "{}" : Globalavgpool2D\n'.format(i, GAP_lst[j]))
                file.write('Layer {} : {}\n'.format(lyr1, l1_int_wts[i]))
                file.write('Layer {} : {}\n\n'.format(lyr2, l2_int_wts[i]))
            else:
                file.write('Byte {} mismatch i.e. "Bias values for output channels" : Conv2D/BatchNorm\n'.format(i))
                file.write('Layer {} : {}\n'.format(lyr1, l1_int_wts[i]))
                file.write('Layer {} : {}\n\n'.format(lyr2, l2_int_wts[i]))


