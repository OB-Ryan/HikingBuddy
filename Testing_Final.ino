#include <Adafruit_NeoPixel.h>

// Sensors
const int lightPin = A11;       // Light sensor on pin 12
const int tempPin = A9;         // TMP36 on pin 9
const int numReadings = 10;     // For temperature averaging

// NeoPixel on SDA (pin 2)
#define LED_PIN    2
#define LED_COUNT  1

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Rainbow variables
int rainbowHue = 0;

void setup() {
  Serial.begin(9600);
  analogReference(DEFAULT);
  strip.begin();
  strip.setBrightness(50); // Adjust 0-255
  strip.show();
}

void loop() {
  // Read and average temperature
  long sum = 0;
  for (int i = 0; i < numReadings; i++) {
    sum += analogRead(tempPin);
    delay(10);
  }
  int tempReading = sum / numReadings;
  
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
  
  // Rainbow cycle on NeoPixel
  strip.setPixelColor(0, strip.gamma32(strip.ColorHSV(rainbowHue)));
  strip.show();
  
  // Increment hue for next color (0-65535)
  rainbowHue += 256;  // Adjust speed: higher = faster cycle
  if (rainbowHue >= 65536) {
    rainbowHue = 0;
  }
  
  delay(20);  // Fast updates for smooth rainbow
}
