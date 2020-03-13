//
//  nodedata.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/5/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef inventoryManager_h
#define inventoryManager_h

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "movie.h"
#include "bintree.h"
#include "movieFactory.h"
//--------------------------  class InventoryManager ------------------------
// Purpose: This class reads the given file then sort and insert
//      movies to a specific BSTree (Drama, Classisc, Comedy).
//      It also displays all BSTrees and keep track of invalid movies.
//
// Implementation and assumptions:
//   -- Implement as manager class
//   -- Implement with using factory pattern:
//      MovieFactory class.
//   -- Implement with following futures:
//      proccessInvetory, retriveMovie, displayAll, classicRetrieve,
//        addError, displayErrors
//---------------------------------------------------------------------------

class InventoryManager
{
public:
    
    void processInventory(ifstream&);                 // proccess invetory
    Movie* retrieveMovie(const string&);
    void display()const;
    Movie* retrieveClassicMovie(Movie*);
    
private:
    
    void addError(const string&);                             // add errors from all invalid movie
    void displayErrors() const;                        // displays all invalid movies that has been detected
    
    vector<string> allErrors;                     // error collector
    BinTree dramaBST;                                  // BSTrees for drama movies
    BinTree classicsBST;                               // BSTrees for classic movies
    BinTree comedyBST;                                 // BSTrees for comedy movies
};
#endif /* inventoryManager_h */
