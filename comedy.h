
#ifndef comedy_h
#define comedy_h

#include <string>
#include "movie.h"
using namespace std;
//---------------------------- Class Comedy --------------------------------
// Purpose: Child class of Movie. Comedy Movie sorts by title and year.
//---------------------------------------------------------------------------
class Comedy : public Movie
{
public:
    
    Comedy(const string&);                            // constructor
    Comedy(const string&, const int&);                // constructor
    virtual ~Comedy();                                // destructor
    static const char GENRE = 'F';                   // static indentifier for a class
    virtual string createMovie() const;           // creates a formated string of movie info for output
    virtual string createHistory() const;    // creates a string of movie info for customer transaction history
    
protected:
    
    virtual bool operator==(const Movie* rhs) const;
    virtual bool operator!=(const Movie* rhs) const;
    virtual bool operator>(const Movie* rhs) const;
    virtual bool operator<(const Movie* rhs) const;
    
};

#endif /* comedy_h */
