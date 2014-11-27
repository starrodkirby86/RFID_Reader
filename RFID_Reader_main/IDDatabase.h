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

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <HardwareSerial.h>
#include "LinkedList.h"

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
            IDNumber = "XXXXXXXXXX";
            IDOwner  = "I AM ERROR";
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
    // EDIT FUNCTIONS
    // ==============================================    
        void editID(String arg_IDNumber, String arg_IDOwner)
        {
            IDNumber = arg_IDNumber;
            IDOwner  = arg_IDOwner;
        }
        
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
            
            if((!isIDBlank()) && (!isOwnerBlank()))
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


class IDDatabase
{
    // This is the class for a database of IDs.
    
    // ==============================================
    // PROPERTIES
    // ============================================== 
    
    private:
        LinkedList<ID> database;
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

    // ==============================================
    // ELEMENT MANIPULATION FUNCTIONS
    // ============================================== 
    
        void addID(String arg_IDNumber, String arg_IDOwner)
        {
            // Adds an ID into the database (push into the tail).
            // It's up to your responsibility to make sure that
            // the content added in isn't a duplicate or anything funny...
            
            // Temporarily create a new ID to insert into the vector.
            ID newID(arg_IDNumber, arg_IDOwner);
            
            database.add(newID);
            
        }
        
        ID eraseID(String arg_searchID)
        {
            // Erases an ID from the database.
            // The erased ID will be returned. It's up to the user
            // if they want to keep that ID.
            // Search criteria is based on ID Number.
            
            if(isEmpty())
            {
                _Serial->println("ERROR: Empty database. Can't remove what doesn't exist!");
                ID errorID("ERROR_01","EMPTY DATABASE");
                return(errorID);
            }   
            else
            {
            
                int searchIndex = find(arg_searchID);
                if(searchIndex != -1)
                    return(database.remove(searchIndex));
                else
                {
                    // Search was unsuccessful at this case
                    _Serial->println("ERROR: ID doesn't exist. Did you spell it right?");
                    ID errorID("ERROR_02","SEARCH NOT SUCCESSFUL");
                    return(errorID);
                }
            }
            

        }
        
        ID eraseID(int arg_index)
        {
            // Erases an ID from the database.
            // Unlike the previous function, this one
            // will erase a specific ID from the database
            // based on the index.
            // This attempts to be a more precise deletion
            // or even a mass clearing.
            
            // NOTE: For mass cleaning,
            // just let it pop the head.
            
            if(isInRange(arg_index)) // Out of range check
            {
                _Serial->println("ERROR: Index out of range.");
                ID errorID("ERROR_01","OUT_OF_RANGE");
                return(errorID);
            }
            else
            {
                return(database.remove(arg_index));
            }
        }
        
        void editID(String arg_searchID, String arg_IDNumber, String arg_IDOwner)
        {
            // Edits an ID in the database.
            // Searches for the ID to exist, then modifies it.
            
            int searchIndex = find(arg_searchID);
            if(searchIndex != -1)
            {
                database.get(searchIndex).editID(arg_IDNumber,arg_IDOwner);   // What does it do when found?
                return;
            }
            else
                _Serial->println("ERROR: Cannot find ID. Did you spell it correctly?");

        }
        
    // ==============================================
    // COMPARATOR FUNCTIONS
    // ============================================== 
    
        // Use this for codes, it's easier and more intuitive
        // to read at a glance (at least for simple Boolean cases)
        bool isThere(String arg_searchID)   { return (find(arg_searchID) != -1);  }        
        bool isInRange(int arg_index) { return (arg_index >= getSize() || arg_index < 0); }
    
        int find(String arg_searchID)
        {
            // Finds the index of an ID in the database.
            // Search criteria is based off of an ID string.
            
            for(int i = 0; i < getSize(); ++i)
            {
                if(arg_searchID == (database.get(i)).getID())    // Checks if found
                    return(i);  // Returns the corresponding index
            }
            
            // Error case
            return(-1);
        }
        
    // ==============================================
    // GET FUNCTIONS
    // ============================================== 
    
        int getSize()       { return database.size() ; }
        bool isEmpty()      { return (getSize() == 0); }
        
        String getID(int arg_index)
        {
            if(isInRange(arg_index))
                return (database.get(arg_index)).getID();
            else
            {
                _Serial->println("ERROR: Index out of range.");
                return "OUT OF RANGE";
            }
        }
        
        String getOwner(int arg_index)
        {
            if(isInRange(arg_index))
                return (database.get(arg_index)).getOwner();
            else
            {
                _Serial->println("ERROR: Index out of range.");
                return "OUT OF RANGE";
            }
        }
        
 
    // ==============================================
    // OTHER FUNCTIONS
    // ==============================================  
        void print()
        {
            // Print time...
            if(isEmpty())
                _Serial->println("ERROR: Empty database. Please add IDs!");
            else
                {
                    ID tempID();
                    for(int i = 0; i < getSize(); ++i)  // Traveler
                    {
                        (database.get(i)).printID(_Serial);   // Grab the current iteration for printing
                    }
                }
        }
    
};


#endif
