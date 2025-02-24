
Repo:

  **Model_Analysis**: scripts related to model analysis 
  
  **Model_evaluation** : Scripts related to model evaluation
  
  **Performance_Analysis**: Scripts related to model performance analysis
  
  **Model_Triaging** : Scripts related to triaging speedup/automation
  
Few points to be remembered to make sure repo light and convenient for cloning:

•	Do not push large files (like ONNX, .pt etc). Please use NFS area /wrk/ai_regr/, /proj/ai_models/ , /proj/ai_datasets etc for larger files purpose. 
•	Do not push any binary files. Keep repo only for human readable scripts/ Readme and few meta files (json).


**Using scription by AIModelTesting/ VAIML regression:**

This repo is getting synced into following NFS area regularly, so if there is any need to use ml_solutions script by VAIML Regression, it can directly be referred from NFS path:
http://fisweb:8080/wrk/ai_regr/ghe_repos/ml_solutions/main/
