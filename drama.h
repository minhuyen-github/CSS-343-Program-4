//
//  drama.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef drama_h
#define drama_h

#include <string>
#include "movie.h"
#include <iostream>
#include <fstream>
using namespace std;
//---------------------------- class Drama ----------------------------------
// Purpose:
//   -- Child class of Movie. Dramma Movie sorts
//      by director and title.
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie
//   -- Implement with following futures:
//      createMovieInfo, createCustomerHistory, ==, !=, >, <
//---------------------------------------------------------------------------
class Drama : public Movie
{
public:
    
    Drama(const string&);                            // constructor
    Drama(const string&, const string&);             // constructor
    virtual ~Drama();                                // destructor
    
    static const char GENRE = 'D';                   // static indentifier for a class
    
    virtual string createMovie() const;               // creates a formated string of movie info for output
    virtual string createHistory() const;    //creates a string of movie info for customer transaction history
    
    
protected:
    
    bool operator==(const Movie* rhs) const;   // == operator
    bool operator!=(const Movie* rhs) const; // != operator
    bool operator>(const Movie* rhs) const; // greater than operator
    bool operator<(const Movie* rhs) const;  // less than operator
};

#endif /* drama_h */
