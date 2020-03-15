
#ifndef customerManager_h
#define customerManager_h

#include <stdio.h>
#include <fstream>
#include "customer.h"
#include "hashTable.h"
#include <string>
using namespace std;

//-------------------------- class CustomerManager ---------------------------
// Purpose: This class put each customer with their info into the HashTable.
//          It can also retrieve a specified customer using their unique IDs.
//----------------------------------------------------------------------------
class CustomerManager
{
public:
    CustomerManager();                   // constructor
    ~CustomerManager();                  // destructor
    void processCustomers(ifstream& customerFile);       // process file which contains customers' info
    Customer* getCustomer(int);                          // returns a customer given a unique ID
    
private:
    HashTable customers;            //stores all customers' info
};
#endif /* customerManager_h*/
