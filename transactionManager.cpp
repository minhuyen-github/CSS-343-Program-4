#include "transactionManager.h"

//----------------------------- Constructor ---------------------------------
// Descriptoion: This is the default constructor
//---------------------------------------------------------------------------
TransactionManager::TransactionManager()
{
    //empty on purpose
}

//----------------------------- Destructor ----------------------------------
// Description: This is the destructor
//---------------------------------------------------------------------------
TransactionManager::~TransactionManager()
{
    //empty on purpose
}

//--------------------------- readCommands -----------------------------------
// Description: This function reads command lines from command file
// Post-condition: Transaction commands are turned into a string and then
//                 sent to be processed by class TransactionFactory.
//----------------------------------------------------------------------------
void  TransactionManager::readCommands(ifstream& command, CustomerManager& customers, InventoryManager& inventory)
{
    //char type = ' ';
    string commandLine;
    
    while (!command.eof())             // do until end of file has been reached
    {
        getline(command, commandLine);    // get single command
        commandLine.erase(remove(commandLine.begin(), commandLine.end(), '\r'), commandLine.end()); //remove all /r
        
        TransactionFactory doTransaction(commandLine, customers, inventory); // send it to TransactionFactory
        string addToErrors = doTransaction.getErrors();
        
        if (addToErrors != "" && addToErrors[0] == 'E') //if found an error
        {
            error.push_back(doTransaction.getErrors()); //push it to the vector
        }
    }
    
    cout << "------------------ Transaction Errors --------------------" << "\n"; //display transaction errors
    
    for (int i = 0; i < error.size(); i++)
    {
        
        cout << error[i] << "\n";
    }
}
