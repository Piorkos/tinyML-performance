### Predict House Price

Inference for simple regression model, to predict house price based on its attributes.

- #parameters: 6,534
- Complexity: 6,771 MACC
- Flash occupation (without quantization): 25.52 KB
- RAM (without quantization): 0.384 KB

```
Layer (type)                 Output Shape              Param #   
=================================================================
dense_73 (Dense)             (None, 19)                380       
_________________________________________________________________
dense_74 (Dense)             (None, 19)                380       
_________________________________________________________________
dense_75 (Dense)             (None, 38)                760       
_________________________________________________________________
dense_76 (Dense)             (None, 38)                1482      
_________________________________________________________________
dense_77 (Dense)             (None, 38)                1482      
_________________________________________________________________
dense_78 (Dense)             (None, 19)                741       
_________________________________________________________________
dense_79 (Dense)             (None, 19)                380       
_________________________________________________________________
dense_80 (Dense)             (None, 19)                380       
_________________________________________________________________
dense_81 (Dense)             (None, 19)                380       
_________________________________________________________________
dense_82 (Dense)             (None, 8)                 160       
_________________________________________________________________
dense_83 (Dense)             (None, 1)                 9         
=================================================================
Total params: 6,534
Trainable params: 6,534
Non-trainable params: 0
```

<p align="center">
  <img src="/house-price-prediction/predict_house_price_graph.png" />
</p>
