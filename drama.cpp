
#include "drama.h"
#include <sstream>

//-------------------------- Constructor --------------------------------------
// Description: This is the constructor which will call parseAndLoadString method
//              to create a drama movie object.
//-----------------------------------------------------------------------------
Drama::Drama(const string& movieInfo)
{
    parseAndLoadString(movieInfo);
}

//---------------------------Constructor -------------------------------------
// Description: This is the constructor which will set the movie title and director
//----------------------------------------------------------------------------
Drama::Drama(const string& releaseTitle, const string& releaseDir)
{
    this->title = releaseTitle;
    this->director = releaseDir;
}

//------------------------- Destructor ----------------------------------------
// Description: This is the destructor.
//-----------------------------------------------------------------------------
Drama::~Drama()
{
    //empty on purpose
}

//----------------------------- createMovie ------------------------------
// Description: This function creates a formated string with all the movie 
//              info console.
// Post-condition: a string represent the drama movie info
//----------------------------------------------------------------------------
string Drama::createMovie() const
{
    ostringstream movieInfo;
    
    movieInfo << setw(21) << left << director << setw(21) << left << title;
    movieInfo << setw(9) << right << year << setw(8) << right << stock << endl;
    
    return movieInfo.str();
}

//----------------------------- createHistory   ----------------------
// Description: This function creates a formated string with all the movie info for customer history.
// Post-condition: a formated string with all the movie info for customer history.
//----------------------------------------------------------------------------
string Drama::createHistory() const
{
    ostringstream movieInfo;
    
    movieInfo << setw(10) << " Drama: " << director << " " << title;
    movieInfo << " " << year;
    
    return movieInfo.str();
}

//------------------------ operator== ----------------------------------------
// Description: This function compares current object Movie with other object Movie.
// Post-condition: Returns true if title and director are the same
//                 Else returns false.
//----------------------------------------------------------------------------
bool Drama::operator==(const Movie* movie) const
{
    const Drama* rhsCopy = (const Drama*)movie;
    
    return ((title == rhsCopy->title) && (director == rhsCopy->director));
}

//------------------------ operator!= ----------------------------------------
// Description: This function compares current object Movie with other object Movie.
// Post-condition: Returns true if title or director are not the same
//                 Else returns false.
//----------------------------------------------------------------------------
bool Drama::operator!=(const Movie * movie) const
{
    return !(this == movie);
}

//------------------------ operator> -----------------------------------------
// Description: This function compares current object Movie with other object Movie.
// Post-condition: Returns true if director is greater.
//                 If director is the same, then checks title and returns true if greater.
//                 Else returns false.
//----------------------------------------------------------------------------
bool Drama::operator>(const Movie * movie) const
{
    const Drama* rhsCopy = (const Drama*)movie;
    
    return ((director > rhsCopy->director) || ((director == rhsCopy->director) && (title > rhsCopy->title)));
}

//------------------------ operator< -----------------------------------------
// Description: This function compares current object Movie with other object Movie.
// Post-condition: Returns true if (this) does not equal rhs and is not greater than rhs.
//                 Else it returns false.
//----------------------------------------------------------------------------
bool Drama::operator<(const Movie * movie) const
{
    return ((this != movie) && !(this > movie));
}
