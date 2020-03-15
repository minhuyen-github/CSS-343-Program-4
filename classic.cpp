
#include "classic.h"
#include <sstream>

//------------------------------ Destructor ----------------------------------
// Description: This is the destructor
//----------------------------------------------------------------------------
Classics::~Classics()
{
    //empty on purpose
}

//----------------------- Constructor ----------------------------------------
// Description: This is the constructor which sets the movie's actor, month and year.
//----------------------------------------------------------------------------
Classics::Classics(const string& actor, const int& month, const int& year)
{
    this->actor = actor;
    this->month = month;
    this->year = year;
}

//------------------------ Constructor ---------------------------------------
// Description: This is the constructor which calls parseAndLoadString method
//----------------------------------------------------------------------------
Classics::Classics(const string& movie)
{
    parseAndLoadString(movie);
}

//------------------------- parseAndloadString ---------------------------------
// Description: This is the helper method for constructor. It parses the string 
//              into a smaller pieces. From these pieces, it assigns infor to a current movie.
//----------------------------------------------------------------------------
void Classics::parseAndLoadString(const string& movie)
{
    stringstream ss;
    ss << movie;
    
    string temp;                 // hold sub string from info string
    char delimiter = ',';        //delimiter
    
    getline(ss, temp, delimiter);      // get genre of movie (char)
    genre = temp[0];
    getline(ss, temp, delimiter);      // get stock number (int)
    stringstream(temp) >> stock;
    getline(ss, director, delimiter);  // get director string
    getline(ss, title, delimiter);     // get title string
    ss >> temp;                  // add second name to first name
    actor += temp;
    actor += ' ';
    ss >> temp;                 // add second name to first name
    actor += temp;
    ss >> month;                // add month
    ss >> year;                 // add month
}


//------------------------------ createMovie -----------------------------
// Description: This function creates a formatted string with all the movie info to console.
// Post-condition: A formatted string with all the movie info to console.
//----------------------------------------------------------------------------
string Classics::createMovie() const
{
    ostringstream movieInfo;
    
    movieInfo << " " << setw(7) << left << month << setw(6) << left << year <<
    setw(18) << left << actor << setw(23) << left <<
    title << setw(17) << left << director << setw(5) << left << stock << endl;
    
    return  movieInfo.str();
}

//------------------------------ createHistory -----------------------
// Description: This function creates a formated string with all the movie info for customer history.
// Post-condition: A formated string with all the movie info for customer history.
//----------------------------------------------------------------------------
string Classics::createHistory() const
{
    ostringstream movieInfo;
    
    movieInfo << setw(10) << " Classic:  " << month << " " << year << ' ' << actor << title << director;
    
    return  movieInfo.str();
}


//--------------------------------- isEqual ----------------------------------
// Description: This function is only used in BinTree if a customer is trying to borrow a Classic and the
//              stock is zero. It will then try to find an alternative Classic that has same
//              title, month, and year, but not the same major actor.
// Post-condition: Return true if an alternate is found, otherwise, return false
//----------------------------------------------------------------------------
bool Classics::isEqual(const Movie* movie) const
{
    const Classics* rhsCopy = (const Classics*)movie;
    return ((title == rhsCopy->title) && (year == rhsCopy->year) && (month == rhsCopy->month) && actor != rhsCopy->actor);
}


//------------------------ operator== ---------------------------------------
// Description: This function compares current object Movie with other object Movie.
// Post-condition: Returns true if major actor, year, and month are the same
//                 Else returns false.
//----------------------------------------------------------------------------
bool Classics::operator==(const Movie * movie) const
{
    const Classics* rhsCopy = (const Classics*)movie;
    return ((actor == rhsCopy->actor) && (year == rhsCopy->year) && (month == rhsCopy->month));
    
}

//------------------------ operator!= ---------------------------------------
// Description: This function compares current object Movie with other object Movie.
// Post-condition: Returns true if major actor, year, or month are not the same
//                 Else returns false.
//----------------------------------------------------------------------------
bool Classics::operator!=(const Movie * movie) const
{
    return !(this == movie);
}

//------------------------ operator> ----------------------------------------
// Description: This function compares current object Movie with other object Movie.
// Post-condition: Returns true if year is greater.
//                 If year is the same, then checks month and returns true if greater.
//                 If year and month are the same, then checks majorActor and returns true
//                 if greater.
//                 Else returns false.
//----------------------------------------------------------------------------
bool Classics::operator>(const Movie * movie) const
{
    const Classics* rhsCopy = (const Classics*)movie;
    
    return ((year > rhsCopy->year) || ((year == rhsCopy->year) && (month > rhsCopy->month))
            || ((year == rhsCopy->year) && (month == rhsCopy->month) && (actor > rhsCopy->actor)));
}

//------------------------ operator< ----------------------------------------
// Description: This function compares current object Movie with other object Movie.
// Post-condition: Returns true if (this) does not equal rhs and is not greater than rhs
//                 Else it returns false.
//----------------------------------------------------------------------------
bool Classics::operator<(const Movie * movie) const
{
    return ((this != movie) && !(this > movie));
}
