// ------------------------------------------------ history.h -------------------------------------------------------

// Name: Uyen Hoang, Max Nguyen
// CSS 343 Section C

// Creation Date: 3/9/2020

// Date of Last Modification: 3/14/2020

// --------------------------------------------------------------------------------------------------------------------

// This program is the implentation file (.cpp) that stores the borrowed history of customers

// -------------------------------------------------------------------------------------------------------------------- 
#include "history.h"

//-------------------------------------------- Constructor ---------------------------------------------

// Description: Take in customer ID and print out that customer's history

// ----------------------------------------------------------------------------------------------------- 
History::History(const string& command, CustomerManager& customers, InventoryManager& inventory)
{
    char code;
    int customer_id;                // hold customer id
    Customer* customer = nullptr;    // hold pointer to the object customer
    
    stringstream ss;                   // string reader
    ss << command;                 // insert string into reader
    
    ss >> code >> customer_id;        // extract the code and the customer ID
    customer = customers.getCustomer(customer_id);     // get pointer to the customer
    
    if (customer == nullptr)        // check if customer exist
    {
        newError = "ERROR:   " + to_string(customer_id) + " is not in the customer Database";
    }
    else
    {
        customer->printHistory();   // if so, print customer history
    }
}

//------------------------------- Destructor ---------------------------------

// Description: virtual

//----------------------------------------------------------------------------
History::~History()
{
    //empty on purpose
}
