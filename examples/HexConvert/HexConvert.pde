#include <Led_Functions.h>

Led_Functions h("FFE26B");

void setup()
{
    Serial.begin(9600);
    Serial.print("Red: ");
    Serial.println(h.r());
    Serial.print("Green: ");
    Serial.println(h.g());
    Serial.print("Blue: ");
    Serial.println(h.b());
    h.toHexString("EFAFE0");
    Serial.print("Red: ");
    Serial.println(h.r2());
    Serial.print("Green: ");
    Serial.println(h.g2());
    Serial.print("Blue: ");
    Serial.println(h.b2());
}

void loop()
{

}