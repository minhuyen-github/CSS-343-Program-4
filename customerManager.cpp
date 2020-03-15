#include "customerManager.h"

//-------------------------- Constructor ----------------------------
// Description: This is the default constructor for the class
//---------------------------------------------------------------------------
CustomerManager::CustomerManager()
{
    //empty on purpose
}

//----------------------------- Destructor ----------------------------------
// Description: This is the destructor for the class
//---------------------------------------------------------------------------
CustomerManager::~CustomerManager()
{
    //empty on purpose
}

//--------------------------- processCustomers -------------------------------
// Description: This function takes in a valid file of customer data where each
//              line is in the format: int ID, string LastName, string firstName
//              and add that data into the customer database.
// Pre-condition: The file must be valid.
// Post-condition: Creates customer objects with the specified data and adds them to
//                 the customer database (i.e the HashTable : tableOfCustomers)
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
// Description: This function retreives a customer from the customer database
//              given a unique ID.
// Post-condition: Returns a pointer to the customer object in the hash table
//----------------------------------------------------------------------------
Customer* CustomerManager::getCustomer(int id)
{
    
    //search customer storage for the customer pointer
    return customers.retrieveCustomer(id);
}
