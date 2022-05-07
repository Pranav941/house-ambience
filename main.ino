#include "FastLED.h"
#include "DHT.h"

#define NUM_LEDS 60
#define DATA_PIN 3

#define DHTPIN 2
#define DHTTYPE DHT11

CRGB leds[NUM_LEDS];

// Source MSN Weather
// Cool = 17 (Candle) Candle=0xFF9329 /* 1900 Kelvin, 255, 147, 41 */, hsv(30,84,100)
// 24 = Normal (20 to 24 is normal room temperature) (Tungsten100W) Tungsten100W=0xFFD6AA /* 2850 Kelvin, 255, 214, 170 */, hsv(31,33,100)
// Hot = 32 () (CarbonArc) CarbonArc=0xFFFAF4 /* 5200 Kelvin, 255, 250, 244 */,

uint8_t hue = 0;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  
  Serial.begin(9600);
  Serial.println(F("DHT11 test!"));
  dht.begin();
}

void loop() {
  EVERY_N_SECONDS(2) { // Min 2000 are required for DHT11 to update precisely

    fill_solid(leds, NUM_LEDS, CRGB::White);
    float temp = dht.readTemperature();
    
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
    Serial.println(temp);
    }
  }
