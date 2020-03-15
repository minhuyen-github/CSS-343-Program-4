// ------------------------------------------------ myDriver.cpp -------------------------------------------------------

// Name: Uyen Hoang, Max Nguyen
// CSS 343 Section C

// Creation Date: 3/9/2020

// Date of Last Modification: 3/14/2020

// --------------------------------------------------------------------------------------------------------------------

// This program is the implementation file (.cpp) that contains the main function to run the whole program.
// Main function reads 3 data textfiles, then process all movies, customes, and commands.

// -------------------------------------------------------------------------------------------------------------------- 
#include <stdio.h>
#include "storeManager.h"
#include <iostream>

using namespace std;

int main()
{
    // Read movie data file
    ifstream infile1("data4movies.txt");
    if (!infile1) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    
    // Read command data file
    ifstream infile2("data4commands.txt");
    if (!infile2) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    
    // Read customer data file
    ifstream infile3("data4customers.txt");
    if (!infile3) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    
    StoreManager store;                   // allocate store
    store.buildStore(infile1, infile3);   // proccess movies and customers
    store.readCommands(infile2);        // proccess commands
    
    // Close the 3 files
    infile1.close();
    infile2.close();
    infile3.close();
    
    return 0;
}

