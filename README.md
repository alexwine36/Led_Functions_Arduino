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

#### Get uint32_t
```arduino

for (int i=0; i < intervals; i++) {
	uint32_t color = turquoise.rgbGetBrightness(i);
}
```

#### Get RGB values
```arduino
for (int i=0; i < intervals; i++) {
	 turquoise.rgbGetBrightness(i);

	 int red = turquoise.r();
	 int green = turquoise.g();
	 int blue = turquoise.b();
}
```
