//
//  customer.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 2/26/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "customer.h"


//--------------------------- Default Constructor ---------------------------
// --Default Constructor:
// --Param: N/A
// --Post-condition:
//     --Sets ID to -1, lastName and firstName to en empty string.
//---------------------------------------------------------------------------
Customer::Customer()
{
    ID = -1;                       // customer ID
    lastName = "";               // customer last name
    firstName = "";
    head = nullptr;
}
//-------------------------- Constructor -----------------------------------
// --Constructor Overload:
// --Param :
//      --newID is an Int >= 0 and < 10000
//      --first and last name are strings
// --Post-condition:
//    --sets the customers ID, first name and last name according
//        to the parameters. Transaction log is initialized to nullptr.
//---------------------------------------------------------------------------

Customer::Customer(int id, string last, string first)
{
    if (id < 0 || id > 9999)
    {
        return;
    }
    
    ID = id;                      // customer ID
    lastName = last;          // customer last name
    firstName = first;        // customer first name
    head = nullptr;                    // transaction history doesn't exist yet
}


//------------------------------ Destructor ---------------------------------
// --Destructor:
// --Param: N/A
// --Post-condition:
//      --De-allocates memory used for Transaction Log.
//---------------------------------------------------------------------------
Customer::~Customer()
{                                        // delete history
    TransactionHist* current = head;        // temporary pointer
    while (current != nullptr)
    {                                    // traverse the entire LL
        head = head->next;                // set head to head next
        current->ptr = nullptr;        // set to null pointer
        delete current;                    // delete the pointer
        current = head;                    // set temp to head
    }
}

//--------------------------- newTransaction --------------------------------
// --Function: newTransaction
// --Param:
//      --type is of type char representing the type of transaction.
//      --theMovie is a movie from the inventory pointing to the
//        movie assocaited to customer transaction.
// --Post-condition:
//      --The transaction will be added to customer history.
//---------------------------------------------------------------------------
bool Customer::newTrans(char type, Movie* movie)
{
    
    TransactionHist* ptr = new TransactionHist(type, movie); // temp pointer
    if (type == 'B')
    {
        ptr->rented = true;
    }
    
    if (head == nullptr)        // If it is the first transaction
    {
        head = ptr;                // make temp pointer the new head
    }
    else                    // If the customer has a history
    {
        ptr->next = head;        // Move head down
        head = ptr;                // Insert at the front of transaction history
    }
    
    return true;                // Insertion complete
}

//------------------------ checkIfBorrowed ----------------------------------
// --Function: checkIfBorrowed
// --Param:
//      --char type is 'R'
//      --theMovie is a pointer to the movie that the customer wishes to return.
// --Post-condition:
//      --Will return true if the movie is found in customer
//        history with rented marked true, false otherwise.
//---------------------------------------------------------------------------
bool Customer::checkReturn(Movie* movie)const
{
    TransactionHist* current = head;    // Temp pointer for transactionLog traversal
    bool foundItem = false;
    
    if (current == nullptr)            // If transactionHist is empty
    {
        return foundItem;                // The customer hasn't borrowed any movies
    }
    
    while (current != nullptr)        // Traverse entire TransactionHist
    {
        if (current->transaction == 'B' && current->ptr == movie && current->rented == true)
        {
            current->rented = false;    // Movie has been borrowed, mark as returned
            foundItem = true;
            return foundItem;                // continue to adding to customer history
        }
        
        current = current->next;
    }
    return foundItem;
}

//----------------------------- printHistory --------------------------------
// --Function: printHistory
// --Param: N/A
// --Post-condition:
//      --Prints the entire customer transaction history in order
//        of newest to oldest.
//---------------------------------------------------------------------------
void Customer::printHistory() const
{
    cout << "----------------------------------------------------------------" << endl << endl;
    cout << getFullName() << ": ID# " << getID() << endl << "Rental History: " << endl;  //printing customer info
    
    TransactionHist* current = head;    // setting ptr to start of transaction history
    
    while (current != nullptr)        // Traverse entire transaction history
    {
        if (current->transaction == 'B')
        {
            cout << ("Borrowed " + current->ptr->createHistory()) << endl;
        }
        else
        {
            cout << ("Returned " + current->ptr->createHistory()) << endl;
        }
        
        current = current->next;        //set current to next for next transaction
    }
    
    cout << "----------------------------------------------------------------" << endl << endl;
    cout << endl;
    
}

//------------------------------ getID -----------------------------------
// --Function: getID
// --Param: N/A
// --Post-condition:
//      --Returns the int value of the customer's ID.
//---------------------------------------------------------------------------
int Customer::getID()const
{
    return ID;
}

//------------------------------ getName -----------------------------------
// --Function: getName
// --Param: N/A
// --Post-condition:
//      --returns the string value of the customers whole name.
//---------------------------------------------------------------------------
string Customer::getFullName()const
{
    return firstName + " " + lastName;
}

//---------------------------- getLastName ---------------------------------
// --Function: getLastName
// --Param: N/A
// --Post-condition:
//      --Returns the string value of the customer's last name.
//---------------------------------------------------------------------------
string Customer::getLastName()const
{
    return lastName;
}

//---------------------------- getFirstName --------------------------------
// --Function: getFirstName
// --Param: N/A
// --Post-condition:
//      --Returns the string value of the customer's first name.
//---------------------------------------------------------------------------
string Customer::getFirstName()const
{
    return firstName;
}

//------------------------------ displayID --------------------------------------
// --Function: displayID
// --Param: N/A
// --Post-condition:
//      --Formats the customer ID into a string so any leadng 0's
//      may also be printed to the output window.
//---------------------------------------------------------------------------
string Customer::displayID()const
{
    string toString = "";
    
    if (ID > 999)                // If no leading 0's
    {
        toString = to_string(ID);
    }
    else if (ID % 1000 == ID)    // If 1 leading 0
    {
        toString = ("0" + to_string(ID));
    }
    else if (ID % 100 == ID)        // If 2 leading 0's
    {
        toString = ("00" + to_string(ID));
    }
    else if (ID % 10 == ID)        // If 3 leading 0's
    {
        toString = ("000" + to_string(ID));
    }
    
    return toString;
    
}
