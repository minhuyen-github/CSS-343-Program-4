
#ifndef hashTable_h
#define hashTable_h

#include "customer.h"

using namespace std;

int const ROWS = 101;
int const COLUMNS = 199;

//-------------------------- HashTable --------------------------------
// Purpose: This class is built to safely store up to 10,000 customer ID's
//	        in a 101 x 199 two - dimentional matrix, or table. 
// Note: The algorithm determines the ID location by placing the customer in 
//       the table location:[(ID + i ^ 2) % 101][(ID + i ^ 2) % 199] where
//	     i is the number of tries to place the ID in the table
//--------------------------------------------------------------------------
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
