#ifndef Led_Functions_h
#define Led_Functions_h

#include "Arduino.h"

class Led_Functions 
{
    public:
    Led_Functions(String hexString);
    // void writeHex(String hexString);
    void toHexString(String toHexString);
    int r();
    int g();
    int b();
    int r2();
    int g2();
    int b2();
    
    
    
    private:
    String _hexString;
    int rgb1[3];
    void _convertHexString(String hexString);    
    int rgb2[3];
    int rgb[3];

};

#endif