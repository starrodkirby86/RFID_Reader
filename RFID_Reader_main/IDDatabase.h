/*
    IDDatabase.h
    
    This class is the basic framework of the RFID cards. You can manipulate various RFID-related stuff with this class...
    
    Version:
        0.dongerz
    Authors:
        Watson Tungjunyatham
        
*/

#ifndef _IDDATABASE_H_
#define _IDDATABASE_H_

#include <SoftwareSerial.h>
#include <HardwareSerial.h>

class ID
{
    // This is the class for an individual ID.
    
    // ==============================================
    // PROPERTIES
    // ============================================== 
    
        private:
            String IDNumber;    // The ID Number.           e.g. 06008F6747
            String IDOwner;     // The Owner of the ID.     e.g. Kim Jong Un
            
        public:
       
    // ==============================================
    // CLASS CONSTRUCTORS
    // ==============================================
        
        ID(String arg_IDNumber, String arg_IDOwner)
        {
            // Constructor for ID class when both
            // arguments are given. (Ideally)
            IDNumber = arg_IDNumber; 
            IDOwner  =  arg_IDOwner;
        }
        
        ID(String arg_IDNumber)
        {
            // Constructor for ID class when
            // ONLY ID number is given.
            IDNumber = arg_IDNumber;
            IDOwner  = "Unknown";
        }
        
        ID()
        {
            // Constructor for no arguments
            // You shouldn't really stumble upon this...
            IDNumber = "1234567890";
            IDOwner  = "Foo Fighter";
        }    

    // ==============================================
    // FUNCTIONS
    // ============================================== 
    
    // ==============================================
    // GET FUNCTIONS
    // ==============================================
    
        String getID()      { return IDNumber; }
        String getOwner()   { return IDOwner; }

    // ==============================================
    // OTHER FUNCTIONS
    // ==============================================
    
        // Boolean checks
        bool isIDBlank()    { return (IDNumber == NULL); }
        bool isOwnerBlank() { return (IDOwner == NULL);  }
        
        void printID(HardwareSerial *serIn)
        {
            // Display ID and owner in a simple Serial print.
            // If the components are blank, display an error
            // message instead.
            
            // Uses the Serial, so the Serial must be
            // communicated with this function.
            HardwareSerial *_Serial;
            _Serial = serIn;
            
            if((isIDBlank()) && (isOwnerBlank()))
            {
                _Serial->print("ID: ");
                _Serial->println(IDNumber);
                _Serial->print("OWNER: ");
                _Serial->println(IDOwner);
            }
            else
            {
                _Serial->println("ERROR: Null ID or Owner.");
            }
        }
    
};

/*
class IDDatabase
{
    // This is the class for a database of IDs.
    
    // ==============================================
    // PROPERTIES
    // ============================================== 
    
    private:
        vector<ID> database;
        HardwareSerial *_Serial;
    
    public:
    
    // ==============================================
    // CLASS CONSTRUCTORS
    // ==============================================
    
        IDDatabase(HardwareSerial *serIn)
        {
            // Constructor a database.
            // Initially starts empty, with only a Serial
            // to communicate with.
            _Serial = serIn;
        }
    // ==============================================
    // FUNCTIONS
    // ==============================================     
    
        void addID(String arg_IDNumber, String arg_IDOwner)
        {
            // Adds an ID into the database.
            // It's up to your responsibility to make sure that
            // the content added in isn't a duplicate or anything funny...
            
        }
    
}
*/

#endif
