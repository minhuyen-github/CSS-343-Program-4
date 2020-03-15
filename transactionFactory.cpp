// ------------------------------------------------ transactionFactory.cpp ---------------------------------------------

// Name: Uyen Hoang, Max Nguyen
// CSS 343 Section C

// Creation Date: 3/9/2020

// Date of Last Modification: 3/14/2020

// --------------------------------------------------------------------------------------------------------------------

// This program is the implementation file (.cpp) that creates a class TransactionFactory to determine
// the type of transaction to be executed

// -------------------------------------------------------------------------------------------------------------------- 
#include "transactionFactory.h"

// ----------------------------------- constructor ---------------------------------------------- 

// Description

// constructor: Processes the transactions. Validate if transactionType, ID, and movieType are valid. 
//              If they are valid, continue processing according to its transactionType. 
//              If not, print out the error messages.

// preconditions: transaction
// postconditions: continue processing according to the appropriate transactionType

// ----------------------------------------------------------------------------------------------------- 
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
// --Returns a string of errors
//---------------------------------------------------------------------------
string TransactionFactory::getErrors() const
{
    return error;
}
