#include "inventoryManager.h"


//-------------------------- processInventory ----------------------------------
// Description: This function process inventory commands from the given file.
//              It also uses method from class MovieFactory to create a pointer
//              object to Movie.
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

//--------------------------- retrieveveMovie ------------------------------------
// Description: This function retrieves movie from appropriate BSTree.
// Post-condition: Return a pointer to the correct Movie object.
//------------------------------------------------------------------------------
Movie* InventoryManager::retrieveMovie(const string& info)
{
    char genre;                 // store movie's genre
    stringstream ss;            // string reader
    ss << info;                 // get movie's info
    ss >> genre;                // get genre
    Movie* movieData = nullptr;            // make a pointer
    
    string dummyString1, dummyString2;    // dummy string variables to store retrieval info
    int dummyInt1, dummyInt2;            // dummy integer variable to store retrieval info
    
    string send; //temp string to create movies
    
    switch (genre)
    {
        case 'D':                                                            // If Drama
            getline(ss, dummyString1, ',');                                    // get Director
            dummyString2 = (ss.str().substr(ss.tellg()));                    // get Title
            send = "D , 0," + dummyString1 + "," + dummyString2 + " 2000";  // load send string
            
            movieData = MovieFactory::createMovie(send);        // Create temp movie
            return dramaBST.retrieve(movieData);                // Look for movie in its BSTree
            break;
            
        case 'F':                                                            // If Comedy
            getline(ss, dummyString1, ',');                                 // get Title
            ss >> dummyInt1;                                                // get Year
            send = "F, 0, Director," + dummyString1 + "," + to_string(dummyInt1);
            
            movieData = MovieFactory::createMovie(send);        // create temp movie
            return comedyBST.retrieve(movieData);                // Look for movie in its BSTree
            break;
            
        case 'C':                                                         // If Classic
            ss >> dummyInt1 >> dummyInt2;                                    // get Month and Year
            dummyString1 = (ss.str().substr(ss.tellg()));                    // get Major Actor
            send = "C, 0, Director, title," + dummyString1 + " " + to_string(dummyInt1) + " " + to_string(dummyInt2);
            
            movieData = MovieFactory::createMovie(send);        // create temp movie
            return classicsBST.retrieve(movieData);                // Look for movie in its BSTree
            break;
            
            
        default:    //Invalid genre code
            return movieData;
            break;
    }
    
}
//----------------------------- retrieveClassicMovie --------------------------------
// Description: This function retrieve a Classic movie that is the same title, month,
//              and year, but not the same major actor.
// Post-condition: Return a pointer to the correct classic movie object.
//------------------------------------------------------------------------------
Movie* InventoryManager::retrieveClassicMovie(Movie* ptr)
{
    return classicsBST.retrieveClassicMovie(ptr);
}

//-------------------------- display ----------------------------------------
// Description: This function displays all BSTrees (e.g. Comedies, Dramas, Classics).
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
// Descripiton: This function collects errors that have been detected while
//              attempting to create Movie objects.
//------------------------------------------------------------------------------
void InventoryManager::addError(const string& error)
{
    string temp = "  ";
    temp += error;
    allErrors.push_back(temp);
}

//-------------------------- displayError --------------------------------------
// Description: This function displays all errors that have been detected while
//              attempting to create Movie objects.
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
