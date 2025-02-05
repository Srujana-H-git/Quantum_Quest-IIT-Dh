#include <Stepper.h>

// Define the number of steps per revolution for your motor
const int stepsPerRevolution = 200; // Adjust according to your motor specifications

// Initialize the Stepper library with the motor's pins
// Pins 8, 9, 10, 11 are connected to the stepper driver
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Set the speed of the motor in RPM
  myStepper.setSpeed(60); // Set speed to 60 RPM

  // Initialize Serial communication for debugging
  Serial.begin(9600);
  Serial.println("Stepper motor test");
}

void loop() {
  // Rotate the motor one revolution clockwise
  Serial.println("Rotating clockwise...");
  myStepper.step(stepsPerRevolution);
  delay(1000); // Wait for 1 second

  // Rotate the motor one revolution counterclockwise
  Serial.println("Rotating counterclockwise...");
  myStepper.step(-stepsPerRevolution);
  delay(1000); // Wait for 1 second
}
