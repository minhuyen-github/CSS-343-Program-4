//
//  inventory.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/13/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "inventory.h"

//------------------------------- Constructor --------------------------------
Inventory::Inventory(const string& command, CustomerManager& customers, InventoryManager& inventory)
{
    inventory.display(); // ask inventory manager to display all
}

//----------------------------- Destructor -----------------------------------
//
//----------------------------------------------------------------------------
Inventory::~Inventory()
{
    //empty on purpose
}
