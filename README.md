# Low-Cost 2D LiDAR using TOF Sensor

## Overview
This project involves designing and implementing a low-cost 2D LiDAR system capable of:

- Accurate detection and mapping of 2D surroundings.
- Real-time visualization of the mapped data.
- Optional integration with ROS2 for visualization in Rviz2.

The system uses an Arduino nano microcontroller, a Time-of-Flight (ToF) sensor, and a stepper motor to create a functional LiDAR solution. This README serves as a guide for understanding the project and replicating the setup.

## Components

### 1. Hardware Components
- *Arduino nano Microcontroller*: For processing sensor data and controlling the motor.
- *ToF Sensor (e.g., VL53L0X)*: Measures distances in real-time.
- *Stepper Motor*: Enables rotational scanning of the environment.
- *Motor Driver (e.g., ULN2003 or A4988)*: Drives the stepper motor.
- *Power Supply*: 5V for the motor and microcontroller.
- Additional components:
  - Connecting wires, breadboard.

### 2. Software Requirements
- **Arduino IDE**: For programming the Arduino.
- **Python**: For real-time plotting and visualization using libraries such as Matplotlib or PyQt.

## Features

1. *2D Mapping*:
   - The ToF sensor measures distances at different angles as the stepper motor rotates.
   - Data is processed to generate a real-time 2D map.

2. *Visualization*:
   - A Python-based GUI displays the mapped data in real-time.

3. *Dynamic Calibration*:
   - Adjusts sensor parameters to improve accuracy under varying ambient conditions.

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

## Challenges and Solutions

### Challenge: Limited accuracy of low-cost ToF sensors.
*Solution*: Implement software-based error compensation and calibration routines.

### Challenge: Mechanical instability of the rotating platform.
*Solution*: Use a balanced setup and ensure proper alignment of the motor and sensor.

### Challenge: Real-time visualization latency.
*Solution*: Optimize data processing and communication protocols.

## Future Work

1. Improve dynamic calibration under extreme environmental conditions.
2. Explore higher-resolution ToF sensors for better accuracy.
3. Enhance the visualization interface with additional features.
