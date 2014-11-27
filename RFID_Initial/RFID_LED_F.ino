#include <SoftwareSerial.h>
#include "LEDlight.h"

//Parallax RFID Reader 
#define RFIDEnablePin 2 //Pin that enables reading. Set as OUTPUT and LOW to read an RFID tag
#define RFIDSerialRate 2400 //Parallax RFID Reader Serial Port Speed

//Using SoftwareSerial Library to locate the serial pins off the default set
//This allows the Arduino to be updated via USB with no conflict
#define RxPin 5 //Pin to read data from Reader 
#define TxPin 4 //Pin to write data to the Reader NOTE: The reader doesn't get written to, don't connect this line.
SoftwareSerial RFIDReader(RxPin,TxPin);



String RFIDTAG=""; //Holds the RFID Code read from a tag
String DisplayTAG = ""; //Holds the last displayed RFID Tag

LEDlight light;
#define RPin 11
#define GPin 10
#define BPin 9

void setup() 
{
  // RFID reader SOUT pin connected to Serial RX pin at 2400bps
  RFIDReader.begin(RFIDSerialRate);

  // Set Enable pin as OUTPUT to connect it to the RFID /ENABLE pin
  pinMode(RFIDEnablePin,OUTPUT); 

  // Activate the RFID reader
  // Setting the RFIDEnablePin HIGH will deactivate the reader
  // which could be usefull if you wanted to save battery life for
  // example.
  digitalWrite(RFIDEnablePin, LOW);

  Serial.begin(9600);           // set up Serial library at 9600 bps
  light._begin(&Serial);
  light.initial(RPin, GPin, BPin);

  Serial.println("Hello world!");  // prints hello with ending line break 
  light.LEDColor(1,1000); // Green light for set up
}

void loop() 
{
  light.LEDColor(0,0);
  if(RFIDReader.available() > 0) // If data available from reader
  { 
    ReadSerial(RFIDTAG);  //Read the tag number from the reader. Should return a 10 digit serial number
  }

  //This only displays a tag once, unless another tag is scanned
  if(DisplayTAG!=RFIDTAG)
  {
    light.LEDColor(1,1000);
    DisplayTAG=RFIDTAG;
    Serial.println(RFIDTAG);
  }
}

void ReadSerial(String &ReadTagString)
{
  light.LEDColor(3,0);
  int bytesread = 0;
  int  val = 0; 
  char code[10];
  String TagCode="";

  if(RFIDReader.available() > 0) {          // If data available from reader 
    if((val = RFIDReader.read()) == 10) {   // Check for header 
      bytesread = 0; 
      while(bytesread<10) {                 // Read 10 digit code 
        if( RFIDReader.available() > 0) { 
          val = RFIDReader.read(); 
          if((val == 10)||(val == 13)) {   // If header or stop bytes before the 10 digit reading 
            break;                         // Stop reading 
          } 
          code[bytesread] = val;           // Add the digit           
          bytesread++;                     // Ready to read next digit  
        } 
      } 
      if(bytesread == 10) {                // If 10 digit read is complete 

        for(int x=0;x<10;x++)              //Copy the Chars to a String
        {
          TagCode += code[x];
        }
        ReadTagString = TagCode;          //Update the caller
        while(RFIDReader.available() > 0) //Burn off any characters still in the buffer
        {
          RFIDReader.read();
        } 

      } 
      bytesread = 0;
      TagCode="";
    } 
  } 
}


