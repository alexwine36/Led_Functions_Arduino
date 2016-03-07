#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6

int pix = 20;
int intervals = 200;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(pix, PIN, NEO_GRB + NEO_KHZ800);

#include <Led_Functions.h>

/*
 * Potential Warm Light Colors:
 * E0C585
 * FFE066
 * FFD166
 * F5D03D
 */

Led_Functions goal("05D03D");

void setup() {
  strip.begin();
  strip.show();
  Serial.begin(9600);
  Serial.println(goal.r());
  Serial.println(goal.g());
  Serial.println(goal.b());
  goal.fadeSetup(200);

}
void loop() {
  for (int i = 0; i < intervals; i++) {
    uint32_t color = goal.rgbGetBrightness(i);
//    Serial.println(rgb1[0]);
//    Serial.println(color, HEX);
    for (int f = 0; f < pix; f++) {
      strip.setPixelColor(f, color);
    }
    strip.show();
    delay(10);
  }
    for (int i = intervals; i > 0; i--) {
    uint32_t color = goal.rgbGetBrightness(i);
//    Serial.println(rgb1[0]);
//    Serial.println(color, HEX);
    for (int f = 0; f < pix; f++) {
      strip.setPixelColor(f, color);
    }
    strip.show();
    delay(10);
  }
}
