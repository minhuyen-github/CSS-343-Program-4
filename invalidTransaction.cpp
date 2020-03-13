//
//  invalidTransaction.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/13/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "invalidTransaction.h"

InvalidTransaction::InvalidTransaction(const string& command)
{
    if (command != "")
    {
        newError = "ERROR:   " + command + " is an invalid transaction";
    }
    
}

//---------------------------- Destructor ------------------------------------
//
//----------------------------------------------------------------------------
InvalidTransaction::~InvalidTransaction()
{
    //empty on purpose
}
