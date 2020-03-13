//
//  show.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef return_h
#define return_h

#include <stdio.h>
#include "transaction.h"

using namespace std;

class Return : public Transaction
{
public:
    Return(const string&, CustomerManager&, InventoryManager&);    //constructor
    ~Return();
    
    static const char CODE = 'R';        // Code to perform return action
};
#endif /* return_h */
