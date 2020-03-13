//
//  show.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "return.h"

//------------------------------- Constructor --------------------------------
Return::Return(const string& command, CustomerManager& customers, InventoryManager& inventory)
{
    stringstream ss;
    ss << command;    // inserting commandLine into
    
    char code;
    int customerID;
    string movieType;
    
    ss >> code >> customerID >> movieType;            // getting values to use for processing
    
    string remainder(ss.str().substr(ss.tellg()));    // getting the rest for movie retreival
    
    Movie* moviePtr = inventory.retrieveMovie(remainder);        // search inventory for movie
    
    if (moviePtr == nullptr) //if movie does not exist
    {
        newError = "ERROR:   Sorry " + remainder + " could not be found in the inventory";
        return;
    }
    
    Customer* customer = customers.getCustomer(customerID);    // search database for customer
    if (customer == nullptr) // if customer ID could not be found
    {
        newError = "ERROR:   Sorry there are no customers with ID #" + to_string(customerID);
        return;
    }
    
    if (customer->checkReturn(moviePtr))
    {
        customer->newTrans(CODE, moviePtr);
        moviePtr->increaseStock();
    }
    else if (remainder[1] == 'C') // just for Classic movies; stock for prefered choice was 0
    {
        Movie* altClassic = nullptr;
        altClassic = inventory.retrieveClassicMovie(moviePtr); // check if Store has same movie, but different major actor
        
        if (altClassic != nullptr && customer->checkReturn(altClassic)) // check if movie exsists and stock > 0
        {
            customer->newTrans(CODE, altClassic); // send transaction to customerHistory
            altClassic->increaseStock();
        }
        else
        {
            newError = "ERROR:   The customer " + customer->getFullName() + " ID:" + to_string(customerID) + " did not borrow " + remainder;
        }
    }
    else // customer never borrrowed movie
    {
        newError = "ERROR:   The customer " + customer->getFullName() + " ID:" + to_string(customerID) + " did not borrow " + remainder;
    }
    
    
}

//------------------------------ Destructor ----------------------------------
//
//----------------------------------------------------------------------------
Return::~Return()
{
    //empty on purpose
}
