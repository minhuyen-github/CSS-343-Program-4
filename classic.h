
#ifndef classic_h
#define classic_h


#include <string>
#include "movie.h"
using namespace std;
//--------------------------  class Classics --------------------------------
// Purpose: child class of Movie. Classical movie has extra info:
//      month and major actor. Also, classic movie sort by major actor, month,
//      and year.
// Assumption: each classic movie that has same director, same
//      title, same year and month, but has different major actor will be
//      consider as a different classic movie.
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
