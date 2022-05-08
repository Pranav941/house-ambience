/* GitHub: https://github.com/Pranav941/house-ambience */

#include "FastLED.h" // Library to control the LEDs
#include "DHT.h" // Library to control the DHT Sensor

#define NUM_LEDS 60 // Defining the number of LED present on the LED Strip
#define DATA_PIN 3 // Defining a Data Pin

#define DHTPIN 2 // Defining the Data pin for DHT sensor
#define DHTTYPE DHT11 // Defining the type of DHT Sensor

CRGB leds[NUM_LEDS]; // Initializing a Array with the number of LEDs

/* Source MSN Weather
Cool = 17 (Candle) Candle=0xFF9329 [ 1900 Kelvin, 255, 147, 41 ], hsv(30,84,100)
24 = Normal (20 to 22 is normal room temperature) (Tungsten100W) Tungsten100W=0xFFD6AA [ 2850 Kelvin, 255, 214, 170 ], hsv(31,33,100)
Hot = 32 () (CarbonArc) CarbonArc=0xFFFAF4 [ 5200 Kelvin, 255, 250, 244 ],
*/

uint8_t hue = 0;
DHT dht(DHTPIN, DHTTYPE); // Initializing the DHT controller function

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS); // Initializing the FastLED controller function
  FastLED.setBrightness(50); // Moderate brightness set up
  
  Serial.begin(9600);
  Serial.println(F("DHT11 test!"));
  dht.begin();
}

void loop() {
  EVERY_N_SECONDS(2) { // Min 2000 are required for DHT11 to update precisely

    fill_solid(leds, NUM_LEDS, CRGB::White); // Default color on start up set to white
    float temp = dht.readTemperature(); // Reading live temperature to a variable for if-else cycle
    
    if(temp >0 && temp <20) { // 1 to 19
      FastLED.setTemperature(Candle);
      FastLED.show();
    } else if(temp >19 && temp <28) { // 20 to 27
      FastLED.setTemperature(Tungsten40W);
      FastLED.show();
    }
    else if(temp >27 && temp <50) { // 28 to 49
      FastLED.setTemperature(CarbonArc);
      FastLED.show();
    }
    Serial.println(temp); // Print read temperature to serial
    }
  }
