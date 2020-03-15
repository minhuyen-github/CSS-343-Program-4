
#include "movieFactory.h"

//----------------------------- createMovie ---------------------------------
// Description: This function creates a new movie object based on the command line.
// Post-condition: Returns a pointer to the newly created movie object.
//                 If there is no object created, return nullptr
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
