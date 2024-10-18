#include <Servo.h>
#include <NewPing.h>

// Pin Definitions
const int ServoPin = 6;           // Servo control pin
const int TriggerPin = 2;         // HC-SR04 Trigger pin
const int EchoPin = 3;            // HC-SR04 Echo pin

// Sensor and Servo setup
NewPing sonar(TriggerPin, EchoPin, 400);  // Max distance set to 400 cm
Servo servo;

// Levels for servo movement
const int Level1 = 45;   // Servo angle for level 1
const int Level2 = 90;   // Servo angle for level 2
const int Level3 = 135;  // Servo angle for level 3
const int Level4 = 180;  // Servo angle for level 4

int lastDistance = 0;    // To store the last valid distance
const int changeThreshold = 3;  // Minimum change in distance to update the servo

void setup() {
  Serial.begin(9600);
  servo.attach(ServoPin);  // Attach the servo
}

void loop() {
  // Measure distance
  int distance = sonar.ping_cm();

  // Output the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Only update servo if the distance changes significantly
  if (abs(distance - lastDistance) >= changeThreshold && distance > 0) {
    lastDistance = distance;  // Update the last distance
    
    // Adjust servo position based on the distance
    if (distance <= 10) {
      // Level 1: Close object (0 to 10 cm)
      servo.write(Level1);
      Serial.println("Servo at Level 1 (45 degrees)");
    } 
    else if (distance > 10 && distance <= 20) {
      // Level 2: Medium close (11 to 20 cm)
      servo.write(Level2);
      Serial.println("Servo at Level 2 (90 degrees)");
    } 
    else if (distance > 20 && distance <= 30) {
      // Level 3: Medium far (21 to 30 cm)
      servo.write(Level3);
      Serial.println("Servo at Level 3 (135 degrees)");
    } 
    else if (distance > 30 && distance <= 50) {
      // Level 4: Far object (31 to 50 cm)
      servo.write(Level4);
      Serial.println("Servo at Level 4 (180 degrees)");
    } 
    else {
      // Out of range: Stop or reset the servo (optional)
      Serial.println("Out of range or invalid reading");
    }
  }

  // Delay to slow down readings and servo updates
  delay(1000);  // 1 second delay between measurements
}
