// ------------------------------------------------ transactionFactory.h -------------------------------------------------------

// Name: Uyen Hoang, Max Nguyen
// CSS 343 Section C

// Creation Date: 3/9/2020

// Date of Last Modification: 3/14/2020

// --------------------------------------------------------------------------------------------------------------------

// This program is the header file (.h) that creates a class TransactionFactory to determine
// the type of transaction to be executed

// -------------------------------------------------------------------------------------------------------------------- 
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

class TransactionFactory
{
public:
    TransactionFactory(const string&, CustomerManager&, InventoryManager&); // constructor
    string getErrors() const;   // return a string of errors
private:
    string error;
};
#endif 
