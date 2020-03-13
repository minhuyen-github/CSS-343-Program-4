//
//  movie.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "movie.h"
//----------------------------- Construstor ----------------------------------
//
//----------------------------------------------------------------------------
Movie::Movie()
{
    genre = ' ';
    stock = 0;
    director = "";
    title = "";
    year = 0;
}


//------------------------ parseNloadString ----------------------------------
// --Helper method for constractor.
// --Parses the string into a smaller pieces. From these pieces
//   assign inforamtion to a current movie.
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
//  --Increase stock of current movievby one
//-----------------------------------------------------------------------------
bool Movie::increaseStock()
{
    this->stock++;
    return true;
}

//------------------------ getStock   ------------------------------------------
// --returns current stock of the movie
//------------------------------------------------------------------------------
int Movie::getStock()
{
    return stock;
}

//-------------------------- decreaseStock  ------------------------------------
// --Decreases current stock of the movie.
// --If stock is less than or equal zero, stock will be the same and return false,
//     else will return true after decreasing stock by one
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

