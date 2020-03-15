#include "storeManager.h"
#include <string>
#include <iostream>
#include <fstream>

//----------------------------- buildStore ----------------------------------
// Description: This function processes movie file and customer file by using
//              methods from class InventoryManager and CustomerManager
//---------------------------------------------------------------------------
void StoreManager::buildStore(ifstream& movie, ifstream& customer)
{
    allInventory.processInventory(movie);
    allCustomers.processCustomers(customer);
}

//------------------------------ readCommands -------------------------------
// Description: This function processes transaction commmands file by using
//              methods from class TransactionManager.
//---------------------------------------------------------------------------
void StoreManager::readCommands(ifstream& commands)
{
    allTransactions.readCommands(commands, allCustomers, allInventory);
}
