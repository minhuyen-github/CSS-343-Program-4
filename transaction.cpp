//
//  transaction.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "transaction.h"

Transaction::Transaction()
{
    newError = "";
}

Transaction::~Transaction()
{
    //empty on purpose
}

string Transaction::getError() const
{
    return newError;
}

