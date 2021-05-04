# tinyML-performance
I couldn’t find much information about the performance of Machine Learning inference on microcontrollers, so I decided to do the tests by myself.
I tested different ML models (from simple NN, to complex CNN) on various Cortex-M microcontrollers. If someone is considering implementing ML inference on MCU, then this document should give an idea if performance-wise it will be feasible and what kind of MCU should be used.

## ML models
I used 3 different ML models and deployed them to MCU using Cube.AI. The models have following parameters:
- Simple regression model, to predict house price based on its attributes.
  - #parameters: 6,534
  - MACC: 6,771
  - types of layers: Dense
- Human Activity Recognition. It recognizes the kind of human activity (walking, running, stationary) based on data from a 3-axis accelerometer.
  - #parameters: 12,075
  - MACC: 24,120
  - types of layers: Conv1D, Flattern, Dense
- Image Classification. Complex Convolutional Neural Network, trained on Fashion MNIST dataset.
  - #parameters: 412, 778
  - MACC: 2,323,968
  - types of layers: Conv2D, MaxPooling2D, Flatten, Dense


## Results
Below table presents time needed for inference:
|  ML model | Cortex-M4 48 MHz | Cortex-M4 64 MHz | Cortex-M7 180 MHz | Cortex-M7 180 MHz
----------- | ---------------- | ---------------- | ----------------- | -----------------
predict house price | 1.35 ms | 1.08 ms | 0.20 ms | 0.06 ms |
human activity recognition | 6.7 ms | 5.2 ms  | 1.01 ms | 0.34 ms |
image classification | 547 ms | 423 ms  | 82.4 ms | 27.0 ms |

Below table shows how many inferences can be executed per second:
| ML model  | Cortex-M4 48 MHz | Cortex-M4 64 MHz | Cortex-M7 180 MHz | Cortex-M7 180 MHz
----------- | ---------------- | ---------------- | ----------------- | -----------------
predict house price | 740 Hz | 926 Hz | 5,000 Hz | 16,700 Hz |
human activity recognition | 149 Hz | 192 Hz | 990 Hz | 2,941 Hz |
image classification | 1.8 Hz | 2.3 Hz | 12 Hz | 37 Hz |
