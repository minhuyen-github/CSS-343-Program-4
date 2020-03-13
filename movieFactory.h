//
//  movieFactory.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/9/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef movieFactory_h
#define movieFactory_h

#include <stdio.h>
#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class MovieFactory {

public:
    static Movie* createMovie(const string&); // create pointer to the object Movie
};
#endif /* movieFactory_h */
