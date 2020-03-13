//
//  store.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/9/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "customerManager.h"

//-------------------------- Default Constructor ----------------------------
//
//---------------------------------------------------------------------------
CustomerManager::CustomerManager()
{
    //empty on purpose
}

//----------------------------- Destructor ----------------------------------
//
//---------------------------------------------------------------------------
CustomerManager::~CustomerManager()
{
    //empty on purpose
}

//--------------------------- processCustomers -------------------------------
// --Function: processCustomers
// --Param:
//      --customerFile is a valid file of customer data where each
//        line is in the format: int ID, string LastName, string firstName
//
// --Post-condition:
//      --Creates customer objects with the specified data and adds them to
//        the customer Database (i.e the HashTable : tableOfCustomers)
//----------------------------------------------------------------------------
void CustomerManager::processCustomers(ifstream& file)
{
    int fileID;
    string lastName, firstName;
    
    while (!file.eof())        // until end of file
    {
        file >> fileID >> lastName >> firstName;    // get Info
        
        //Then add to storage:
        customers.addCustomer(new Customer(fileID, lastName, firstName));
        
    }
    
}

//------------------------------ getCustomer ----------------------------------
// --Function: getCustomer retreives the customer from the customerStorage
//               hash table
// --Param:
//      --int is the ID of the customer wished to be retreived
// --Post-condition:
//      --Returns a pointer to the customer in customerStorage
//----------------------------------------------------------------------------
Customer* CustomerManager::getCustomer(int id)
{
    
    //search customer storage for the customer pointer
    return customers.retrieveCustomer(id);
}
