<p align="center">
  <img src="/img/mcu_header.jpg" />
</p>

# Edge AI - performance
I couldn’t find much information about the performance of edge AI inference on microcontrollers, so I decided to conduct the tests myself.

I tested different ML models (from simple NN, to complex CNN) on various Cortex-M microcontrollers. If someone is considering implementing ML inference on MCU, then this document should give an idea if performance-wise it will be feasible and what kind of MCU would be required.

### testing method
Tests were performed on Cortex-M4 @48 MHz, Cortex-M4 @64 MHz, Cortex-M7 @180 MHz and Cortex-M7 @550MHz. I used Cube.AI to deploy ML models on microcontrollers. Inference was the only thing running on the MCU, there were no other tasks. Inference duration was measured with the use of timer. For every model, inference was executed 3 times and duration of all 3 inferences was measured and then the average was calculated. This also allowed to reduce the impact of clock cycles used for reading from the timer. 

I did not perform pruning nor quantization (except Image Classification task), so performance and size of the models still can be improved. Image Classification model was too big to fit on the Flash, so I did quantization in this case.

The models have following parameters:
- Simple regression model, to predict house price based on its attributes ([more details](https://github.com/Piorkos/tinyML-performance/tree/main/house-price-prediction)).
  - #parameters: 6,534
  - MACC: 6,771
- Human Activity Recognition. It recognizes the kind of human activity (walking, running, stationary) based on data from a 3-axis accelerometer ([more details](https://github.com/Piorkos/tinyML-performance/tree/main/human-activity-recognition)).
  - #parameters: 12,075
  - MACC: 24,120
- Image Classification. Complex Convolutional Neural Network, trained on Fashion MNIST dataset. Model was too big to fit into Flash, so I did quantization. ([more details](https://github.com/Piorkos/tinyML-performance/tree/main/image-classification)).
  - #parameters: 412, 778
  - MACC: 2,323,968

### results
Results of the tests are listed below. First table presents inference latency. The second table shows the same, but in different form, it indicates how many inferences could be executed per second. Please keep in mind that no other tasks were running on the MCU, not even collecting nor processing input data.

|  ML model | Cortex-M4 48MHz | Cortex-M4 64MHz | Cortex-M7 180MHz | Cortex-M7 550MHz
----------- | ---------------- | ---------------- | ----------------- | -----------------
predict house price | 1.35 ms | 1.08 ms | 0.20 ms | 0.06 ms |
human activity recognition | 6.7 ms | 5.2 ms  | 1.01 ms | 0.34 ms |
image classification | 547 ms | 423 ms  | 82.4 ms | 27.0 ms |


| ML model  | Cortex-M4 48MHz | Cortex-M4 64MHz | Cortex-M7 180MHz | Cortex-M7 550MHz
----------- | ---------------- | ---------------- | ----------------- | -----------------
predict house price | 740 Hz | 926 Hz | 5,000 Hz | 16,700 Hz |
human activity recognition | 149 Hz | 192 Hz | 990 Hz | 2,941 Hz |
image classification | 1.8 Hz | 2.3 Hz | 12 Hz | 37 Hz |

###
Memory occupied by the models on MCU is as follows:
|           | predict house price | human activity regocnition  | image classification
----------- | ---------------- | ---------------- | -----------------
FLASH | 25.52 KB | 47.17 KB | 240.48 KB
RAM | 0.384 KB  | 1.88 KB | 66.10 KB

##
### conclusion
To be honest, I've been surprised how good the performance is. There are many, many cases in which Machine Learning can be implemented on MCU and provide satisfying performance.

However the issue is with the memory. Complex models won't fit on the small size of Flash or RAM. Of course there are techniques which can help (like quantization or pruning) and they will help in many cases but not always. First I wanted to use MobileNet for image classification, but even after quantization it was too big to fit on the memory.

