#include "invalidTransaction.h"

//------------------------------- Constructor --------------------------------
// Description: This is the default constructor.
// Post-condition: Print out invalid transaction to the output screen.
//----------------------------------------------------------------------------
InvalidTransaction::InvalidTransaction(const string& command)
{
    if (command != "")
    {
        newError = "ERROR:   " + command + " is an invalid transaction";
    }
}

//---------------------------- Destructor ------------------------------------
// Description: This is the destructor
//----------------------------------------------------------------------------
InvalidTransaction::~InvalidTransaction()
{
    //empty on purpose
}
