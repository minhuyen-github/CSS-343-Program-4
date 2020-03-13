//
//  transaction.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef transaction_h
#define transaction_h

#include "customerManager.h"
#include "inventoryManager.h"

//-------------------------------- class Transaction ------------------------
// Purpose: This is the parent class for all transactions
//---------------------------------------------------------------------------

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
