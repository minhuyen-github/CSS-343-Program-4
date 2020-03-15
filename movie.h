
#ifndef movie_h
#define movie_h

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

//--------------------------  class Movie -----------------------------------
// Purpose:
//   -- This is an abstract class for child classes Drama,
//      Comdedy, and Classisc. It is used only for inheretance purpose.
//   -- General movie contains information about title, director, year, and stock.
//
//---------------------------------------------------------------------------
class Movie
{
public:
    virtual ~Movie() {};                // destructor
    
    virtual string createMovie() const = 0;      // abstract method to create string format of movie info
    virtual string createHistory() const = 0;    // abstract method to create customer's history
    
    virtual bool increaseStock();    // increase stock
    virtual bool decreaseStock();       // decrease stock
    virtual int getStock();             // return current stock
    virtual bool operator==(const Movie* rhs) const = 0; // check if they are equal
    virtual bool operator!=(const Movie* rhs) const = 0; // check if they are not equal
    virtual bool operator>(const Movie* rhs) const = 0; 
    virtual bool operator<(const Movie* rhs) const = 0;
    
protected:
    
    Movie();    // constructor (protected) to avoid declaration of the object
    void parseAndLoadString(const string& movieInfo);     // helper method for copy constractor
    
    char genre;                          // hold genre
    int stock;                          // hold stock
    string director;                    // hold director
    string title;                       // hold title
    int year;                           // hold year
    
};

#endif /* movie_h */
