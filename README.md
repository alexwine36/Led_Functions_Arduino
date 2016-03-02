# Led_Functions_Arduino

## Purpose

This library is intended to give easy access to common LED functions without making assumptions about the hardware being used.


### Potential Logarithmic Fade Code


```arduino
float getRval(int intervals, int ledMax) {
  float rVal;
  rVal = (intervals * log10(2)) / (log10(ledMax));
  return rVal;
}

int getBrightness(int interval, float rVal) {
  int brightVal = 0;
  brightVal = pow(2, (interval/rVal)) - 1;
  return brightVal;
}
```

#### Calling Function


```arduino
void setup() {
  R = getRval(pwmIntervals,255);
}
void loop() {
  for(int i = 0; i <= pwmIntervals; i++) {
    
    brightness = getBrightness(i,R);
    analogWrite(led, brightness);
  }
}

```

##### Notes

* Red, Green, and Blue rValues must be tracked in order to be effective
* rValues must be stored and called during the getBrightness function
* Function cannot be blocking to allow other processes to function
* Potential Solutions
  * Create an array of rValues
  * Have application call "steps" whenever desired through getBrightness Function
