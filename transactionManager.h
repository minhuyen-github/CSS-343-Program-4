//
//  transactionManager.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/13/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef transactionManager_h
#define transactionManager_h

#include <stdio.h>
#include <string>
#include <algorithm>
#include "inventoryManager.h"
#include  "customerManager.h"
#include "transactionFactory.h"

//------------------------- class TransactionManager ------------------------
// Purpose:
//     -- Transaction Manager Processes the transaction file
//---------------------------------------------------------------------------
class TransactionManager
{
public:
    TransactionManager();
    virtual ~TransactionManager();
    void readCommands(ifstream&, CustomerManager&, InventoryManager&);    // read commands
    
private:
    vector<string> error;
};
#endif /* transactionManager_h */
