#include <Adafruit_NeoPixel.h>

/*
  DEFINE RANGE VALUES AS FOLLOWS:
  For a given sensor (light or temp):

  Such that:
  < 1: Red, too low range
  1 - 2: Yellow, sub-optimal low range
  2 - 3: Green, optimal range
  3 - 4: Yellow, sub-optimal high range
  > 4: Red, too high range
*/
#define LIGHT_1 20
#define LIGHT_2 100
#define LIGHT_3 500
#define LIGHT_4 700
#define TEMP_1 33
#define TEMP_2 45
#define TEMP_3 68
#define TEMP_4 80

const int lightPin = A11;       // Light sensor on pin 12
const int tempPin = A9;         // TMP36 on pin 9
const int numReadings = 10;     // Number of readings to take for a temperature average
const int neoPixel_1 = 2;       // Neopixel on pin 2
const int neoPixel_2 = 8;       // On board NeoPixel

// Init NeoPixels
Adafruit_NeoPixel neo_temp = Adafruit_NeoPixel(1, neoPixel_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neo_light = Adafruit_NeoPixel(1, neoPixel_2, NEO_GRB + NEO_KHZ800);

// Initialize the given NeoPixel to brightness 50, and OFF
void init_neo(Adafruit_NeoPixel &neo) {
  neo.begin();
  neo.setBrightness(50);
  neo.show();
}

// Change given NeoPixel to be yellow
void yellow(Adafruit_NeoPixel &neo) {
  neo.setPixelColor(0, neo.Color(255, 255, 0));
  neo.show();
}

// Change given NeoPixel to be red
void red(Adafruit_NeoPixel &neo) {
  neo.setPixelColor(0, neo.Color(255, 0, 0));
  neo.show();
}

// Change given NeoPixel to be green
void green(Adafruit_NeoPixel &neo) {
  neo.setPixelColor(0, neo.Color(0, 255, 0));
  neo.show();
}

// Change the NeoPixel color for temperature value given the defined threshold
void color_temp(Adafruit_NeoPixel &neo, float temp_F) {
  if (temp_F < TEMP_1 || temp_F > TEMP_4) {
    red(neo);
  } else if ((temp_F >= TEMP_1 && temp_F < TEMP_2) || (temp_F > TEMP_3 && temp_F <= TEMP_4)) {
    yellow(neo);
  } else if ((temp_F >= TEMP_2 && temp_F <= TEMP_3)) {
    green(neo);
  }
}

// Change the NeoPixel color for light value given the defined threshold
void color_light(Adafruit_NeoPixel &neo, int light) {
  if (light < LIGHT_1 || light > LIGHT_4) {
    red(neo);
  } else if ((light >= LIGHT_1 && light < LIGHT_2) || (light > LIGHT_3 && light <= LIGHT_4)) {
    yellow(neo);
  } else if ((light >= LIGHT_2 && light <= LIGHT_3)) {
    green(neo);
  }
}

// Setup runs once at startup
void setup() {
  analogReference(DEFAULT);

  // Initalize NeoPixels
  init_neo(neo_temp);
  init_neo(neo_light);
}

// Runs on a constant loop after setup
void loop() {
  // Read and average temperature
  long sum = 0;
  for (int i = 0; i < numReadings; i++) {
    sum += analogRead(tempPin);
    delay(10);
  }
  int tempReading = sum / numReadings;
  
  // Convert to F and C, based on temp example and datasheet
  float voltage = tempReading * 3.3 / 1024.0;
  float temperatureC = (voltage - 0.5) * 100.0;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  // Read light sensor
  int lightLevel = analogRead(lightPin);

  // Color the NeoPixels based on sensor readings
  color_temp(neo_temp, temperatureF);
  color_light(neo_light, lightLevel);

  // Wait 1 second
  delay(1000);
}
