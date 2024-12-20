import sys
import json
import os
import numpy as np
import onnxruntime as ort
# torchvision is required for onnx to work
import torchvision
import pickle
import argparse



def compare_models(ofm_ref_path,
                   ofm_aie_path):

    bev_embed_mismatch=0
    outputs_classes_mismatch=0
    outputs_coords_mismatch=0
    samples=0
    for itr in range(81):
        samples+=1
        with open(os.path.join(ofm_ref_path,str(itr)+'_output.pkl'), 'rb') as file:
                ofm_ref = pickle.load(file)

        with open(os.path.join(ofm_aie_path,str(itr)+'_output.pkl'), 'rb') as file:
                ofm_aie = pickle.load(file)



        atol_perc = 0.07
        rtol = 0

        bev_embed_aie = ofm_aie[0]
        bev_embed_ref = ofm_ref[0]
        bev_embed_ref_max = np.max(abs(bev_embed_ref))
        bev_embed_atol = bev_embed_ref_max * atol_perc

        outputs_classes_aie = ofm_aie[1]
        outputs_classes_ref = ofm_ref[1]
        outputs_classes_ref_max = np.max(abs(outputs_classes_ref))
        outputs_classes_atol = outputs_classes_ref_max * atol_perc

        outputs_coords_aie = ofm_aie[2]
        outputs_coords_ref = ofm_ref[2]
        outputs_coords_ref_max = np.max(abs(outputs_coords_ref))
        outputs_coords_atol = outputs_coords_ref_max * atol_perc

        print(f'bev_embed max: {bev_embed_ref_max} atol: {bev_embed_atol}')
        print('bev_embed_aie')
        print(bev_embed_aie[0][0][0:15])
        print('bev_embed_ref')
        print(bev_embed_ref[0][0][0:15])

        if np.allclose(bev_embed_aie, bev_embed_ref, rtol=rtol, atol=bev_embed_atol):
            print('INFO: bev_embed_aie matches bev_embed_ref')
        else:
            print('ERROR: bev_embed_aie does NOT match bev_embed_ref')
            bev_embed_mismatch+=1


        if np.allclose(outputs_classes_aie, outputs_classes_ref, rtol=rtol, atol=outputs_classes_atol):
            print('INFO: outputs_classes_aie matches outputs_classes_ref')
        else:
            print('ERROR: outputs_classes_aie does NOT match outputs_classes_ref')
            outputs_classes_mismatch+=1


        if np.allclose(outputs_coords_aie, outputs_coords_ref, rtol=rtol, atol=outputs_coords_atol):
            print('INFO: outputs_coords_aie matches outputs_coords_ref')
        else:
            print('ERROR: outputs_coords_aie does NOT match outputs_coords_ref')
            outputs_coords_mismatch+=1  

    print(" bev_embed mismatch % ",  (bev_embed_mismatch*100/(samples)))
    print(" outputs_classes mismatch % ",  (outputs_classes_mismatch*100/(samples)))
    print(" outputs_coords mismatch % ",  (outputs_coords_mismatch*100/(samples)))

if __name__== "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('ref', type=str, help='onnx ref o/p files dir path')
    parser.add_argument('aie', type=str, help='aie o/p files dir path')
    args = parser.parse_args()
    compare_models(args.ref,args.aie)


#example
##python compare.py  "/wrk/ai_regr/santosh/workspace/scripts/bevfrmr_tiny_pkl_itrd_ipop" "/wrk/ai_regr/santosh/workspace/scripts/bevfrmr_tiny_pkl_itrd_ipop"