// ------------------------------------------------ borrow.h -------------------------------------------------------

// Name: Uyen Hoang, Max Nguyen
// CSS 343 Section C

// Creation Date: 3/9/2020

// Date of Last Modification: 3/14/2020

// --------------------------------------------------------------------------------------------------------------------

// This program is the header file (.h) that process transaction borrow

// -------------------------------------------------------------------------------------------------------------------- 
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
