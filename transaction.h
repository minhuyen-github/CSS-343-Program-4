// ------------------------------------------------ transaction.h -------------------------------------------------------

// Name: Uyen Hoang, Max Nguyen
// CSS 343 Section C

// Creation Date: 3/9/2020

// Date of Last Modification: 3/14/2020

// --------------------------------------------------------------------------------------------------------------------

// This program is the header file (.h) that implements the parent class for all transactions

// -------------------------------------------------------------------------------------------------------------------- 
#ifndef transaction_h
#define transaction_h

#include "customerManager.h"
#include "inventoryManager.h"

//-------------------------------- class Transaction ------------------------------------------------------
class Transaction
{
public:
    Transaction();                // constructor: necessary for inheritance
    virtual ~Transaction();        // virtual desrtuctor
    
    static const char DVD = 'D';    // All transactions are for DVD's
    string getError() const;
    
protected:
    string newError;
};

#endif /* transaction_h */
