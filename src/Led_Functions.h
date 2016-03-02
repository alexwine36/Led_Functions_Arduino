#ifndef Led_Functions_h
#define Led_Functions_h

#include "Arduino.h"

class Led_Functions
{
    public:
    Led_Functions(String hexString);
    // void writeHex(String hexString);
    void toHexString(String toHexString);

// Log fade functions can return rgb with calls to r(), g(), and b()
    int r();
    int g();
    int b();
    int r2();
    int g2();
    int b2();

    // Log Fade functions
    void fadeSetup(int steps, int ledRed, int ledGreen, int ledBlue);
    uint32_t rgbGetBrightness(int interval);
    uint32_t Color(uint8_t r, uint8_t g, uint8_t b);
    int getBrightness(int interval, float rVal);




    private:
    String _hexString;
    int rgb1[3];
    void _convertHexString(String hexString);
    int rgb2[3];
    int rgb[3];
    float rgbR[3];

    // Log Fade functions
    float getRval(int intervals, int ledMax);

};

#endif
