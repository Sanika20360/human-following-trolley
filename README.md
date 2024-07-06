# Intelligent Path Companion Trolley

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Setup and Installation](#setup-and-installation)
- [Usage](#usage)
- [Code Explanation](#code-explanation)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The **Intelligent Path Companion Trolley** is a smart trolley designed to autonomously follow a path using IR sensors. It is equipped with a load cell for weight measurement, an LCD for displaying information, and a motor control system to navigate based on sensor inputs. This project aims to create a robotic trolley that can independently follow a path and carry objects.

## Features

- **Autonomous Navigation:** Uses IR sensors to detect and follow a path.
- **Weight Measurement:** Equipped with an HX711 load cell to measure the weight of objects placed on it.
- **LCD Display:** Shows the current weight and status of the trolley.
- **Obstacle Detection:** Uses an ultrasonic sensor to avoid collisions.

## Components

- Arduino UNO
- HX711 Load Cell Amplifier
- Load Cell (5Kg)
- LiquidCrystal I2C Display (16x2)
- L293D Motor Driver
- DC Motors
- HC-SR04 Ultrasonic Sensor
- IR Sensors
- Jumper Wires
- Breadboard
- Power Supply

## Circuit Diagram

![Circuit Diagram](path/to/your/circuit_diagram.jpg) <!-- Replace with actual circuit diagram image -->

## Setup and Installation

1. **Wiring:**
    - Connect the HX711 load cell according to the [HX711 datasheet](https://www.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf).
    - Connect the IR sensors to the digital pins of the Arduino.
    - Connect the motors to the L293D motor driver.
    - Connect the ultrasonic sensor to the Arduino.
    - Connect the LCD display using I2C protocol.

2. **Arduino IDE Setup:**
    - Install the Arduino IDE from the [official website](https://www.arduino.cc/en/software).
    - Install the necessary libraries:
        ```bash
        Sketch -> Include Library -> Manage Libraries
        ```
        Search for and install:
        - **HX711**
        - **LiquidCrystal I2C**

3. **Upload Code:**
    - Open the provided `trolley.ino` file in the Arduino IDE.
    - Select the correct board and COM port.
    - Upload the code to the Arduino.

## Usage

1. **Power the Trolley:**
    - Connect the power supply to the Arduino and motor driver.

2. **Place the Trolley on the Path:**
    - Ensure the IR sensors are positioned over the path to detect lines.

3. **Start the Trolley:**
    - The trolley will begin moving forward by default and will change direction based on the path detected by the IR sensors.

4. **Monitor Weight and Status:**
    - The LCD will display the current weight of the object placed on the trolley and its status.

## Code Explanation

The main code for the project is `trolley.ino`. Below is a brief explanation of the code structure:

- **Libraries:**
    ```cpp
    #include <Wire.h>
    #include <LiquidCrystal_I2C.h>
    #include "HX711.h"
    ```

- **Pin Definitions:**
    ```cpp
    const int LOADCELL_DOUT_PIN = 2;
    const int LOADCELL_SCK_PIN = 3;
    const int trigPin = 11;
    const int echoPin = 12;
    const int motorA1 = 7;
    const int motorA2 = 6;
    const int motorAspeed = 8;
    const int motorB1 = 5;
    const int motorB2 = 4;
    const int motorBspeed = 13;
    const int left_sensor_pin = 10;
    const int right_sensor_pin = 9;
    ```

- **Setup Function:**
    ```cpp
    void setup() {
      // Initialize LCD and sensors
      // Set up pins for motor control
      // Display initial messages on LCD
      moveForward(); // Start moving forward
    }
    ```

- **Main Loop:**
    ```cpp
    void loop() {
      // Read sensor values
      // Measure distance using ultrasonic sensor
      // Adjust motor direction based on sensor input
    }
    ```

- **Movement Functions:**
    ```cpp
    void moveForward() {
      // Code to move the trolley forward
    }

    void turnRight() {
      // Code to turn the trolley right
    }

    void turnLeft() {
      // Code to turn the trolley left
    }

    void stop() {
      // Code to stop the trolley
    }
    ```

## Contributing

Contributions are welcome! If you have any ideas for improvements or new features, please submit a pull request or open an issue.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

### How to Use This Template

1. **Fork the Repository:**
   Click the "Fork" button at the top right of this repository to create a copy of this repo on your GitHub account.

2. **Clone the Repository:**
   ```bash
   git clone https://github.com/yourusername/intelligent-path-companion-trolley.git
   cd intelligent-path-companion-trolley
