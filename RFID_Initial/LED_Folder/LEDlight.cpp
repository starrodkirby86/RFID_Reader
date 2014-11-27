#ifndef LEDLIGHT_H_INCLUDED
#define LEDLIGHT_H_INCLUDED

#include "Arduino.h"
#include "HardwareSerial.h"
//#include "SoftwareSerial.h"
class LEDlight
{
    public:
        //////////////////// List of Practical Function ////////////////////
        // Constructor and destructor
        LEDlight();
        ~LEDlight();

        // Hardware Serial begin
        void initial(int, int, int);
        void _begin(HardwareSerial*);

        // Set default color
        void LEDColor(int, int);

        // Set Intensity LED lights
        void LEDintensity(int, int, int, int);

        // LED off for set duration
        void LEDoff(int);

        // read digital values of pin RGB
        void readRGB();
        void readR();
        void readG();
        void readB();
        void readSerial();

        //////////////////// List of Private Function ////////////////////

        // Set Private Values
        void setPinR(int);
        void setPinG(int);
        void setPinB(int);

        // See Private Values
        void printPinR();
        void printPinG();
        void printPinB();

    private:
        HardwareSerial *_Serial;
        int _pinR;
        int _pinG;
        int _pinB;

        const static int RGB_R= 0;
        const static int RGB_G= 1;
        const static int RGB_B= 2;
        const static int RGB_O= 3;
        const static int RGB_Y= 4;
};

#endif // LEDLIGHT_H_INCLUDED
