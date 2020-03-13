//
//  borrow.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef borrow_h
#define borrow_h

#include <stdio.h>
#include "transaction.h"

using namespace std;

class Borrow : public Transaction
{
public:
    Borrow(const string&, CustomerManager&, InventoryManager&);    // constructor
    ~Borrow();                                                // destructor
    
    static const char CODE = 'B';        // Code to perform borrow action
};
#endif /* borrow_h */
