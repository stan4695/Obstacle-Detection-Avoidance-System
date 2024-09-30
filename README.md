# Obstacle-Detection-Avoidance-System

This project is a university-level initiative aimed at designing and implementing a collision avoidance system using a Intel Galileo Gen 2 microcontroller and any other components on our choice (transistors, resistors, capacitors, diodes, proximity or ultrasonic sensors, car chassis with motors etc.). The system is capable of detecting obstacles in its path and change direction to avoid them.

## Table of Contents
- [Project Overview](#project-overview)
- [System Components](#system-components)
- [Implementation](#implementation)
- [How It Works](#how-it-works)
- [Installation and Setup](#installation-and-setup)
- [Contributors](#contributors)

## Project Overview
The goal of the project was to create a device capable of navigating through an environment with obstacles while avoiding collisions as efficiently as possible. This was achieved using ultrasonic sensors to detect obstacles and adjust the movement of the motors accordingly.

This system could be integrated into autonomous robots, cars, or drones for obstacle detection and avoidance in real-world environments.

## System Components
- **Intel Galileo Gen 2 Board**: The brain of the system, used to control sensors and motors.
- **Ultrasonic Sensors (HC-SR04)**: Used to measure the distance between the system and obstacles.
- **Car Chassis with DC Motors**: Controlled by the Intel Galileo Gen 2 to adjust the movement of the robot.
- **NPN Transistor**: Used as a switch to control the motors.
- **Capacitors and Diodes**: To filter noise and protect components.
- **9V Battery**: To power Arduino system.

## Implementation
The system works using three ultrasonic sensors positioned on the front and sides of the robot. The sensors constantly measure the distance to nearby objects. If an obstacle is detected within a predefined range, the system adjusts the speed of the motors in order to change direction and avoid the collision.

### Functional Diagram
![Block Diagram](https://github.com/user-attachments/assets/5ff9a322-4f6d-4906-a0e2-b61d6ffe337e)

### Electrical Schematic
![Electrical Schematic](https://github.com/user-attachments/assets/f5588e00-5b60-475f-9aa3-a696f3e11562)


## How It Works
1. **Obstacle Detection**: 
    - Each sensor emits ultrasonic waves and calculates the time taken for the waves to bounce back from an obstacle. 
    - The distance is then computed based on the speed of sound.

2. **Movement Control**:
    - If an obstacle is detected, the Intel Galileo Board adjusts the speed of one motor using the switch function of NPN transistors to turn the robot in a direction away from the obstacle. 
    - If all sensors detect obstacles, the system performs a 180° turn.

## Installation and Setup
### Prerequisites:
- Arduino IDE
- Basic knowledge of Arduino programming
- Necessary hardware components

### Steps:
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/collision-avoidance-system.git
   ```
2. Upload the Arduino sketch to your Arduino board.
3. Connect the components following the electrical schematic provided in the documentation.
4. Run the system and observe how it detects and avoids obstacles.

## Contributors
- Mihnea-Andrei Ciungu
- Oana-Andreea Teculescu

Supervisor:
- Mihai Muntean, Universitatea Politehnica București
