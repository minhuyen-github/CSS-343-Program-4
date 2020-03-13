//
//  history.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef history_h
#define history_h

#include "transaction.h"

class History : public Transaction
{
public:
    History(const string&, CustomerManager&, InventoryManager&); // Constructor
    ~History();                                             // Destructor
    
    static const char CODE = 'H';    //Code to display a customer's history
};

#endif /* history_h */
