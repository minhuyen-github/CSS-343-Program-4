// ------------------------------------------------ transaction.cpp -------------------------------------------------------

// Name: Uyen Hoang, Max Nguyen
// CSS 343 Section C

// Creation Date: 3/9/2020

// Date of Last Modification: 3/14/2020

// --------------------------------------------------------------------------------------------------------------------

// This program is the implementation file (.cpp) that implements the parent class for all transactions

// -------------------------------------------------------------------------------------------------------------------- 
#include "transaction.h"

// ----------------------------------- default constructor ---------------------------------------------- 

// Description

// default constructor: initialize an empty string for error

// preconditions: none
// postconditions: an empty string for error

// ----------------------------------------------------------------------------------------------------- 
Transaction::Transaction()
{
    newError = "";
}

// --------------------------------------- destructor -------------------------------------------------- 

// Description

// destructor: virtual

// preconditions: none
// postconditions: none

// ----------------------------------------------------------------------------------------------------- 
Transaction::~Transaction()
{
    //empty on purpose
}

// --------------------------------------- getError -------------------------------------------------- 

// Description

// getError: Return the new error

// preconditions: none
// postconditions: the error found

// ----------------------------------------------------------------------------------------------------- 
string Transaction::getError() const
{
    return newError;
}

