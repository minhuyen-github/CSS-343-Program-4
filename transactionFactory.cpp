//
//  transactionFactory.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/9/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "transactionFactory.h"

TransactionFactory::TransactionFactory(const string& command, CustomerManager& customers, InventoryManager& inventory) {
    //Initializing temp variables
    Transaction* newTransaction = nullptr;
    
    char transactionType(' '), movieType(' ');
    int IDdummy = 0;
    
    
    stringstream ss;            // string reader
    ss << command;            // getting command line for manipulation and analyzation
    ss >> transactionType;        // getting transaction type
    
    if (transactionType == 'B' || transactionType == 'R') //If its a borrow or return transaction
    {
        ss >> IDdummy >> movieType;                            // get additional info
        
        if (movieType != Transaction::DVD)                    // Make sure its correct type of movie
        {
            transactionType = InvalidTransaction::CODE;        // If not, set transaction to invalid transaction code
        }
        
    }
    //string transactionError = "";
    
    switch (transactionType)
    {
        case Inventory::CODE:
            newTransaction = new Inventory(command, customers, inventory);
            break;
            
        case History::CODE:
            newTransaction = new History(command, customers, inventory);
            break;
            
        case Borrow::CODE:
            newTransaction = new Borrow(command, customers, inventory);
            
            break;
            
        case Return::CODE:
            newTransaction = new Return(command, customers, inventory);
            break;
            
        default:
            newTransaction = new InvalidTransaction(command);
            break;
    }
    
    error = newTransaction->getError();
    
    
    delete newTransaction;
}

//---------------------------------- getErrors ------------------------------
// --Returns a string of erros
//---------------------------------------------------------------------------
string TransactionFactory::getErrors() const
{
    return error;
}
