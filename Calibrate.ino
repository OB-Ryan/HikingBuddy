#include <Adafruit_NeoPixel.h>

/*
Use this file to pick threshold values for HikingBuddy.ino
*/

const int lightPin = A11;       // Light sensor on pin 12
const int tempPin = A9;         // TMP36 on pin 9
const int numReadings = 10;     // For temperature averaging

// Runs once at setup
void setup() {
  Serial.begin(9600);
  analogReference(DEFAULT);
}

// Runs on a loop
void loop() {
  // Read and average temperature
  long sum = 0;
  for (int i = 0; i < numReadings; i++) {
    sum += analogRead(tempPin);
    delay(10);
  }
  int tempReading = sum / numReadings;
  
  // Convert temp reading to F and C
  float voltage = tempReading * 3.3 / 1024.0;
  float temperatureC = (voltage - 0.5) * 100.0;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  
  // Read light sensor
  int lightLevel = analogRead(lightPin);
  
  // Print sensor values
  Serial.print("Light: ");
  Serial.print(lightLevel);
  Serial.print("  |  Temp: ");
  Serial.print(temperatureC, 1);
  Serial.print("°C / ");
  Serial.print(temperatureF, 1);
  Serial.println("°F");
}
