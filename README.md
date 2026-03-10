# Tutorial for Design and Assembly of the HikingBuddy Project

## Introduction
Hiking is a great way to get outside, clear your mind, get exercise, and connect with nature. One challenge hikers face is uncertainty about current weather conditions. HikingBuddy offers a unique solution to this uncertainty. Using an Adafruit Flora microcontroller, HikingBuddy provides real-time information about temperature and light conditions, allowing users to make more informed decisions about their outdoor adventures. HikingBuddy attaches to a standard backpack using velcro and uses two NeoPixel LEDs to inform users about the optimality of light and temperature conditions. It also allows users to easily customize the threshold ranges to suit their personal preferences.


## Materials

### Materials List
- [1 Adafruit Flora Microcontroller](https://www.adafruit.com/product/659) - $14.95
- [1 LilyPad Sewable Light Sensor](https://www.sparkfun.com/lilypad-light-sensor.html) - $5.25
- [1 TMP36 Temperature Sensor](https://www.adafruit.com/product/165) - $2.75
- [1 Conductive Thread](https://www.adafruit.com/product/603) - $4.50
- [Sewing Needles](https://www.adafruit.com/product/603) - $5
- Fabric
- [Beeswax (optional)](https://a.co/d/0i4Q4bqV) - $5.50
- Micro USB Cord
- Computer for Programming
- Scissors (optional)
- Ruler (optional)
- Sharpie/Marker (optional)
- [1 Sewable NeoPixel LEDs](https://www.adafruit.com/product/1260) - $6.50 each
- [3 Velcro Tabs/Strips](https://a.co/d/0iyklyGx) - $7.70
- Clear Nail Polish for Securing Knots (optional)
- [1 3.7V Rechargeable Battery with JST Connector](https://www.adafruit.com/product/2750) - $7

### Materials Explanation
- **Adafruit Flora**
    - The Flora is a sewable, fabric-friendly microcontroller made by Adafruit. The board uses the ATmega32u4 microcontroller and is compatible with the Arduino IDE. You can learn more about the properties of the Flora, and how to use it, [here](https://www.instructables.com/How-to-use-the-Adafruit-Flora-board-Arduino-Tutori/).
- **LilyPad Sewable Light Sensor**
    - The LilyPad light sensor is a sewable light sensor that is well suited for e-textiles projects. Like a standard light sensor, it contains a [photoresistor](https://physics-and-radio-electronics.com/electronic-devices-and-circuits/passive-components/resistors/photoresistor.html), but on a sewing-friendly board with large tabs for thread connections. It produces an analog reading that the Flora microcontroller can interpret. Read more about this component [here](https://learn.sparkfun.com/tutorials/lilypad-light-sensor-hookup-guide/all).
- **TMP36 Temperature Sensor**
    - The TMP36 is a popular, low-voltage (2.7V to 5.5V) temperature sensor that produces a voltage linearly proportional to temperature in Celsius. It includes 3 pins: power, ground, and voltage out (sense). Learn more about this sensor [here](https://www.arduino.cc/en/uploads/Main/TemperatureSensor.pdf).
- **Conductive Thread**
    - Conductive thread is similar to regular thread, but with the additional property of conducting electricity. This allows us to design flexible circuits by running traces of conductive thread. You can learn more about conductive thread [here](https://chibitronics.com/how-to/guide-to-conductive-thread/).
- **Sewing Needles**
    - It is okay to use inexpensive needles, but make sure the set includes small, thin needles. The sew holes on some components can be very small, and large needles will not fit.
- **Fabric**
    - A good fabric for this project is something flexible and at least 7x7 inches. Avoid fabrics that snag or tear easily. Choose your favorite color or pattern — for this project, a cheap red fabric in a 10x10 inch sheet was used.
- **Beeswax**
    - Beeswax can be applied to the ends of thread to help prevent fraying and make threading through the eye of a needle easier.
- **Micro USB Cord**
    - A micro USB cord allows you to connect your Flora to your computer to upload code and power the board.
- **Computer**
    - A suitable computer that can install and run the [Arduino IDE](https://www.arduino.cc/en/software/). This is used to program your Flora.
- **Scissors**
    - To cut your fabric.
- **Ruler**
    - To measure fabric dimensions and mark cutting lines.
- **Sharpie/Marker**
    - A marker can be helpful for tracing cutting lines on your fabric. Chalk can also work well for this.
- **Sewable NeoPixel LED**
    - The NeoPixel is a sewable RGB LED that can be controlled directly from the Flora. Each LED is individually addressable, meaning its color and brightness can be set in code. The Flora has one build in NeoPixel LED on the board itself, and makes use of an additonal external NeoPixel. Learn more about the NeoPixel LED [here](https://docs.cirkitdesigner.com/component/e84c1a2d-67dc-38e5-d85b-d198d41b8cbe/neopixel-flora).
- **Velcro Tabs/Strips**
    - Velcro will attach to the arms of the project, allowing it to wrap around and attach to a backpack strap.
- **Clear Nail Polish for Securing Knots**
    - Nail polish is optional, but useful for dabbing on loose thread or knots to help secure them. It can also help secure components — just be careful not to create a short circuit when applying near conductive pads.
- **Battery**
    - The battery powers the project. The Flora accepts batteries with a JST connector. The linked battery is 3.7V with a cable length suitable for this project.
### Workspace
It is important to choose a suitable workspace for this project. An ideal workspace should have plenty of room for sewing and be well lit. If you are using nail polish to secure thread knots or components, ensure your workspace is well ventilated. Good examples include an uncluttered desk, a dining room table, or your local makerspace.


## Circuit Design
### Components and Connections
1. **The Adafruit Flora**. This is the brains of the project, all components will be connected to the pins on the board. The pins are clearly labeled directly on the board, which makes locating them easy. The Flora also includes a built-in NeoPixel LED onboard, which this project uses to display light conditions.
1. **NeoPixel LED**. The NeoPixel LED has 4 pin holes: power, marked with a `+`; ground, marked with a `-`; signal in, marked with a `->` that points toward the LED when the NeoPixel is oriented with `-` on the left and `+` on the right; and signal out, marked with a `->` that points away from the LED in the same orientation. Signal out is used to chain NeoPixels together and will not be used in this project. This external NeoPixel will display temperature conditions and its signal in pin will be connected to pin `SDA #2` on the Flora. The ground pin will be connected to the `GND` pin on the Flora adjacent to the JST battery connector. The power pin will connect to the `3.3V` power pin on the Flora adjacent to the Micro-USB connector.
1. **LilyPad Light Sensor**. The LilyPad light sensor has 3 pin holes: power, marked with a `+`; ground, marked with a `-`; and sense, marked with `S`. Power will be connected to the power of the TMP36, then routed to the `3.3V` power pin on the Flora adjacent to the Micro-USB connector. Ground will be connected to the ground of the TMP36, then routed to the `GND` pin on the Flora between pins `#6` and `#9`. Sense will be connected to pin `#12` on the Flora.
1. **TMP36 Temperature Sensor**. The TMP36 has three pins: power, sense, and ground. With the flat side of the sensor facing you, the pins from left to right are power, sense, and ground. Power will connect to the `3.3V` power pin on the Flora adjacent to the Micro-USB connector. Sense will connect to pin `#9` on the Flora. Ground will connect to the `GND` pin on the Flora between pins `#6` and `#9`.
1. **Battery**. The 3.7V battery is responsible for powering the project. It connects to the Flora using the onboard JST connector and can only be inserted one way. When removing the battery, avoid pulling by the wires, instead, grip the white plastic JST connector and pull carefully.

### Pictorial Schematic
![Pictorial Schematic](tutorial_images/FinalProjectSchematic_Root.png)


### Making the TMP36 Sewable
The TMP36 used in this project is not sewable-friendly version, but we can make more sewable-friendly by manually adjusting the pins. To make a component with straight pins sewable, we can bend the pins into a circular shape, to allow threading around it. This can be done with standard needle-nose pliers. Check out the Making Standard LEDs Sewable section of this [E-textiles tutorial](https://www.fashionlacrum.com/articles/beginner-e-textilessoft-circuits). Although this guide is for an LED, the process for a sensor with 3 straight pins is the same. I chose to solder the rounded pins for a stronger, smoother result, but that is an optional step. The end result should look similar to below:
![SewabelTMP36](tutorial_images/TMP.JPG)

## Fabric Layout and Design

### Measuring
It is a good idea to take measurements before you cut your fabric and begin assembly. The first measurement to take is the width of the backpack strap. This will give you the total working fabric width for attaching components, since this will be the forward-facing surface. I measured the width of my strap to be 2.5 inches. The next step is to estimate the total length/height needed to fit all your components. After laying them out on a piece of paper, I estimated I would need 6 inches.

After getting these base measurements for the backpack and components, we need to think about the velcro attachment arms. For this I measured the velcro I had for width and length. I decided to use 3 velcro tabs that together were 2.75 inches long and 1 inch tall. I added 3 evenly spaced 2.75 inch by 1 inch arms to each side of the base dimensions.

After deciding on the dimensions for your fabric, it is a good idea to draw it to scale on a piece of paper and lay out your components to make sure everything will fit as expected. An example of what that might look like can be seen below.

![Measurement_Sketch](tutorial_images/Measurement.jpg)

You can also use this paper sketch to plan your traces. I found it helpful to place the actual components on the sketch and use a pencil to draw where the thread connections would go. It is important that no traces of thread cross in your final design, as this could lead to a short circuit. If you find that components cannot be placed without traces crossing, try different orientations until you find one that works.

### Cutting the Fabric
Once you have decided on dimensions for your fabric, it is time to cut it out. It is helpful to make a paper template first. Use a ruler and writing utensil to carefully measure and mark out your design on a piece of paper, then cut it out with scissors. Verify it fits as expected on the backpack and with your components. You can see the template I used below.

![template](tutorial_images/template.jpg)

Once you have your template cut out and verified that it is the correct size, use it to cut out your actual fabric.
1. Place the paper template on your chosen fabric
2. Hold it in place with one hand
3. Use your other hand to carefully trace around the template onto the fabric using a marker, sharpie, or chalk
4. Once it is fully traced, use scissors to carefully cut along the inside of the lines
5. Once fully cut out, trim any frayed or loose ends

## Assembling Your Components
Now that you have your fabric cut, it is time to assemble the project. If you have never sewn before, I recommend practicing on scrap fabric with regular thread before starting on your project. Practice tying knots and keeping stitching tight. I recommend [this beginner sewing tutorial](https://www.youtube.com/watch?v=QhZTc1x1-pM) on YouTube.

Start by securing the Flora to the fabric using a couple of non-conductive thread loops through pins that will not be used in the project. I chose to make loops through pins `VBATT` and `SCL #3` on the Flora. Start by making a fabric knot close to these pins, then loop your thread around the pin pad 4–7 times, ensuring it will securely hold the board in place. When finished, make sure your knots are tight and trim any loose thread ends with scissors.

The next step is to attach each component using conductive thread. Since you have already planned out the traces in previous steps, this part should be fairly straightforward. When sewing traces with conductive thread, keep the following in mind:
- Ensure that conductive thread traces do not cross
- Tighter stitches will give a more durable and visually appealing result
- Keep loops through pin pads tight and abundant. Loose loops can result in partial or intermittent connections
- Conductive thread can be springy, leading to a tendency for knots to come undone. Dabbing clear nail polish on knots can help secure them
- Trim excess thread close to its source
- Test components as you go! If something went wrong, it is better to catch it early
- Be patient. E-textile projects have more sources for bugs than typical electronics projects and can be frustrating to debug. Taking breaks can help.

See reference photos below for each component connection.

### NeoPixel LED
![NeoPixel](tutorial_images/NeoPixel.JPG)
![NeoPixelBoard](tutorial_images/NeoPixel_Board.JPG)
![NeoPixelBack](tutorial_images/NeoBack.JPG)

### LilyPad Light Sensor and TMP36
![TMP36_LilyPadLight](tutorial_images/tmpLight.JPG)

### All Components
![FullFront](tutorial_images/FullFront.JPG)
![FullFrontLarge](tutorial_images/FullFrontLarge.JPG)

## Attaching the Battery Pouch
Now that all the components are attached, we need to secure the battery. The easiest and most straightforward way to do this is with a battery pouch. Cut a piece of fabric that is 2.5 inches wide and 1.5 inches tall.

![BatFabricCut](tutorial_images/Bat1.JPG)

Sew the fabric onto the back side of the HikingBuddy using regular thread, making sure it is aligned with the bottom edge (the bottom is the side with the sensors). Slide the battery into this pocket and route the cable around to the front to connect with the JST connector on the Flora.

![BatPouchAttachedBack](tutorial_images/Bat2.JPG)
![BatPouchAttachedFront](tutorial_images/FinishedFront.JPG)


## Attaching the Velcro
The HikingBuddy is designed to attach to any conventional 2-strap backpack. To achieve this, it uses velcro strips on the arms of the fabric so that it can wrap around a strap and secure itself in place. The velcro used here are small, self-adhesive tabs. Other types of velcro will work too, but self-adhesive tabs or strips are the easiest and most straightforward option.

![Velcro1](tutorial_images/Velcro1.jpg)

Notice that there are two different kinds of velcro included. One has a softer (loop) surface, and the other has a rougher (hook) surface. Hook-and-loop velcro sticks when the two different surfaces are pressed together. With the Flora side of the HikingBuddy facing you, stick soft velcro tabs on all of the left arms. In my case, 3 tabs on each arm.

![Velcro3](tutorial_images/Velcro3.jpg)

Flip the HikingBuddy over with the battery pouch facing you. Then stick rough velcro tabs on all of the right arms. In my case, 3 tabs on each arm.

![Velcro2](tutorial_images/Velcro2.jpg)

This creates opposing velcro arms that will overlap when wrapped around a backpack strap, allowing the HikingBuddy to attach and detach easily.

![Velcro4](tutorial_images/Velcro4.jpg)



## Code
### Getting Started
The coding for this project is done using the Arduino IDE. If you have not yet set up your Flora in the Arduino IDE, now is a good time to do so. I recommend [this guide](https://learn.adafruit.com/adafruit-arduino-ide-setup/arduino-1-dot-6-x-ide) to get started. All code for this project can be found in `Calibrate.ino`. Donwload this code, open it in the Arduino IDE, and upload it to your board to get started.

### Overview
The code for this project is contained in `Calibrate.ino`, and uses defined light and temperature threshold values to set the ranges for poor/sub-optimal/optimal conditions. The top of the code contains the block defining these values for light and temperature.
```C
#define LIGHT_1 20
#define LIGHT_2 100
#define LIGHT_3 500
#define LIGHT_4 700
#define TEMP_1 33
#define TEMP_2 45
#define TEMP_3 68
#define TEMP_4 80
```

These are the default values for the given ranges, which I determined to be optimal for myself. They work in the following way; for a given sensor value definition (`LIGHT` or `TEMP`):
- `_1` is the upper threshold for bad quality. When the sensor data is below this value, the corresponding NeoPixel will be red.
- `_2` is the upper threshold for sub-optimal quality. When the sensor data is between `_1` and `_2`, the corresponding NeoPixel will be yellow.
- `_3` is the upper threshold for optimal quality. When the data is between `_2` and `_3`, the corresponding NeoPixel will be green.
- `_4` is the upper threshold for sub-optimal quality. When the data is between `_3` and `_4`, the corresponding NeoPixel will be yellow.
- Anything above `_4` is bad quality. When the data is above `_4`, the corresponding NeoPixel will be red.

**Note that all `TEMP_*` values are in Fahrenheit, and all `LIGHT_*` values are raw analog sensor readings (0–1023 on a 10-bit ADC).**

There are several functions in the code to achieve this behavior:
- `init_neo()` — Initializes a given NeoPixel object, setting its brightness to 50 and its initial state to OFF.
- `yellow()` — Changes a given NeoPixel to shine yellow.
- `red()` — Changes a given NeoPixel to shine red.
- `green()` — Changes a given NeoPixel to shine green.
- `color_temp()` — Takes a given NeoPixel and temperature value, and calls the corresponding color function based on the `TEMP_*` threshold values.
- `color_light()` — Takes a given NeoPixel and light value, and calls the corresponding color function based on the `LIGHT_*` threshold values.
- `setup()` — Runs once at startup. Sets the analog reference value to the default for 3.3V boards and initializes both NeoPixels.
- `loop()` — Runs continuously after setup. First takes 10 temperature readings with a 10ms delay between each and averages them. Then converts the averaged reading to a voltage, then to Celsius, then to Fahrenheit. Next it reads the light sensor value. It then passes all data to the corresponding `color_*` functions to set the NeoPixels to the correct color. After a 1 second delay, the loop repeats.

### Calibration
There is another file called `Calibrate.ino` that will help you define more personalized `LIGHT_*` and `TEMP_*` threshold values. This program is similar to `HikingBuddy.ino`, except there are no defined threshold values and no code to control the NeoPixel LEDs. Instead, the temperature and light sensor values are printed to the serial console. To use it, upload the code to the board and keep it connected via the Micro-USB cable. Then open the Serial Monitor in the Arduino IDE and expose the board to different light and temperature conditions. Note what values correspond to conditions you find bad, sub-optimal, or optimal, and adjust the `LIGHT_*` and `TEMP_*` values in `HikingBuddy.ino` accordingly. An example of the program output can be seen below.

![CalibrationExample](tutorial_images/CalibrationExample.png)


## Conclusion
Congratulations on building the HikingBuddy! You have successfully assembled an e-textile wearable that uses temperature and light sensors to give real time data feedback about hiking weather conditions through NeoPixel LEDs. This project included many opurtunities to gain experience with the Adafruit Flora, conductive thread sewing, and the Arduino IDE.
![FinsihedProduct](tutorial_images/BackPack.JPG)
