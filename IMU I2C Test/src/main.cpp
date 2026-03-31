#include <Arduino.h>
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  delay(1000);  // Let serial stabilize

  Wire.begin(21, 22);  // SDA=GPIO21, SCL=GPIO22 (default ESP32 pins)

  Serial.println("I2C Scanner — scanning...");

  byte count = 0;

  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Device found at address 0x");
      if (addr < 16) Serial.print("0");
      Serial.println(addr, HEX);
      count++;
    } else if (error == 4) {
      Serial.print("Unknown error at 0x");
      if (addr < 16) Serial.print("0");
      Serial.println(addr, HEX);
    }
  }

  if (count == 0)
    Serial.println("No I2C devices found.");
  else
    Serial.println("Scan complete.");
}

void loop() {}