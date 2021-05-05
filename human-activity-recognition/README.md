### Human Activity Recognition

Inference for Human Activity Recogniotion ML model. It recognizes the kind of human activity (walking, running, stationary) based on data 
from a 3-axis accelerometer

- #parameters: 12,075
- Complexity: 24,120 MACC
- Flash occupation (without quantization): 47.17 KB
- RAM (without quantization): 1.88 KB

```
Layer (type)                 Output Shape              Param #   
=================================================================
conv1d_35 (Conv1D)           (None, 24, 16)            160       
_________________________________________________________________
conv1d_36 (Conv1D)           (None, 22, 8)             392       
_________________________________________________________________
dropout_19 (Dropout)         (None, 22, 8)             0         
_________________________________________________________________
flatten_20 (Flatten)         (None, 176)               0         
_________________________________________________________________
dense_40 (Dense)             (None, 64)                11328     
_________________________________________________________________
dense_41 (Dense)             (None, 3)                 195       
=================================================================
Total params: 12,075
Trainable params: 12,075
Non-trainable params: 0
```

<p align="center">
  <img src="/human-activity-recognition/human_activity_recognition_graph.png" />
</p>
