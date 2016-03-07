#include "Arduino.h"
#include "Led_Functions.h"

Led_Functions::Led_Functions(String hexString)
{
  _hexString = hexString;
  _convertHexString(_hexString);
  for(int i=0;i<3;i++)
  {
    rgb1[0] = rgb[0];
    rgb1[1] = rgb[1];
    rgb1[2] = rgb[2];
  }

}

void Led_Functions::toHexString(String hexString2)
{
  _convertHexString(hexString2);
  for(int i=0;i<3;i++)
  {
    rgb2[0] = rgb[0];
    rgb2[1] = rgb[1];
    rgb2[2] = rgb[2];
  }
}

// Log fade functions
float Led_Functions::getRval(int intervals, int ledMax) {
  float rVal;
  rVal = (intervals * log10(2)) / (log10(ledMax));
  return rVal;
}

int Led_Functions::getBrightness(int interval, float rVal) {
  int brightVal = 0;
  brightVal = pow(2, (interval/rVal)) - 1;
  return brightVal;
}

// Setup
// Enter at least steps
// void Led_Functions::fadeSetup(int steps, int ledRed = rgb2[0], int ledGreen = rgb2[1], int ledBlue = rgb2[2]) {
void Led_Functions::fadeSetup(int steps) {
  rgbR[0] = getRval(steps, rgb1[0]);
  rgbR[1] = getRval(steps, rgb1[1]);
  rgbR[2] = getRval(steps, rgb1[2]);
}

// Loop
// Enter interval
uint32_t Led_Functions::rgbGetBrightness(int interval) {
  rgb1[0] = getBrightness(interval, rgbR[0]);
  rgb1[1] = getBrightness(interval, rgbR[1]);
  rgb1[2] = getBrightness(interval, rgbR[2]);
  uint32_t c = Color(rgb1[0],rgb1[1],rgb1[2]);
  return c;
}

uint32_t Led_Functions::Color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

// End of Log fade functions


int Led_Functions::r2()
{
  return rgb2[0];
}

int Led_Functions::g2()
{
  return rgb2[1];
}

int Led_Functions::b2()
{
  return rgb2[2];
}

int Led_Functions::r()
{
  return rgb1[0];
}

int Led_Functions::g()
{
  return rgb1[1];
}

int Led_Functions::b()
{
  return rgb1[2];
}


void Led_Functions::_convertHexString(String hexString)
{
  long number = (long) strtol( &hexString[0], NULL, 16);
  rgb[0] = number >> 16;
  rgb[1] = number >> 8 & 0xFF;
  rgb[2] = number & 0xFF;
}
