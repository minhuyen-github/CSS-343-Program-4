
#include "comedy.h"
//---------------------------- class Comedy --------------------------------
// Purpose: Child class of Movie. Comedy Movie sorts by title and year.
//---------------------------------------------------------------------------

#include "comedy.h"
//------------------------ Constructor ----------------------------------------
// Description: This is the constructor which will use the parseAndLoadString method 
//              to create a comedy movie.
// Post-condition: A comedy movie object is created
//-----------------------------------------------------------------------------
Comedy::Comedy(const string& movie)
{
    parseAndLoadString(movie);
}

//----------------------- Constructor ----------------------------------------
// Description: This is the constructor which will set the movie's title and director.
//----------------------------------------------------------------------------
Comedy::Comedy(const string& title, const int& year)
{
    this->title = title;
    this->year = year;
}

//------------------------- Destructor ----------------------------------------
// Description: This is the destructor
//-----------------------------------------------------------------------------
Comedy::~Comedy()
{
    //emptty on purpose
}

//------------------------ operator== ----------------------------------------
// Description: This function compares current object Movie with other object Movie.
// Post-condition: Returns true if title and year are the same
//                 Else returns false.
//----------------------------------------------------------------------------
bool Comedy::operator==(const Movie* movie) const
{
    const Comedy* rhsCopy = (const Comedy*)movie;
    return ((title == rhsCopy->title) && (year == rhsCopy->year));
}

//------------------------ operator!= ----------------------------------------
// Description: This function compares current object Movie with other object Movie.
// Post-condition: Returns true if title or year are not the same
//                 Else returns false.
//----------------------------------------------------------------------------
bool Comedy::operator!=(const Movie * movie) const
{
    return !(this == movie);
}

//------------------------ operator> -----------------------------------------
// Description: This function compares current object Movie with other object Movie.
// Post-condition: Returns true if title is greater.
//                 If title is the same, then checks year and returns true if greater.
//                 Else returns false
//----------------------------------------------------------------------------
bool Comedy::operator>(const Movie * movie) const
{
    const Comedy* rhsCopy = (const Comedy*)movie;
    return ((title > rhsCopy->title) || ((title == rhsCopy->title) && (year > rhsCopy->year)));
}

//------------------------ operator< -----------------------------------------
// Description: This function compares current object Movie with other object Movie.
// Post-condition: Returns true if (this) does not equal rhs and is not greater than rhs
//                 Else it returns false.
//----------------------------------------------------------------------------
bool Comedy::operator<(const Movie * movie) const
{
    return ((this != movie) && !(this > movie));
}

//----------------------------- createMovie ------------------------------
// Description: This function creates a formated string with all the movie info to console.
// Post-condition: A string represents a movie info
//----------------------------------------------------------------------------
string Comedy::createMovie() const
{
    ostringstream movieInfo;
    
    movieInfo << setw(33) << left << title << setw(1) << right << year
    << setw(20) << left << director << setw(20) << left << stock << endl;
    
    return movieInfo.str();
}

//----------------------------- createHistory ------------------------
// Description: This function creates a formated string with all the movie info for customer history.
// Post-condition: a formated string with all the movie info for customer history.
//----------------------------------------------------------------------------
string Comedy::createHistory() const
{
    ostringstream movieInfo;
    
    movieInfo << setw(10) << " Comedy: " << title << " " << director
    << " " << year;;
    
    return movieInfo.str();
}
