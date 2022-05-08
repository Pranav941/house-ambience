# House Ambience
Set your house ambience in accordance to the ambient temperature around you using simple devices in 5 steps !

## Pre-requisites

* **Hardware**
  + Arduino Uno or any other equivalent board
  + 5v Power supply
  + 3 Male-to-male Jumper Cables
  + 3 Male-to-female Jumper Cables
  + WS281B LED Strip
  + DHT11 or newer temperature sensor
  + Breadboard (Optional)

* **Software**
  + [Arduino IDE](https://www.arduino.cc/en/software "Download Arduino IDE")
  + Library : FastLED *(not by AdaFruit)* & Unified Sensor by AdaFruit  (*[howTo](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)*)

## Usage

  Step 1 : Open main.ino on your Arduino IDE\
  Step 2 : Install "FastLED" & "Unified Sensors" by AdaFruit\
  Step 3 : Enter the number of LEDs on your strip on the 4th line (*You can change data pins according to your prefrence*)\
  Step 4 : Select the right Com port via 'Tools'\
  Step 5 : Make the right connections *(Check figure below)*\
  Step 5 : Hit "Upload"
  
  #### Note : After use disconnect the power supply jumper cable to LED Strip & Sensor to avoid any unwanted issues

  ![Connections](https://github.com/Pranav941/house-ambience/blob/main/resource/Untitled.png?raw=true)
