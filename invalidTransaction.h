
#ifndef invalidTransaction_h
#define invalidTransaction_h

#include <stdio.h>
#include "transaction.h"

//--------------------------- class InvalidTransaction -----------------------
// Purpose: This class handele invalid transactions.
// Note: This class inherit from Transaction class.
//----------------------------------------------------------------------------
class InvalidTransaction : public Transaction
{
public:
    InvalidTransaction(const string&); //constructor
    ~InvalidTransaction();             // destructor
    
    static const char CODE = 'X';    //The general code for invalid transaction command
};

#endif /* invalidTransaction_h */
