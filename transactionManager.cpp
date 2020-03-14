#include "transactionManager.h"

//------------------------- class TransactionManager ------------------------
// Purpose:
//     -- Transaction Manager Processes the transaction file
//---------------------------------------------------------------------------

//----------------------------- Constructor ---------------------------------
//
//---------------------------------------------------------------------------
TransactionManager::TransactionManager()
{
    //empty on purpose
}

//----------------------------- Destructor ----------------------------------
//
//---------------------------------------------------------------------------
TransactionManager::~TransactionManager()
{
    //empty on purpose
}


//--------------------------- readCommands -----------------------------------
// --Function: read commands
// --Param:
//      --commandFile is a file with commands with 1 command per line
// --Post-condition:
//      --transaction commands are turned into a  string and then
//        sent to be processed by transaction factory.
//----------------------------------------------------------------------------
void  TransactionManager::readCommands(ifstream& command, CustomerManager& customers, InventoryManager& inventory)
{
    //char type = ' ';
    string commandLine;
    
    while (!command.eof())             // do until end of file has been reached
    {
        getline(command, commandLine);    // get single command
        commandLine.erase(remove(commandLine.begin(), commandLine.end(), '\r'), commandLine.end()); //remove all /r
        
        TransactionFactory doTransaction(commandLine, customers, inventory); // send it to transaction factory
        string addToErrors = doTransaction.getErrors();
        
        if (addToErrors != "" && addToErrors[0] == 'E')
        {
            error.push_back(doTransaction.getErrors());
        }
    }
    
    cout << "------------------ Transaction Errors --------------------" << "\n";
    
    for (int i = 0; i < error.size(); i++)
    {
        
        cout << error[i] << "\n";
    }
}
