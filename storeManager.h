//
//  storeManager.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/13/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef storeManager_h
#define storeManager_h

#include <stdio.h>

#include <string>
#include <iostream>
#include <fstream>
#include "customerManager.h"
#include "inventoryManager.h"
#include "transactionManager.h"

//--------------------------  class StoreManager ----------------------------
// Purpose:
//   -- Store Manager class: high level manager for other manager
//      classes such as: CustomerManager, InventoryManager, ComandLoaderManager.
//
// Implementation and assumptions:
//   -- Implement as a manager class
//   -- Implement with following futures:
//      buildStore, readCommands
//---------------------------------------------------------------------------
class StoreManager
{
public:
    
    void buildStore(ifstream&, ifstream&);               // build store by creating movie and customer base
    void readCommands(ifstream&);                      // proccess commands lines
    
private:
    CustomerManager allCustomers;                     // Customer manager object
    InventoryManager allInventory;                   // Inventroy manager object
    TransactionManager allTransactions;                         // comands  manager object
};

#endif /* storeManager_h */
