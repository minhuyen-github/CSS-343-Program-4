//
//  store.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/9/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef customerManager_h
#define customerManager_h

#include <stdio.h>
#include <fstream>
#include "customer.h"
#include "hashTable.h"
#include <string>
using namespace std;

class CustomerManager
{
public:
    CustomerManager();                   // constructor
    ~CustomerManager();                  // destructor
    void processCustomers(ifstream& customerFile);   // process file with customers
    Customer* getCustomer(int);                          // returns a customer
    
private:
    HashTable customers;            //stores all customers
};
#endif /* customerManager_h*/
