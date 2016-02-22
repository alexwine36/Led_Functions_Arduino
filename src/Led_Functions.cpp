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