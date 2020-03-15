

#ifndef return_h
#define return_h

#include <stdio.h>
#include "transaction.h"

using namespace std;

//------------------------------ Return -------------------------------------------
// Purpose: This is a class to return movies.
// Notes: This class inherits from Transaction class
//---------------------------------------------------------------------------
class Return : public Transaction
{
public:
    Return(const string&, CustomerManager&, InventoryManager&);    //constructor
    ~Return();
    
    static const char CODE = 'R';        // Code to perform return action
};
#endif /* return_h */
