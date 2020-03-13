//
//  movieFactory.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/9/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "movieFactory.h"

//--------------------------  class MovieFactory ----------------------------
// Purpose: This class uses factory method pattern to create new moive from input string.
//
//---------------------------------------------------------------------------

//----------------------------- createMovie ---------------------------------
// Description: Creates a new movie based on genre using factory method
//---------------------------------------------------------------------------
Movie* MovieFactory::createMovie(const string& command)
{
    Movie* addToInventory = nullptr;               //  pointer to movie
    switch (command[0])    // get first character of string array
    {
        case Drama::GENRE:
            addToInventory = (Movie*) new Drama(command);  // create Drama
            break;
        case Comedy::GENRE:
            addToInventory = (Movie*) new Comedy(command);  // create Comedy
            break;
        case Classics::GENRE:
            addToInventory = (Movie*) new Classics(command); // create Classics
            break;
        default:
            break;
    }
    return addToInventory; // return movie
}
