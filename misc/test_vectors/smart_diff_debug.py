#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
FlexML backend driver
"""

import argparse
import json
import logging
import os
import re

# logger = logging.getLogger(__name__)
# c_handler = logging.StreamHandler()
# c_handler.setLevel(logging.DEBUG)
# c_format = logging.Formatter("%(levelname)s - %(message)s")
# c_handler.setFormatter(c_format)
# f_handler = logging.FileHandler("./smart_diff.log", mode="w")
# logger.addHandler(c_handler)
# logger.addHandler(f_handler)
# logger.setLevel(logging.WARNING)


logging.basicConfig(filename="./smart_diff.log",
                    format='%(levelname)s - %(message)s',
                    filemode='w')

logger = logging.getLogger()

logger.setLevel(logging.DEBUG)


def sorted_alphanumeric(data):
    convert = lambda text: int(text) if text.isdigit() else text.lower()
    alphanum_key = lambda key: [ convert(c) for c in re.split('([0-9]+)', key) ] 
    return sorted(data, key=alphanum_key)


def main():
    # flexml_source = os.environ['FLEXML_SOURCE']
    # flexml_home = os.environ['FLEXML_HOME']
    parser = argparse.ArgumentParser(
        description="Compares OFM output against a reference taking discriminating padding/garbage data"
    )
    parser.add_argument(
        "--layers_folder",
        help="Folder which contains all layers",
        # required=True,
    )
    parser.add_argument(
        "--tensor_dims_folder",
        help="Folder which conatains all the tensor_dims json files",
        # required=True,
    )
    # parser.add_argument(
    #     "--tensor_dims_json",
    #     help="Tensor dimensions JSON file",
    #     default="./../../../../test/integration/inputs/tensor_dims.json",
    #     # required=True,
    # )
    # parser.add_argument(
    #     "--log_level",
    #     help="Logging level: E - errors, W - warnings",
    #     default="W",
    #     # required=True,
    # )

    args = parser.parse_args()

    # if args.log_level == "E":
    #     logger.setLevel(logging.ERROR)
    # elif args.log_level == "W":
    #     logger.setLevel(logging.WARNING)
    # else:
    #     logger.setLevel(logging.DEBUG)

    # # pdb.set_trace()

    files = [f for f in sorted_alphanumeric(os.listdir(args.layers_folder+'/')) if re.match(r'[0-9]+_data_Conv_[0-9]+_/*', f)]
    tensor_dim_allfiles = [f for f in sorted_alphanumeric(os.listdir(args.tensor_dims_folder+'/')) if re.match(r'[0-9]+_tensor_dims/*', f)]
    # print(len(tensor_dims))
    # print(tensor_dim_allfiles)

    for i in range(len(files)-1):

        ifm_file = args.layers_folder+'/'+files[i+1]+"/ifm32.txt"
        ofm_ref = args.layers_folder+'/'+files[i]+"/ofm32_ref.txt"
        tensor_dim_file = args.tensor_dims_folder+'/'+tensor_dim_allfiles[i]
        # print(tensor_dim_file)
        # print(ifm_file, ofm_ref, tensor_dim_file)

        with open(tensor_dim_file, "r", encoding="utf8") as f:
            tensor_dims = json.load(f)

        with open(ofm_ref, "r") as ofm_ref:
            ref_lines = ofm_ref.readlines()

        with open(ifm_file, "r") as ofm_file:
            ofm_lines = ofm_file.readlines()

        # pdb.set_trace()

        ofm_dim_h = tensor_dims["ofm_dim_h"]
        ofm_dim_w = tensor_dims["ofm_dim_w"]
        ofm_dim_d = tensor_dims["ofm_dim_d"]
        ofm_bound_h = tensor_dims["ofm_bound_h"]
        ofm_bound_w = tensor_dims["ofm_bound_w"]
        ofm_bound_d = tensor_dims["ofm_bound_d"]
        msg_str = ""
        c_pack = 8
        bytes_per_line = 4
        flag = 0

        if len(ofm_lines) != len(ref_lines):
            msg_str = (
                "OFM number of lines "
                + str(len(ofm_lines))
                + " is not equal to Ref number of lines "
                + str(len(ref_lines))
            )
            logger.warning(msg_str)
            flag = 1

        expected_lines = int((ofm_dim_h * ofm_dim_w * ofm_dim_d) / bytes_per_line)
        if len(ofm_lines) != expected_lines:
            msg_str = (
                "OFM file number of lines "
                + str(len(ofm_lines))
                + " does not match expected number "
                + str(expected_lines)
            )
            logger.warning(msg_str)
            flag = 1

        if len(ref_lines) != expected_lines:
            msg_str = (
                "Ref file number of lines "
                + str(len(ref_lines))
                + " does not match expected number "
                + str(expected_lines)
            )
            logger.warning(msg_str)
            flag = 1

        # pdb.set_trace()

        lines_compared = 0
        error_cnt = 0

        for h in range(ofm_dim_h):
            for cout in range(0, ofm_dim_d, c_pack):
                for w in range(ofm_dim_w):
                    for cout_line in range(0, int(c_pack / bytes_per_line)):
                        line_idx = int(
                            (h * (ofm_dim_d / c_pack) * ofm_dim_w * 2)
                            + int((cout / c_pack) * ofm_dim_w * 2)
                            + w * 2
                            + cout_line
                        )
                        # pdb.set_trace()
                        if line_idx >= len(ref_lines) or line_idx >= len(ofm_lines):
                            break
                        if int(ofm_lines[line_idx].rstrip(), 16) != int(
                            ref_lines[line_idx].rstrip(), 16
                        ):
                            # pdb.set_trace()
                            msg_str = (
                                "OFM mismatch at line="
                                + str(line_idx + 1)
                                + ", ref="
                                + ref_lines[line_idx].rstrip()
                                + ", ofm="
                                + ofm_lines[line_idx].rstrip()
                                + "; cout= "
                                + str(int(cout + cout_line * bytes_per_line))
                                + ", w= "
                                + str(w)
                                + ", h= "
                                + str(h)
                            )
                            if cout >= ofm_bound_d or w >= ofm_bound_w or h >= ofm_bound_h:
                                logger.warning(msg_str)
                                flag = 1

                            else:
                                error_cnt = error_cnt + 1
                                logger.error(msg_str)
                                flag = 1

                            # print(h,cout,w,cout_line)
                            # pdb.set_trace()
                            # print('Here we are...')

                        # pdb.set_trace()
                        lines_compared = line_idx

                    # pdb.set_trace()
                    if line_idx >= len(ref_lines) or line_idx >= len(ofm_lines):
                        break

                if line_idx >= len(ref_lines) or line_idx >= len(ofm_lines):
                    break

            if line_idx >= len(ref_lines) or line_idx >= len(ofm_lines):
                break

        msg_str = (
            "OFM dims: cout= "
            + str(ofm_dim_d)
            + ", w= "
            + str(ofm_dim_w)
            + ", h="
            + str(ofm_dim_h)
        )
        logger.debug(msg_str)

        msg_str = (
            "OFM bounds: cout= "
            + str(ofm_bound_d)
            + ", w= "
            + str(ofm_bound_w)
            + ", h="
            + str(ofm_bound_h)
        )
        logger.debug(msg_str)

        msg_str = "Expected number of lines: " + str(expected_lines)
        logger.debug(msg_str)

        msg_str = "REF number of lines: " + str(len(ref_lines))
        logger.debug(msg_str)

        msg_str = "OFM number of lines: " + str(len(ofm_lines))
        logger.debug(msg_str)

        msg_str = "Number of lines compared: " + str(lines_compared + 1)
        logger.debug(msg_str)

        msg_str = "Number of lines in error: " + str(error_cnt)
        logger.debug(msg_str)


        if flag == 1:
            msg_str = f"ERROR: found mismatch in layers [{files[i+1]}, {files[i]}, {tensor_dim_allfiles[i]}]\n"
            logger.debug(msg_str+'####################################')
            print(msg_str)
        else:
            msg_str = f"Success: layers [{files[i+1]}, {files[i]}, {tensor_dim_allfiles[i]}]\n ####################################"
            logger.debug(msg_str)

    print('Please check smart_diff.log for detailed information.')


if __name__ == "__main__":
    main()