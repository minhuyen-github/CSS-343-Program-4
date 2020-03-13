//
//  nodedata.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "inventoryManager.h"


//-------------------------- processInventory ----------------------------------
// --Process inventory commands from file (infile).
// --Uses factory method (MovieFactory) to create pointer object to Movie.
//------------------------------------------------------------------------------
void InventoryManager::processInventory(ifstream& infile)
{
    string command;                                     // hold movie information
    
    while (!infile.eof())
    {
        
        getline(infile, command);                       // inser info into string
        
        Movie* a = MovieFactory::createMovie(command);  // pointer to the object movie
        
        switch (command[0])                             // check what object type to insert curent movie
        {
            case Drama::GENRE:
                dramaBST.insert(a);             // insert Drama movie
                break;
            case Comedy::GENRE:
                comedyBST.insert(a);            // insert Comedy movie
                break;
            case  Classics::GENRE:
                classicsBST.insert(a);          // insert Classics movie
                break;
            default:
                addError(command);         // add unkown movie (error)
                break;
        }
    }
    displayErrors(); // display errors
}

//--------------------------- retireveMovie ------------------------------------
// --Retrieves movie from appropriate BinTree.
//------------------------------------------------------------------------------
Movie* InventoryManager::retrieveMovie(const string& info)
{
    char genre;
    stringstream ss;            // string reader
    ss << info;                    // load with info
    ss >> genre;                // get genre
    Movie* movieData = nullptr;            // make temp pointer
    
    string dummyString1, dummyString2;    // dummy string for getting retreival info
    int dummyInt1, dummyInt2;            // dummy ints for getting retreval info
    
    string send; //temp string for creating movies
    
    switch (genre)
    {
        case 'D':                                                            // If Drama
            getline(ss, dummyString1, ',');                                    // Get Director
            dummyString2 = (ss.str().substr(ss.tellg()));                    // Get Title
            send = "D , 0," + dummyString1 + "," + dummyString2 + " 2000";  // load send string
            
            movieData = MovieFactory::createMovie(send);        // Create temp movie
            return dramaBST.retrieve(movieData);                // Look for movie in inventory
            break;
            
        case 'F':                                                            // If Comedy
            getline(ss, dummyString1, ',');                                 // Title
            ss >> dummyInt1;                                                // Get Year
            send = "F, 0, Director," + dummyString1 + "," + to_string(dummyInt1);
            
            movieData = MovieFactory::createMovie(send);        // create temp movie
            return comedyBST.retrieve(movieData);                // Look for movie in inventory
            break;
            
        case 'C':                                                         // If Classic
            ss >> dummyInt1 >> dummyInt2;                                    // Get Month and Year
            dummyString1 = (ss.str().substr(ss.tellg()));                    // Get Major Actor
            send = "C, 0, Director, title," + dummyString1 + " " + to_string(dummyInt1) + " " + to_string(dummyInt2);
            
            movieData = MovieFactory::createMovie(send);        // create temp movie
            return classicsBST.retrieve(movieData);                // Look for movie in inventory
            break;
            
            
        default:    //Invalid Genre Code
            return movieData;
            break;
    }
    
}
//----------------------------- classicRetrieve --------------------------------
// --Used only when the store needs to retrieve a Classic movie that is the same
//   title, month, and year, but not the same major Actor
//------------------------------------------------------------------------------
Movie* InventoryManager::retrieveClassicMovie(Movie* ptr)
{
    return classicsBST.retrieveClassicMovie(ptr);
}

//-------------------------- displayAll ----------------------------------------
// --Displays all BinTrees (e.g. Comedies, Dramas, Classics).
//------------------------------------------------------------------------------
void InventoryManager::display()const
{
    cout << endl;
    cout << "----------------------------------------------------------------" << endl << endl;
    cout << "                                Display Comedies " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << " Title                           Year Director          Stock" << endl;
    comedyBST.display();
    
    cout << "----------------------------------------------------------------" << endl << endl;
    cout << "                                Display Dramas " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << " Director             Title                    Year     Stock" << endl;
    dramaBST.display();
    
    cout << "----------------------------------------------------------------" << endl << endl;;
    cout << "                                Display Classics " << endl;
    
    cout << "----------------------------------------------------------------" << endl;
    cout << " Month  Year  Major actor        Title                  Director       Stock" << endl;
    classicsBST.display();
    
    cout << "----------------------------------------------------------------" << endl;
    cout << endl << endl;
}

//-------------------------- addError ------------------------------------------
// --Collects errors that have been detected while attempting to create movie(s).
//------------------------------------------------------------------------------
void InventoryManager::addError(const string& error)
{
    string temp = "  ";
    temp += error;
    allErrors.push_back(temp);
}

//-------------------------- displayError --------------------------------------
// --Displays all errors found while attempting to create movie(s).
//------------------------------------------------------------------------------
void InventoryManager::displayErrors() const
{
    cout << endl;
    cout << "----------------------------------------------------------------" << endl << endl;
    cout << "                                Invalid movie report" << endl << endl;
    
    for (int i = 0; i < allErrors.size(); i++)
    {
        cout << allErrors[i] << "\n";
    }
    
    cout << endl;
    cout << "----------------------------------------------------------------" << endl;
}
