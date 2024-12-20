data_dir=/host_nithink/VitisAI/download_coco/data
model=deeplabv3_resnet50_ptq.py
model_name=deeplabv3_resnet50
echo "Run float"
python3 $model --dataset coco --model $model_name --data-path $data_dir --test-only --quant_mode float
echo "Run Quantization"
python3 $model --dataset coco --model $model_name --data-path $data_dir --test-only --quant_mode calib 
echo "Run Deploy"
python3 $model --dataset coco --model $model_name --data-path $data_dir --test-only --quant_mode test --deploy 
echo "Run Evaluation on Quant Network"
python3 $model --dataset coco --model $model_name --data-path $data_dir --test-only --quant_mode test

