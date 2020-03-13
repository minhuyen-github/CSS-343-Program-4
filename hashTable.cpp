//
//  hashTable.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "hashTable.h"

//------------------------------- Default Constructor ------------------------
// --Default Constructor
// --Param: N/A
// --Post-condition:
//      --Fills the table with nullptrs
//----------------------------------------------------------------------------
HashTable::HashTable()
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLUMNS; c++)
        {
            customerTable[r][c] = nullptr;            //Initializing Table to Null
        }
    }
    
}

//-------------------------------- Destructor --------------------------------
// --Default Constructor:
// --Param: N/A
// --Post-condition:
//      --Deallocates memory by deleating any existing pointers and setting
//        all table values to nullptr
//----------------------------------------------------------------------------
HashTable::~HashTable()
{
    for (int r = 0; r < ROWS; r++)    // traversing all rows
    {
        for (int c = 0; c < COLUMNS; c++)// traversing all columns
        {
            if (customerTable[r][c] != nullptr) // if a pointer exists
            {
                delete customerTable[r][c];            // delete pointer
                customerTable[r][c] = nullptr;            // setting table spot back to null
            }
        }
    }
}

//---------------------------- addCustomerToHash -----------------------------
// --Function: addCustomertoDatabase
// --Param:
//      --The newCustomer to be added has non-empty strings and a customer ID >= 0
// --Post-condition:
//      --The customer is added to the Hash table at the location
//        [iSquared + ID % Rows][iSquared + ID % COLUMNS]
//        where I= the number of 'hit' in the table
//        and ROWS and COLUMNS are the prime numbers 101 and 199
//        respectively, generating space for 20099 possible ID's
//----------------------------------------------------------------------------

bool HashTable::addCustomer(Customer* customer)
{
    int ID = customer->getID();
    unsigned int i = 0;
    bool done = false;
    
    if (ID < 0 || customer->getFullName() == " ") //if it is default customer = invalid input
    {
        return done;
    }
    
    
    while (!done && i < 9999) //Hash algorithm: [iSquared + ID % Rows][iSquared + ID % COLUMNS]
    {
        unsigned long int iSquared = i * i;
        
        //IF table of customers is empty: fill with newCustomer
        if (customerTable[(iSquared + ID) % ROWS][(iSquared + ID) % COLUMNS] == nullptr)
        {
            customerTable[(iSquared + ID) % ROWS][(iSquared + ID) % COLUMNS] = customer;
            done = true;
            return done;
        }
        
        //IF table of customers has the same customer, we are done
        if (customerTable[(iSquared + ID) % ROWS][(iSquared + ID) % COLUMNS] == customer)
        {
            done = true;
            return done;
        }
        
        //ELSE: table of customers is already full at location
        //at this point newCustomer has not been added to hash
        
        i++;        //increment i by +1 and retry
    }
    
    return done;
}

//------------------------------ removeCustomer ------------------------------
// --Function: removeCustomer
// --Param:
//      --existingID is the ID of the customer to be removed
// --Post-condition:
//      --If the customer exists in the table A pointer to the customer is
//        returned. If the customer does not exist then nullptr is returned.
//----------------------------------------------------------------------------
bool HashTable::removeCustomer(const int& ID)
{
    unsigned int i = 0;
    bool done = false;
    Customer* temp = nullptr;
    
    while (!done && i < 9999)
    {
        unsigned long int iSquared = i * i;
        
        if (customerTable[(iSquared + ID) % ROWS][(iSquared + ID) % COLUMNS] == nullptr)
        {
            return done; //customer does not exist
        }
        
        //Customer Exists in Table
        temp = customerTable[(iSquared + ID) % ROWS][(iSquared + ID) % COLUMNS];
        
        //If it's a match:
        if (temp->getID() == ID)
        { //if ID's Match then we are done
            delete customerTable[(iSquared + ID) % ROWS][(iSquared + ID) % COLUMNS];
            customerTable[(iSquared + ID) % ROWS][(iSquared + ID) % COLUMNS] = nullptr;
            done = true;
            return done;
        }
        
        //Else: increment i by 1 and try again
        i++;
    }
    
    return done; //Customer was never found
}

//-------------------------- retrieveCustomer --------------------------------
// --Function: retrieveCustomer
// --Param:
//      --Existing ID is the ID of the customer to be retrieved
// --Post-condition:
//      --If the customer exists in the table A pointer to the customer is
//        returned. If the customer does not exist then nullptr is returned.
//----------------------------------------------------------------------------
Customer* HashTable::retrieveCustomer(const int& ID)const
{
    unsigned int i = 0;
    bool done = false;
    Customer* temp = nullptr;
    
    while (!done && i < 9999)
    {
        unsigned long int iSquared = i * i;
        
        temp = customerTable[(iSquared + ID) % ROWS][(iSquared + ID) % COLUMNS];
        
        
        /*    int currentID = temp->getIDNum();*/
        
        if (temp != nullptr && temp->getID() == ID)
        { //if ID's Match then we are done
            done = true;
        }
        
        i++;
    }
    
    return temp;
    
}
