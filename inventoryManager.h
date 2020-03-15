
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
// Purpose: This class reads in a given file then sort and insert
//      movies to a specific BSTree (Drama, Classisc, Comedy).
//      It also displays all BSTrees and keep track of invalid movies inputs.
//---------------------------------------------------------------------------

class InventoryManager
{
public:
    
    void processInventory(ifstream&);                 // reads in the file, then sort and insert
    Movie* retrieveMovie(const string&);              // retrieve a movie
    void display()const;                              // display inventory
    Movie* retrieveClassicMovie(Movie*);              // a seperate method to retrieve classic movies
    
private:
    
    void addError(const string&);                      // add all invalid movie inputs
    void displayErrors() const;                        // displays all invalid movie inputs that has been detected
    
    vector<string> allErrors;                          // store all errors
    BinTree dramaBST;                                  // BSTrees for drama movies
    BinTree classicsBST;                               // BSTrees for classic movies
    BinTree comedyBST;                                 // BSTrees for comedy movies
};
#endif /* inventoryManager_h */
