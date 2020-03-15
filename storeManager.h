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
// Purpose: This class is a high level manager class for other manager
//      classes such as: CustomerManager, InventoryManager, and TransactionManager.
//---------------------------------------------------------------------------
class StoreManager
{
public:
    
    void buildStore(ifstream&, ifstream&);              // build store by creating movie and customer database
    void readCommands(ifstream&);                      // proccess command lines
    
private:
    CustomerManager allCustomers;                     // CustomerManager object
    InventoryManager allInventory;                   // InventoryManager object
    TransactionManager allTransactions;               //TransactionManager object
};

#endif /* storeManager_h */
