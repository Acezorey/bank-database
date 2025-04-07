/*****************************************************************
//
//  NAME:        Ace Reyes
//
//  HOMEWORK:    project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 27, 2023
//
//  FILE:        user_interface.c
//
//  DESCRIPTION:
//   This file contains the user interface source code for
//   the bank user interface, now in C++
//
****************************************************************/

#include <iostream>
#include <cstring>
#include "record.h"
#include "llist.h"

void getaddress(char[], int);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION: * Displays to the user an introductory message
//                 and menu screen, prompting the user to select
//                 a menu option. Upon selection, main will
//                 prompt the user for any more additional
//                 required information, sometimes through
//                 the use of the function getaddress, and then
//                 call the appropriate database.c function
//                 with the collected information.
//
//               * If the input for the menu option provided by
//                 the user is determined to not be valid, main
//                 will ask the user to retype their input
//
//               * If debug mode was attempted to be run, main
//                 first checks if debug mode was called 
//                 correctly. Prints out an error message if
//                 not, and activates debug mode (sets
//                 global variable debugmode to 1) if valid
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
/                                  to the program.
//
//  Return values: int success: 0 if function ran successfully,
//                              -1 if it did not
//
****************************************************************/

int main(int argc, char* argv[])
{
    int success = 0;
    int runFunction = 1;
    int userInputNum = 0;
    int looper = 1;
    int iterator = 0;
    int functionsuccess = 0;
    int switcher = 0;

    char selector = 0;

    char add[4] = "add";
    char printall[9] = "printall";
    char find[5] = "find";
    char deletel[7] = "delete";
    char quit[5] = "quit";

    char userInput[30];
    char check[9];
    char address[50];

    char memoryfile[11] = "memory.txt";

    llist initlist(memoryfile);
    llist database = initlist;

    #ifdef DEBUGMODE
    cout << "\n\nDEBUG MODE\n";
    cout << "@========================================================================@\n";
    #else
    cout << "\n\n@===================================";
    cout << "=====================================@\n";
    #endif

    cout << "\n                   - Welcome to Ace's Bank Database -\n";
    cout << "                            - C++ Edition -\n\n";
    cout << "\nEnter in the name of the menu option to select it\n";

    while (runFunction == 1)
    {
        userInputNum = 0;
        iterator = 0;
        switcher = 0;
        looper = 1;

        cout << "\nMenu options:\n";
        cout << " - add: Adds a new record into the database\n";
        cout << " - printall: Prints all records in the database\n";
        cout << " - find: Finds the record with a specified account number\n";
        cout << " - delete: Deletes the existing record with a specified acccount number\n";
        cout << " - quit: Quits the program\n\n";
        cout << "\nChoose a menu option: ";

        cin >> userInput;

        if (userInput[0] == 'a')
        {
            if (strlen(userInput) <= strlen(add) + 1)
            {
                switcher = 1;
                strcpy(check, add);
            }
        }
        else if (userInput[0] == 'p')
        {
            if (strlen(userInput) <= strlen(printall) + 1)
            {
                switcher = 2;
                strcpy(check, printall);
            }
        }
        else if (userInput[0] == 'f')
        {
            if (strlen(userInput) <= strlen(find) + 1)
            {
                switcher = 3;
                strcpy(check, find);
            }
        }
        else if (userInput[0] == 'd')
        {
            if (strlen(userInput) <= strlen(deletel) + 1)
            {
                switcher = 4;
                strcpy(check, deletel);
            }
        }
        else if (userInput[0] == 'q')
        {
            if (strlen(userInput) <= strlen(quit) + 1)
            {
                switcher = 5;
                strcpy(check, quit);
            }
        }

        if (switcher != 0)
        {
            while (iterator < static_cast<int>(strlen(userInput)))
            {
                if (userInput[iterator] != check[iterator] && userInput[iterator] != '\n')
                {
                    switcher = 0;
                }
                iterator++;
            }
        }

        switch (switcher)
        {
            case 1:
            cout << "\nChosen menu option: add\n\n";

            while (looper == 1)
            {
                cout << "\nEnter in an account number: ";
                cin >> userInputNum;
                if (userInputNum <= 0)
                {
                    cout << "\nPlease enter in a posivive non-zero number\n";
                    cin.clear();
                }
                else
                {
                    looper = 0;
                }
                cin.ignore(100, '\n');
            }
            cout << "\nEnter your name: ";
            cin.getline(userInput, 30);
            cout << "\nType in your address\n\n";
            cout << "This address has a limit of 50 characters\n";
            cout << "In order to enter in your address, press 'enter' twice in a row\n\n";
            cout << "Address:\n\n";
            looper = 1;
            while (looper == 1)
            {
                getaddress(address, 50);
                cout << "\n\nInputted address:\n\n";
                cout << address;
                cout << "\nIs this your correct address? (Y/N): ";
                looper = 2;
                while (looper == 2)
                {
                    cin >> selector;
                    if (selector == 'Y' || selector == 'y')
                    {
                        functionsuccess = database.addRecord(userInputNum, userInput, address);
                        if (functionsuccess == 0)
                        {
                            cout << "\nYou have successfully added a record\n\n";
                        }
                        else
                        {
                            cout << "\nFailed to add record,";
                            cout << " account with that number already exists\n";
                            cout << "Cannot add duplicate accounts\n\n";
                        }
                        looper = 0;
                    }
                    else if (selector == 'N' || selector == 'n')
                    {
                        cout << "\n\nRe-enter your address:\n\n";
                        looper = 1;
                    }
                    else if (selector != '\n')
                    {
                        cout << "\nEnter in either 'Y' or 'N': ";
                    }
                    cin.ignore(100, '\n');
                }
            }
            break;

            case 2:
            cout << "\nChosen menu option: printall\n\n";
            database.printAllRecords();
            cout << "\n";
            break;

            case 3:
            cout << "\nChosen menu option: find\n\n";
            while (looper == 1)
            {
                cout << "\nEnter in the account number you wish to look for: ";
                cin >> userInputNum;
                if (userInputNum <= 0)
                {
                    cout << "\nPlease enter in a positive non-zero number\n";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                else
                {
                    cout << "\nFinding account: " << userInputNum << "\n\n";
                    cin.ignore(100, '\n');
                    looper = 0;
                }
            }
            functionsuccess = database.findRecord(userInputNum);
            if (functionsuccess == -1)
            {
                cout << "\nFailed to find account, database is currently empty\n\n";
            }
            else if (functionsuccess == 1)
            {
                cout << "\nFailed to find account, account does not exist\n\n";
            }
            break;

            case 4:
            cout << "\nChosen menu option: delete\n\n";
            while (looper == 1)
            {
                cout << "\nEnter in the account number you wish to delete: ";
                cin >> userInputNum;
                if (userInputNum <= 0)
                {
                    cout << "\nPlease enter in a positive non-zero number\n";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                else
                {
                    cout << "\nDeleting account: " << userInputNum << "\n\n";
                    cin.ignore(100, '\n');
                    looper = 0;
                }
            }
            functionsuccess = database.deleteRecord(userInputNum);
            if (functionsuccess == -1)
            {
                cout << "\nFailed to delete account, database is currently empty\n\n";
            }
            else if (functionsuccess == 1)
            {
                cout << "\nFailed to delete account, account does not exist\n\n";
            }
            else if (functionsuccess == 0)
            {
                cout << "\nSuccessfully deleted account " << userInputNum << "\n\n";
            }
            break;

            case 5:
            cout << "\nChosen menu option: quit\n\n";
            runFunction = 0;
            break;

            case 0:
            cout << "\nPlease enter a valid menu option name\n";
            break;
        }
    }
    initlist = database;

    cout << "\n               - Thank you for using Ace's Bank Database -\n\n";
    cout << "@========================================================================@\n\n\n";

    return success;
}

/*****************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION: * This function uses an fgetc loop in order to
//                 extract the user's inputted address, no matter
//                 the format, terminating only once "Enter" is
//                 pressed twice subsequently.
//
//               * In debug mode, this function additionally
//                 prints out its name, the name of the 
//                 parameters passed to it, and their values
//
//  Parameters:    address (char[]) : The array storing the address
//                 size (int)  : The size of the address array
//
//  Return values: None
//
****************************************************************/

void getaddress(char* address, int size)
{
    char c;
    char prevc = 0;
    int looper = 1;
    int index = 0;

    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Function name: getaddress\n";
    cout << "Function parameter names and values:\n";
    cout << "- address (char[]): \n" << address;
    cout << "\n- size (int): " << size << "\n";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    while (looper == 1)
    {
        c = cin.get();
        if (c == '\n' && prevc == '\n')
        {
            address[index] = 0;
            looper = 0;
        }
        else
        {
            address[index] = c;
            prevc = c;
            index++;
        }
        if (index == size - 2)
        {
            address[index] = 0;
            looper = 0;
        }
    }
}
