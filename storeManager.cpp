//
//  storeManager.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/13/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "storeManager.h"
#include <string>
#include <iostream>
#include <fstream>

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

//----------------------------- buildStore ----------------------------------
// --Processes inventory file(movieFile) and customer file(customerFile)
//---------------------------------------------------------------------------
void StoreManager::buildStore(ifstream& movie, ifstream& customer)
{
    allInventory.processInventory(movie);
    allCustomers.processCustomers(customer);
}

//------------------------------ readCommands -------------------------------
// --Processes transaction commmands file (commands)
//---------------------------------------------------------------------------
void StoreManager::readCommands(ifstream& commands)
{
    allTransactions.readCommands(commands, allCustomers, allInventory);
}
