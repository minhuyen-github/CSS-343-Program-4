//
//  hashTable.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef hashTable_h
#define hashTable_h

#include "customer.h"

using namespace std;

int const ROWS = 101;
int const COLUMNS = 199;

// This is a chain hash table
class HashTable
{
public:
    HashTable();        //constructor
    ~HashTable();        //destructor
    Customer* retrieveCustomer(const int&)const;                //getFunction
    bool addCustomer(Customer* newCustomer);    //addFunction
    bool removeCustomer(const int&);                        //deleteFunction
    
    
private:
    Customer* customerTable[ROWS][COLUMNS];            //The table
    
};

#endif /* hashTable_h */
