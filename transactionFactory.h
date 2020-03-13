//
//  transactionFactory.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/9/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef transactionFactory_h
#define transactionFactory_h
#include "customerManager.h"
#include "inventoryManager.h"
#include "transaction.h"
#include "inventory.h"
#include "history.h"
#include "borrow.h"
#include "return.h"
#include "invalidTransaction.h"

//-------------------------- class TransactionFactory -----------------------
// Purpose:
//     -- Transaction Factory determines the type of transaction to be executed
//---------------------------------------------------------------------------

class TransactionFactory
{
public:
    TransactionFactory(const string&, CustomerManager&, InventoryManager&); // constructor
    string getErrors() const;
private:
    string error;
};
#endif /* transactionFactory_h */
