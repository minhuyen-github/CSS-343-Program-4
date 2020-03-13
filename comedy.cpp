//
//  comedy.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "comedy.h"
//---------------------------- class Comedy --------------------------------
// Purpose:
//   -- Child class of Movie. Comedy Movie sorts by
//      title and year.
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie.
//   -- Implement with following futures:
//      createMovieInfo, createCustomerHistory, ==, !=, >, <
//---------------------------------------------------------------------------

#include "comedy.h"
//------------------------ Constructor ----------------------------------------
// --Uses helper function parseAndLoadString.
//-----------------------------------------------------------------------------
Comedy::Comedy(const string& movie)
{
    parseAndLoadString(movie);
}

//----------------------- Constructor ----------------------------------------
//
//----------------------------------------------------------------------------
Comedy::Comedy(const string& title, const int& year)
{
    this->title = title;
    this->year = year;
}

//------------------------- Destructor ----------------------------------------
//
//-----------------------------------------------------------------------------
Comedy::~Comedy()
{
    //emptty on purpose
}

//------------------------ operator== ----------------------------------------
// --Compares current object Movie with other object Movie.
// --Returns true if title and year are the same
//   else returns false.
//----------------------------------------------------------------------------
bool Comedy::operator==(const Movie* movie) const
{
    const Comedy* rhsCopy = (const Comedy*)movie;
    return ((title == rhsCopy->title) && (year == rhsCopy->year));
}

//------------------------ operator!= ----------------------------------------
// --Compares current object Movie with other object Movie.
// --Returns true if title or year are not the same
//   else returns false.
//----------------------------------------------------------------------------
bool Comedy::operator!=(const Movie * movie) const
{
    return !(this == movie);
}

//------------------------ operator> -----------------------------------------
// --Compares current object Movie with other object Movie.
// --Returns true if title is greater.
// --If title is the same, then checks year and returns true if greater.
// --Else returns false
//----------------------------------------------------------------------------
bool Comedy::operator>(const Movie * movie) const
{
    const Comedy* rhsCopy = (const Comedy*)movie;
    return ((title > rhsCopy->title) || ((title == rhsCopy->title) && (year > rhsCopy->year)));
}

//------------------------ operator< -----------------------------------------
// --Compares current object Movie with other object Movie.
// --Returns true if (this) does not equal rhs and is not greater than rhs
//   else it returns false.
//----------------------------------------------------------------------------
bool Comedy::operator<(const Movie * movie) const
{
    return ((this != movie) && !(this > movie));
}

//----------------------------- createMovieInfo ------------------------------
// --Creates a formated string with all the movie info for output to console.
//----------------------------------------------------------------------------
string Comedy::createMovie() const
{
    ostringstream movieInfo;
    
    movieInfo << setw(33) << left << title << setw(1) << right << year
    << setw(20) << left << director << setw(20) << left << stock << endl;
    
    return movieInfo.str();
}

//----------------------------- createCustomerHistory ------------------------
// --Creates a formated string with all the movie info for customer history.
//----------------------------------------------------------------------------
string Comedy::createHistory() const
{
    ostringstream movieInfo;
    
    movieInfo << setw(10) << " Comedy: " << title << " " << director
    << " " << year;;
    
    return movieInfo.str();
}
