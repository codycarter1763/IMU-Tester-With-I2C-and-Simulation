#include <Arduino.h>
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  delay(1000);
  Wire.begin(21, 22);

  Serial.println("Initializing MPU6050...");
  mpu.initialize();

  if (mpu.testConnection()) {
    Serial.println("MPU6050 connected successfully");
  } else {
    Serial.println("MPU6050 connection failed");
  }
}

void loop() {
  int16_t ax, ay, az;  // Accelerometer
  int16_t gx, gy, gz;  // Gyroscope

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Accelerometer (raw values)
  Serial.print("Accel X: "); Serial.print(ax);
  Serial.print("  Y: ");     Serial.print(ay);
  Serial.print("  Z: ");     Serial.println(az);

  // Gyroscope (raw values)
  Serial.print("Gyro  X: "); Serial.print(gx);
  Serial.print("  Y: ");     Serial.print(gy);
  Serial.print("  Z: ");     Serial.println(gz);

  Serial.println("---");
  delay(500);
}