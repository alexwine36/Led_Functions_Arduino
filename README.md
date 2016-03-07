# Led_Functions_Arduino

## Purpose

This library is intended to give easy access to common LED functions without making assumptions about the hardware being used.

## How do I use it?

### Initialize

Select the color that you want to use

```arduino
#include <Led_Functions.h>

// Not necessary but makes life easier
int intervals = 250;

Led_Functions turquoise("0ADA3D");
```

### Setup
Creates values for generating logarithmic fades

```arduino

turquoise.fadeSetup(intervals);
```
### Loop
Loop through the generated values for fading
```arduino

for (int i=0; i < intervals; i++) {
	uint32_t color = turquoise.rgbGetBrightness(i);
}
```
