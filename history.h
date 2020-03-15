// ------------------------------------------------ history.h -------------------------------------------------------

// Name: Uyen Hoang, Max Nguyen
// CSS 343 Section C

// Creation Date: 3/9/2020

// Date of Last Modification: 3/14/2020

// --------------------------------------------------------------------------------------------------------------------

// This program is the header (.h) that stores the borrowed history of customers

// -------------------------------------------------------------------------------------------------------------------- 
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
