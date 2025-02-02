#include <Adafruit_VL53L0X.h>
#include <Stepper.h>

// Define constants
const float STEPS_PER_REV = 32;    // Steps per revolution for your stepper motor
const float GEAR_RED = 64;         // Gear reduction
const int stepperSpeed = 100;      // Speed in RPM (adjusted for accuracy)
const int scanningResolution = 45; // Angle increment in degrees

// Initialize ToF sensor
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

// Initialize stepper motor (adjust pins as needed)
Stepper stepper(STEPS_PER_REV, 8, 9, 10, 11);

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(1); // Wait for Serial connection
  }

  // Initialize ToF sensor
  if (!lox.begin()) {
    Serial.println("Failed to initialize VL53L0X sensor!");
    while (1);
  }

  // Initialize stepper motor
  stepper.setSpeed(stepperSpeed);
  Serial.println("Stepper and ToF Sensor initialized.");
}

void loop() {
  // Perform a single 360° scan
  for (int angle = 0; angle < 360; angle += scanningResolution) {
    // Measure distance
    VL53L0X_RangingMeasurementData_t measure;
    lox.rangingTest(&measure, false);

    int distance = (measure.RangeStatus != 4) ? measure.RangeMilliMeter : -1; // -1 for out of range

    // Send (angle, distance) via Serial
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("°, Distance: ");
    if (distance != -1) {
      Serial.print(distance);
      Serial.println(" mm");
    } else {
      Serial.println("-1");
    }

    // Rotate stepper motor by the resolution
    int stepsForResolution = (STEPS_PER_REV * GEAR_RED * scanningResolution) / 360;
    stepper.step(stepsForResolution);

    delay(1000); // Allow time for sensor stabilization
  }

  Serial.println("One full 360° scan complete!");
   while (1); // Halt the program
}
