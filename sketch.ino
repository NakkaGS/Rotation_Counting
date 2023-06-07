#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;
const int rotationThreshold = 500;  // Threshold to detect a ball rotation
int rotationCount = 0;  // Variable to store the rotation count

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  mpu.initialize();
  mpu.setFullScaleGyroRange(0x03);
}

void loop() {
  // Read the gyroscope data
  int16_t gyroX = mpu.getRotationX();
  int16_t gyroY = mpu.getRotationY();
  int16_t gyroZ = mpu.getRotationZ();
  
  // Calculate the rotational speed around the Y-axis
  float rotationalSpeedY = gyroY / 131.0;
  
  // Print the rotational speed
  Serial.print("Rotational Speed (Y-axis): ");
  Serial.println(rotationalSpeedY);
  
  // Check for a ball rotation
  if (rotationalSpeedY > rotationThreshold) {
    rotationCount++;
    delay(1000);  // Delay to avoid counting multiple rotations
  }
  
  // Print the rotation count
  Serial.print("Rotation Count: ");
  Serial.println(rotationCount);
  
  delay(100);
}

