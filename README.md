# Low-Cost 2D LiDAR System

## Overview
This project involves designing and implementing a low-cost 2D LiDAR system capable of:

- Accurate detection and mapping of 2D surroundings.
- Real-time visualization of the mapped data.
- Optional integration with ROS2 for visualization in Rviz2.

The system uses an Arduino nano microcontroller, a Time-of-Flight (ToF) sensor, and a stepper motor to create a functional LiDAR solution. This README serves as a guide for understanding the project and replicating the setup.

---

## Components

### 1. Hardware Components
- *Arduino nano Microcontroller*: For processing sensor data and controlling the motor.
- *ToF Sensor (e.g., VL53L0X)*: Measures distances in real-time.
- *Stepper Motor*: Enables rotational scanning of the environment.
- *Motor Driver (e.g., ULN2003 or A4988)*: Drives the stepper motor.
- *Power Supply*: 5V for the motor and microcontroller.
- Additional components:
  - USB breakout board.
  - Pull-up resistors for I2C communication.
  - Connecting wires, breadboard, or PCB.

### 2. Software Requirements
- *Arduino IDE*: For programming the Arduino.
- **Python **: For real-time plotting and visualization using libraries such as Matplotlib or PyQt.
- **ROS2 and Rviz2 **: For advanced visualization.

---

## Features

1. *2D Mapping*:
   - The ToF sensor measures distances at different angles as the stepper motor rotates.
   - Data is processed to generate a real-time 2D map.

2. *Visualization*:
   - A Python-based GUI displays the mapped data in real-time.
   - Option to interface with ROS2 for advanced 3D visualization.

3. *Dynamic Calibration*:
   - Adjusts sensor parameters to improve accuracy under varying ambient conditions.

---

## System Architecture

1. *Data Acquisition*:
   - The ToF sensor measures distances as the stepper motor rotates.
   - Angular data is synchronized with the distance readings.

2. *Data Processing*:
   - Arduino converts distance and angle into Cartesian coordinates.
   - Noise filtering algorithms (e.g., Kalman filter) enhance accuracy.

3. *Visualization*:
   - Python-based real-time plotting.
   - ROS2 integration for advanced visualization.

---

## Circuit Diagram

### Key Connections:
1. *Arduino*:
   - SDA: GPIO21
   - SCL: GPIO22
2. *ToF Sensor*:
   - VCC: 3.3V
   - GND: GND
3. *Stepper Motor Driver*:
   - Connect IN1-IN4 to Arduino GPIO pins.
   - Connect motor wires to OUT1-OUT4.
4. *Power*:
   - Use USB breakout board for external 5V supply if needed.


---

## Pseudo Code
python
initialize ToF sensor and stepper motor
set rotation speed and scanning resolution

while scanning:
    for each angle in range(0, 360, resolution):
        measure distance using ToF sensor
        record (angle, distance)
    filter data to remove noise
    convert (angle, distance) to Cartesian coordinates
    update real-time plot


---

## Challenges and Solutions

### Challenge: Limited accuracy of low-cost ToF sensors.
*Solution*: Implement software-based error compensation and calibration routines.

### Challenge: Mechanical instability of the rotating platform.
*Solution*: Use a balanced setup and ensure proper alignment of the motor and sensor.

### Challenge: Real-time visualization latency.
*Solution*: Optimize data processing and communication protocols (e.g., ESP-NOW).

---

## Evaluation Metrics

1. *Accuracy*: Distance measurement precision 
2. *Efficiency*: Real-time processing capability.
3. *Durability*: Robust physical design.
4. *User Interface*: Intuitive and interactive plotting tool.


## Future Work

1. Improve dynamic calibration under extreme environmental conditions.
2. Explore higher-resolution ToF sensors for better accuracy.
3. Enhance the visualization interface with additional features.
