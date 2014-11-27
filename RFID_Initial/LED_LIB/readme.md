# **LED Library**

   **Component**
   ```
   3 way RGB LED  
   ```
  
   **How to Do It**
   ```Arduino
   LEDlight foo; // before setup initializing LED
   
   In
   void setup(),
   foo.initial(int Red_pin, int Green_pin, int Blue_pin);
   foo._begin(&Serial);
   ```
  
   **List of Functions**
   ```Arduino
   void LEDColor(int localColor, int duration)
      - Select Local Color integer and display indicative value
      - localColor Break down
        - RGB_R - Red/0
        - RGB_G - Green/1
        - RGB_B - Blue/2
        - RGB_O - Orange/3
        - RGB_Y - Yellow/4
        - duration - set in milliseconds (ms)
   ```
   ```Arduino
   void LEDintensity(int R, int G, int B, int D)
      - Select Custom Intensity
        - R - Red   (0-255)
        - G - Green (0-255)
        - B - Blue  (0-255)
        - D - Duration, set in miliiseconds (ms)
   ```
   ```Arduino
   void LEDoff(int Duration)
      - Off for set duration, Duration, in milliseconds (ms)
   ```
   ```Arduino
   void readRGB()
      - Read digital value of R,G,B pins.
   ```
  
