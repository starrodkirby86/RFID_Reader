#include <SoftwareSerial.h>

//Parallax RFID Reader 
#define RFIDEnablePin 2 //Pin that enables reading. Set as OUTPUT and LOW to read an RFID tag
#define RFIDSerialRate 2400 //Parallax RFID Reader Serial Port Speed

//Using SoftwareSerial Library to locate the serial pins off the default set
//This allows the Arduino to be updated via USB with no conflict
#define RxPin 5 //Pin to read data from Reader 
#define TxPin 4 //Pin to write data to the Reader NOTE: The reader doesn't get written to, don't connect this line.
SoftwareSerial RFIDReader(RxPin,TxPin);

// LED Pins
#define RPin 11
#define GPin 10
#define BPin 9
#define RGB_R 0
#define RGB_G 1
#define RGB_B 2
#define RGB_O 3
#define RGB_Y 4

String RFIDTAG=""; //Holds the RFID Code read from a tag
String DisplayTAG = ""; //Holds the last displayed RFID Tag
//String Color="": // Holds Color

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
  
  Serial.println("Hello world!");  // prints hello with ending line break 
  
  // LED Pins Red Green Blue 
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);
  
  // all off
  digitalWrite(RPin, LOW);
  digitalWrite(GPin, LOW);
  digitalWrite(BPin, LOW);
}

void loop() 
{
  if(RFIDReader.available() > 0) // If data available from reader
  { 
    ReadSerial(RFIDTAG);  //Read the tag number from the reader. Should return a 10 digit serial number
  }

  //This only displays a tag once, unless another tag is scanned
  if(DisplayTAG!=RFIDTAG)
  {
    DisplayTAG=RFIDTAG;
    Serial.println(RFIDTAG);
  }
}

void ReadSerial(String &ReadTagString)
{
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

void LEDColor(int localColor, int duration)
{
  bool led_f= false;

  if(localColor== 0)
  {
    // LED Color = Red
    digitalWrite(RPin, HIGH);
    digitalWrite(GPin, LOW);
    digitalWrite(BPin, LOW);
    Serial.println("LED Color: Red");
    led_f= true;
  }
  else if(localColor== 1)
  {
    // LED Color = Green
    digitalWrite(RPin, LOW);
    digitalWrite(GPin, HIGH);
    digitalWrite(BPin, LOW);
    Serial.println("LED Color: Green");  
    led_f= true;
  }
  else if(localColor== 2)
  {
    // LED Color = Blue      
    digitalWrite(Rpin, LOW);
    digitalWrite(Gpin, LOW);
    digitalWrite(Bpin, HIGH);
    Serial.println("LED Color: Blue");
    led_f= true;
  }
  else if(localColor== 3)
  {
    // LED Color = Orange
    analogWrite(Rpin, 255);
    analogWrite(Gpin, 255);
    analogWrite(Bpin, 51);
    Serial.println("LED Color: Orange");
    led_f= true;
  }
  else if(localColor== 4)
  {
    // LED Color = Yellow
    analogWrite(Rpin, 255);
    analogWrite(Gpin, 153);
    analogWrite(Bpin, 51);
    Serial.println("LED Color: Yellow");
    led_f= true;
  }
  else 
    Serial.println("LED Color: Error");
  
  Serial.print("LED light flag: ");
  Serial.println(led_f);
    
  if(led_f)
  {
    Serial.print("Delay is set for ");
    Serial.print(duration);
    Serial.print(" ms.");
    delay(duration);
  }     
}
// Color intensity Red, Green, Blue, Duration of light
void LEDintensity(int R, int G, int B, int D)
{
  if( (R<0 && R>255) || (G<0 && G>255) || (B<0 && B> 255) )
  {
    Serial.println("Error in one of RGB Value.");
    return;
  }
  else
  {
    analogWrite(RPin, R);
    analogWrite(GPin, G);
    analogWrite(BPin, B);
  }
  Serial.print("Delay is set for ");
  Serial.print(duration);
  Serial.print(" ms.");
  delay(duration);
}
