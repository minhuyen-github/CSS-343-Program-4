//
//  myDriver.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/13/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include <stdio.h>
#include "storeManager.h"
#include <iostream>

using namespace std;

int main()
{
    ifstream infile1("/Users/minhuyen/Downloads/CSS 343/CSS 343/Program 4/datafiles/data4movies.txt");
    if (!infile1) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    ifstream infile2("/Users/minhuyen/Downloads/CSS 343/CSS 343/Program 4/datafiles/data4commands.txt");
    if (!infile2) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    
    ifstream infile3("/Users/minhuyen/Downloads/CSS 343/CSS 343/Program 4/datafiles/data4customers.txt");
    if (!infile3) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    
    StoreManager store;                   // allocate store
    store.buildStore(infile1, infile3);   // proccess movies and customers
    store.readCommands(infile2);        // proccess commanads
    
    infile1.close();
    infile2.close();
    infile3.close();
    
    return 0;
}

