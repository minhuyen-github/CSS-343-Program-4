//
//  customer.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 2/26/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef customer_h
#define customer_h

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "movie.h"

using namespace std;

class Customer
{
public:
    
    Customer();                            // default constructor
    Customer(int, string, string);        // constructor with parameters
    ~Customer();                        // destructor
    bool newTrans(char, Movie*);  // adds transaction to customer history
    void printHistory() const;                // print customer borrow and return history
    int getID()const;                // return customer ID
    string displayID()const;                        // get customer ID
    string getFullName()const;                // returns string of customer full name
    string getFirstName()const;            // returns the string of the customer first name
    string getLastName()const;            // returns the string of the custome last name
    bool checkReturn(Movie*)const; // checks if customer is returning a movie they borrowed
    
private:
    
    int ID;                               // customer ID
    string lastName;                    // customer last name
    string firstName;                    // customer first name
    
    struct  TransactionHist
    {
        TransactionHist* next;        // next
        char transaction;            // transaction type (B or R)
        Movie* ptr;                // pointer to the movie
        bool rented;
        TransactionHist(char type, Movie* movie) : transaction(type), ptr(movie), next(nullptr), rented(false) {};
    };
    TransactionHist* head;
    
};
#endif /* customer_h */
