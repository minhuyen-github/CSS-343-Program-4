//
//  inventory.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/13/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef inventory_h
#define inventory_h

#include <stdio.h>
#include "transaction.h"

class Inventory : public Transaction
{
public:
    Inventory(const string&, CustomerManager&, InventoryManager&);        // Constructor
    ~Inventory();                                                // Destructor
    
    static const char CODE = 'I';        // Code to do display all movie, aka inventory
};
#endif /* inventory_h */
