/*  
  IEEE_RFID_Reader
  
  ID Card scanning system intended for system logins.
  
  Version:
    0.01
  
  Authors:
    - Watson Tungjunyatham
    - Jaehoon Hwang
    - Conor Swezey
    - Daniel Irvin
    
  For all changes, details, bugs, grumbles, and everything else,
  please check out our very own (and shiny!) Github.
  
  https://github.com/starrodkirby86/IEEE_RFID_Reader
  
  We want YOU to help! Unless you're a Somalian pirate. Just
  kidding, we're an Equal Opportunities employer.
  
*/

// ==============================================
// INCLUDE AND CONSTANT DEFINITIONS
// ============================================== 

#include <SoftwareSerial.h>
#include "IDDatabase.h"

// Parallax RFID Reader
#define RFIDEnablePin 2        // Pin for reading
#define RFIDSerialRate 2400    // Port Speed

// SoftwareSerial Library
#define RxPin 5                // Pin for reading data from the Reader
#define TxPin 4                // Pin for writing data to the Reader (unused)

// LED Pins
#define RPin 11
#define GPin 10
#define BPin 9
#define RGB_R 0
#define RGB_G 1
#define RGB_B 2
#define RGB_O 3
#define RGB_Y 4

void setup()
{
  Serial.begin(9600);  // Create serial, baud rate is 9600bps
  Serial.println("Get this started!");
  
  Serial.println("ID Test");
  Serial.println("");
  ID pikachu("1A3C9D00BB","Barack Obama");
  pikachu.printID(&Serial);
  
  Serial.println("");
  Serial.println("Database Test");
  Serial.println("");
  
  IDDatabase database(&Serial);
  database.addID("56U8M9A3XY","Switches Be Trippin");
  database.addID("11112222M4","Mister Rogers");
  database.addID("MK69CC22AB","Carl Sagan");
  database.addID("9302573823","Austin Powers");
  database.print();
  
  Serial.println("");
  Serial.println("Removing Mister Rogers.");
  Serial.println("");
  database.eraseID("11112222M4");
  database.print();
  
  Serial.println("");
  Serial.println("Editing Carl Sagan.");
  Serial.println("");
  database.editID("MK69CC22AB","AAAABBBBCC","Neil deGrasse Tyson");
  database.print();

  Serial.println("");
  Serial.println("Adding more IDs.");
  Serial.println("");
  database.addID("XY88Z00001","Donkey Kong");
  database.addID("24601A1862","Jean Valjean");
  database.addID("JJJAAAEEEH","Malcolm X");
  database.addID("HEEEAAAJJJ","X mloclaM");
  database.print();  
  
  Serial.println("");
  Serial.println("Does Donkey Kong exist?");
  Serial.println("");
  if(database.isThere("XY77Z00001"))
  {    
    Serial.print("Yes! ");
    Serial.print(database.getOwner(database.find("XY77Z00001")));
    Serial.println(" does exist!");
  }
  else
  {
    Serial.println("Sorry, he doesn't exist. :(");
  }
  
  Serial.println("");
  Serial.println("Does Carl Sagan exist?");
  Serial.println("");
  if(database.isThere("MK69CC22AB"))
  {    
    Serial.print("Yes! ");
    Serial.print(database.getOwner(database.find("MK69CC22AB")));
    Serial.println(" does exist!");
  }
  else
  {
    Serial.println("Sorry, he doesn't exist. :(");
  }
  
  Serial.println("");
  Serial.print("Did you know? Our database is ");
  Serial.print(database.getSize());
  Serial.print(" elements long!");
  Serial.println("");

}

void loop()
{
}
