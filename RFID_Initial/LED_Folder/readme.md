Create an LED Light function that does the following:
void LEDLight(int color, int duration);

Lights an RGB LED with whatever color input is given to it.
Inputs can be an integer so it'd be like (if color==1, then LED displays red).

At the beginning of the RFID code, we can assign constants like
```
#DEFINE RGB_RED 1
#DEFINE RGB_YELLOW 2
```
etc. so then when we call this function in main it can be 
```
LEDLight(RGB_RED, 1000); // Make light display red for 1 second.
```
