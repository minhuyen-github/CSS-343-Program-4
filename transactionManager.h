#ifndef transactionManager_h
#define transactionManager_h

#include <stdio.h>
#include <string>
#include <algorithm>
#include "inventoryManager.h"
#include  "customerManager.h"
#include "transactionFactory.h"

//------------------------- class TransactionManager ------------------------
// Purpose: This class processes the movie and customer file
//---------------------------------------------------------------------------
class TransactionManager
{
public:
    TransactionManager();                           // constructor
    virtual ~TransactionManager();                  //destructor
    void readCommands(ifstream&, CustomerManager&, InventoryManager&); // read commands from movie and customer file
    
private:
    vector<string> error;                           //store all transaction errors
};
#endif /* transactionManager_h */
