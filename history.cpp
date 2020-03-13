//
//  history.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "history.h"

//------------------------------- Constructor --------------------------------
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
//
//----------------------------------------------------------------------------
History::~History()
{
    //empty on purpose
}
