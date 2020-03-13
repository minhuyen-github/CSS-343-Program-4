//
//  classic.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef classic_h
#define classic_h


#include <string>
#include "movie.h"
using namespace std;
//--------------------------  class Classics --------------------------------
// Purpose:
//   -- child class of Movie. Classical movie has extra info:
//      month and majorActor. Also, classical movie sort by majoractor, month,
//      and year.
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie
//   -- Implement with following futures:
//      createMovieInfo, createCustomerHistory,
//        ==, !=, >, <, and isEqual
//   -- Assumption: each Classics movie that has same director, same
//      title, same year and month, but has different Major will be
//      considirate as a different Classic movie.
//----------------------------------------------------------------------------
class Classics : public Movie
{
public:
    
    ~Classics();                                        // destructor
    Classics(const string&);                            // constructor
    Classics(const string&, const int&, const int&);    // constructor
    
    virtual string createMovie() const;            // returns string of formated movie info
    virtual string createHistory() const;    // returns string of movie info for customer transactions
    //string getMajorActor()const;
    
    static const char GENRE = 'C';                   // static identifier for the class
    bool isEqual(const Movie* rhs)const;        // used for alternate classic movie with same title, month, and year, but different title
    
    
protected:
    
    void parseAndLoadString(const string& movieInfo);     // helper method for constructor
    bool operator==(const Movie* rhs) const;            // equal comparison operator
    bool operator!=(const Movie* rhs) const;            // not equal comparison operator
    bool operator>(const Movie* rhs) const;                // greater than operator
    bool operator<(const Movie* rh) const;                // less than operator
    
    int month;                                          // hold month
    string actor;                                       // hold major actor's first and last name
};

#endif /* classic_h */
