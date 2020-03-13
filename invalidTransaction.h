//
//  invalidTransaction.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/13/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef invalidTransaction_h
#define invalidTransaction_h

#include <stdio.h>
#include "transaction.h"

class InvalidTransaction : public Transaction
{
public:
    InvalidTransaction(const string&); //constructor
    ~InvalidTransaction();                                             // destructor
    
    static const char CODE = 'X';    //The general code for invalid transaction command
};

#endif /* invalidTransaction_h */
