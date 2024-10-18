# arduino-based-distance-measuring-system
 This Arduino project controls a servo motor based on distance measured by an HC-SR04 ultrasonic sensor, adjusting to four angles for different proximity ranges. It updates only when significant distance changes are detected.
Ultrasonic Sensor Controlled Servo Motor Project
By Sandeep Yadav
Project Overview
This project uses an HC-SR04 ultrasonic sensor to measure the distance to an object and controls a servo motor based on the measured distance. The servo motor adjusts its position based on proximity, responding to objects within a range of 0 to 50 cm. This project is suitable for applications such as robotics or automated systems that require real-time adjustments based on object detection.

Components
Arduino Uno (or compatible board)
HC-SR04 Ultrasonic Sensor
Servo Motor (SG90 or similar)
Jumper Wires
Breadboard (optional)
External 5V Power Supply (optional for powering the servo motor)
Circuit Connections
1. HC-SR04 Ultrasonic Sensor:
VCC pin → 5V on Arduino
GND pin → GND on Arduino
Trigger pin → Digital Pin 2 on Arduino
Echo pin → Digital Pin 3 on Arduino
2. Servo Motor:
Signal (yellow) wire → Digital Pin 6 on Arduino
VCC (red) wire → 5V on Arduino or external power supply (if using)
GND (black) wire → GND on Arduino or external power supply (common ground with Arduino)
Note:
If the servo motor does not get enough power from the Arduino, an external 5V power source is recommended.

Code Explanation
The code uses two main components:

HC-SR04 Ultrasonic Sensor: Measures distance using sound waves by sending a trigger pulse and calculating the time it takes for the echo to return. This time is then converted into distance (in cm).
Servo Motor: Based on the measured distance, the servo motor adjusts its angle to four predefined levels (45°, 90°, 135°, 180°).
Servo Motor Levels:
Level 1: Angle 45° for objects at 0–10 cm.
Level 2: Angle 90° for objects at 11–20 cm.
Level 3: Angle 135° for objects at 21–30 cm.
Level 4: Angle 180° for objects at 31–50 cm.
Key Code Features:
Distance Measurement: The ping_cm() function from the NewPing library measures the distance in centimeters.
Significant Change Detection: The code checks if the distance has changed by more than 3 cm before updating the servo motor, preventing unnecessary movements.
Delay: A 1-second delay is added between each sensor reading to avoid rapid updates and movements.
How the Project Works:
The ultrasonic sensor sends out a sound wave (trigger pulse) and waits for the echo to return. The time it takes for the echo to return is used to calculate the distance to the object.
The servo motor adjusts its position based on the measured distance, divided into four levels, with each level corresponding to a different range of distances.
Significant change detection ensures that the motor only adjusts when the distance changes by at least 3 cm, preventing excessive movements.
Serial output: The distance and servo angle are printed to the serial monitor for easy debugging and observation.
Conclusion:
This project provides an effective way to control servo motors based on proximity detection. It can be further extended for more complex robotic systems or automation tasks. The significant distance change detection mechanism prevents excessive movements and ensures the motor operates smoothly and efficiently.

