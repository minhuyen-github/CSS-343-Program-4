
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

//--------------------------  class MovieFactory ----------------------------
// Purpose: This class creates new movie from input string.
//---------------------------------------------------------------------------
class MovieFactory {

public:
    static Movie* createMovie(const string&); // create pointer to the object Movie
};
#endif /* movieFactory_h */
