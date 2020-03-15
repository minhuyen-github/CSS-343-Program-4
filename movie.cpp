
#include "movie.h"
//----------------------------- Construstor ----------------------------------
// Description: This is the default constructor which creates an empty movie object
//----------------------------------------------------------------------------
Movie::Movie()
{
    genre = ' ';
    stock = 0;
    director = "";
    title = "";
    year = 0;
}


//------------------------ parseAndloadString ----------------------------------
// Description: This is the helper function for constructor. It parses the string 
//              into a smaller pieces. From these pieces, it assigns info to the movie object.
// Post-condition: Movie object is updated with info.
//----------------------------------------------------------------------------
void Movie::parseAndLoadString(const string& movie)
{
    stringstream ss;                 // string reader
    ss << movie;                      // insert string info into reader
    
    string temp;                     //  temp string to parse the string
    
    
    getline(ss, temp, ',');          // get movie genre
    genre = temp[0];                  // assign movie genre
    getline(ss, temp, ',');          // get stock
    stringstream(temp) >> stock;  // assign stock // done this way since getline wants a string not int
    getline(ss, director, ',');      // assign director
    getline(ss, title, ',');         // assign title
    getline(ss, temp, ',');          // get year
    stringstream(temp) >> year;      // assign year // done this way since getline wants a string not int
}

//------------------------ increaseStock --------------------------------------
// Description: This function increase the stock of current movie by one
//-----------------------------------------------------------------------------
bool Movie::increaseStock()
{
    this->stock++;
    return true;
}

//------------------------ getStock   ------------------------------------------
// Description: This function returns current stock of the movie.
// Post-condition: The stock of the current Movie object.
//------------------------------------------------------------------------------
int Movie::getStock()
{
    return stock;
}

//-------------------------- decreaseStock  ------------------------------------
// Description: This function decreases current stock of the movie.
// Post-condition: If stock is less than or equal zero, stock will be the same and return false,
//                 Else return true after decreasing stock by one.
//------------------------------------------------------------------------------
bool Movie::decreaseStock()
{
    if (stock <= 0)
    {
        return false;
    }
    else
    {
        stock--;    // decrease sctock
        return true;
    }
    
}

