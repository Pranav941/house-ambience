# House Ambience
Set your house ambience using a temperature sensor and WS281B Addressable LEDs

## Pre-requisites

* Hardware
  + Arduino Uno or any other equivalent board
  + 5v Power supply
  + 3 Male-to-male Jumper Cables
  + 3 Male-to-female Jumper Cables
  + WS281B LED Strip
  + DHT11 or greator temperature sensor
  + Breadboard (Optional)

* Software
  + [Arduino IDE](https://www.arduino.cc/en/software "Download Arduino IDE")
  + Library : FastLED *(not by AdaFruit)* & Unified Sensor by AdaFruit *[howTo](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)*

## Usage

<p> Step 1 : Open main.ino on your Arduino IDE
  Step 2 : Install FastLED & Unified Sensors by AdaFruit
  Step 3 : Enter the number of LEDs on your strip on the 4th line *Change data pins according to your prefrence if needed*
  Step 4 : Select the right Com port via Tools
  Step 5 : Make the right connections *(Check figures below)*
  Step 5 : Hit Upload
  
  #### Note : Disconnect the power supply jumper cable to LED & Sensor to avoid any unwanted issues
