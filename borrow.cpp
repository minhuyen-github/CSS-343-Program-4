//
//  borrow.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "borrow.h"

// -------------------------- Constructor -------------------------------------
Borrow::Borrow(const string& comm, CustomerManager& theManagers, InventoryManager& inventory)
{
    char code;
    int customerID;
    string movieType;
    stringstream ss;
    
    
    ss << comm;                                // getting command line for manipulation
    ss >> code >> customerID >> movieType;            // extracting needed information
    
    string remainder(ss.str().substr(ss.tellg()));    // getting the remaining information
    
    
    Movie* moviePtr = inventory.retrieveMovie(remainder); // checking if in inventory
    
    
    
    if (moviePtr == nullptr)                    // if not in inventorys end to error collection
    {
        newError = "ERROR:   Sorry " + remainder + " could not be found in the inventory";
        return;
    }
    
    Customer* customer = theManagers.getCustomer(customerID); // check if customer exists
    
    if (customer == nullptr)                // if not in inventory send to error collection
    {
        newError = "ERROR:   Sorry there are no customers with ID #" + to_string(customerID);
        return;
    }
    
    
    
    //both customer and the movie exist in store databases
    if (moviePtr->decreaseStock()) // check if stock > 0
    {
        customer->newTrans(CODE, moviePtr);    // send transaction to customerHistory
    }
    else if (remainder[1] == 'C') // just for Classic movies; stock for prefered choice was 0
    {
        Movie* altClassic = nullptr;
        altClassic = inventory.retrieveClassicMovie(moviePtr); // check if Store has same movie, but different major actor
        
        if (altClassic != nullptr && altClassic->decreaseStock()) // check if movie exsists and stock > 0
        {
            customer->newTrans(CODE, altClassic); // send transaction to customerHistory
        }
        else
        {
            newError = "ERROR:   Customer " + customer->getFullName() + " ID: " + customer->displayID() + ": Sorry" + remainder + "  stock was 0";
            return;
        }
    }
    else
    {
        
        newError = "ERROR: Customer " + customer->getFullName() + " ID: " + customer->displayID() + ": Sorry" + remainder + " the stock was 0";
    }
    
}

// ---------------------------- Destructor ------------------------------------
//
//-----------------------------------------------------------------------------
Borrow::~Borrow()
{
    //empty on purpose
}
