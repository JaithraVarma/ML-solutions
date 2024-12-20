import pickle
import argparse
import onnxruntime as ort
import numpy as np
import torch
import os


def denormalize_bbox(normalized_bboxes, pc_range):
    # rotation 
    rot_sine = normalized_bboxes[..., 6:7]

    rot_cosine = normalized_bboxes[..., 7:8]
    rot = torch.atan2(rot_sine, rot_cosine)

    # center in the bev
    cx = normalized_bboxes[..., 0:1]
    cy = normalized_bboxes[..., 1:2]
    cz = normalized_bboxes[..., 4:5]
   
    # size
    w = normalized_bboxes[..., 2:3]
    l = normalized_bboxes[..., 3:4]
    h = normalized_bboxes[..., 5:6]

    w = w.exp() 
    l = l.exp() 
    h = h.exp() 
    if normalized_bboxes.size(-1) > 8:
         # velocity 
        vx = normalized_bboxes[:, 8:9]
        vy = normalized_bboxes[:, 9:10]
        denormalized_bboxes = torch.cat([cx, cy, cz, w, l, h, rot, vx, vy], dim=-1)
    else:
        denormalized_bboxes = torch.cat([cx, cy, cz, w, l, h, rot], dim=-1)
    return denormalized_bboxes

def decode_single(cls_scores, bbox_preds):

    num_classes = 10
    max_num = 300
    pc_range = [-51.2, -51.2, -5.0, 51.2, 51.2, 3.0]
    score_threshold = None
    post_center_range =  [-61.2, -61.2, -10.0, 61.2, 61.2, 10.0]

    cls_scores = cls_scores.sigmoid()
    scores, indexs = cls_scores.view(-1).topk(max_num)
    labels = indexs % num_classes
    bbox_index = indexs // num_classes
    bbox_preds = bbox_preds[bbox_index]

    print("*******************decorator******************************")
    #print(num_classes, max_num, pc_range, score_threshold, post_center_range)
       
    final_box_preds = denormalize_bbox(bbox_preds, pc_range) 
    final_scores = scores 
    final_preds = labels 
    
    # use score threshold
    if score_threshold is not None:
        thresh_mask = final_scores > score_threshold
        tmp_score = score_threshold
        while thresh_mask.sum() == 0:
            tmp_score *= 0.9
            if tmp_score < 0.01:
                thresh_mask = final_scores > -1
                break
            thresh_mask = final_scores >= tmp_score

    if post_center_range is not None:
            post_center_range = torch.tensor(
                post_center_range, device=scores.device)
            mask = (final_box_preds[..., :3] >=
                    post_center_range[:3]).all(1)
            mask &= (final_box_preds[..., :3] <=
                     post_center_range[3:]).all(1)

            if score_threshold:
                mask &= thresh_mask

            boxes3d = final_box_preds[mask]
            scores = final_scores[mask]

            labels = final_preds[mask]
            predictions_dict = {
                'bboxes': boxes3d,
                'scores': scores,
                'labels': labels
            }
    return predictions_dict

def bbox3d2result(scores, labels, attrs=None):
    result_dict = dict(
        scores_3d=scores.cpu(),
        labels_3d=labels.cpu())

    if attrs is not None:
        result_dict['attrs_3d'] = attrs.cpu()

    return result_dict


def run_everything(output):
    outs = {}
    outs['bev_embed'] = output[0]
    outs['all_cls_scores'] = output[1]
    outs['all_bbox_preds'] = output[2]

    all_cls_scores = outs['all_cls_scores'][-1]
    all_bbox_preds = outs['all_bbox_preds'][-1]
    import numpy
    if isinstance(all_cls_scores, numpy.ndarray):
 
        all_cls_scores=torch.from_numpy(all_cls_scores)
        all_bbox_preds=torch.from_numpy(all_bbox_preds)


    batch_size = all_cls_scores.size()[0]
    predictions_list = []
    for i in range(batch_size):
        predictions_list.append(decode_single(all_cls_scores[i], all_bbox_preds[i]))
    preds_dicts = predictions_list
    num_samples = len(preds_dicts)

    ret_list = []
    for i in range(num_samples):
        preds = preds_dicts[i]
        bboxes = preds['bboxes']

        bboxes[:, 2] = bboxes[:, 2] - bboxes[:, 5] * 0.5

        code_size = bboxes.shape[-1]
        #bboxes = img_metas[i][0]['box_type_3d'](bboxes, code_size) #ONNX
        #bboxes = img_metas[i]['box_type_3d'](bboxes, code_size)     #Torch
        scores = preds['scores']
        labels = preds['labels']

        ret_list.append([scores, labels])

    bbox_results = [
            bbox3d2result(scores, labels)
            for scores, labels in ret_list]
 
    return bbox_results, bboxes

#use for loop here for all pkl  : Santhosh 

def list_files_by_creation_date(directory):
    files = os.listdir(directory)
    
    files.sort(key=lambda x: os.path.getctime(os.path.join(directory, x)))
    
    file_list=[]
    for file in files:
        print(f"{file} - {os.path.getctime(os.path.join(directory, file))}")
        file_list.append(os.path.join(directory, file))

    return file_list


def main(data,onnx):
    prev_bev=np.random.rand(2500, 1, 256).astype(np.float32)

    directory_path = data
    file_list=list_files_by_creation_date(directory_path)

    for fl in file_list:
        
        if "input" not in fl:
            continue

        with open(fl, 'rb') as file:
            data = pickle.load(file)

        data['prev_bev']=prev_bev
        session = ort.InferenceSession(onnx)
        outputs = session.run(None, data)
        #convert_onnx2pyt(outputs, img_metas)

        post_processed_results, bounding_boxes=run_everything(outputs)
        print('scores_3d: ', post_processed_results[0]['scores_3d'].shape)
        print('labels_3d: ', post_processed_results[0]['labels_3d'].shape)
        print('bounding_boxes: ',bounding_boxes.shape)

        print("bev_embed shape ",  outputs[0].shape)
        print("output_classes shape ",  outputs[1].shape)
        print("output_coords shape ",  outputs[2].shape)
        prev_bev=outputs[0]

        
if __name__== "__main__":
    parser = argparse.ArgumentParser(description="bevformer onnx infer")
    parser.add_argument('data', type=str, help='sample input to onnx in pkl format')
    parser.add_argument('onnx', type=str, help='onnx file path')
    args = parser.parse_args()
    main(args.data,args.onnx)
    
# example usage
#python bevformer_infer.py  "/wrk/ai_regr/santosh/workspace/scripts/bevformer_eval/files/samples/"  '/proj/ai_models/vision/VIT_MODELS/simplified/bevformer_tiny_epoch_24_v8_simplify.onnx'