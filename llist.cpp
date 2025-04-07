/****************************************************************
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
//  FILE:        llist.cpp
//
//  DESCRIPTION: 
//    This file contains the llist.cpp source code: the
//    methods for the llist class
//
***************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include "record.h"
#include "llist.h"

using namespace std;

/***************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   If in debug mode, prints out its own name,
//                 the names and data types of its parameters,
//                 and the value of each parameter. Takes in
//                 the input values of its parameters,
//                 creates a struct record, adds all of the
//                 inputted user information to it and links
//                 it to other already existing struct
//                 records in the correct place (in descending
//                 order according to its account number). If
//                 a record with the inputted account number
//                 already exists, this function instead
//                 returns an error value and does not
//                 create a new record. If it was successful
//                 in adding a record and it is the first
//                 record in the list (start is NULL), then
//                 it sets start (the pointer pointed to by
//                 startpointer) to the address of the first
//                 record.
//
//  Parameters:    accnumber (int):
//                   User inputted account number for new
//                   account
//
//                 name (char[]):
//                   User inputted user name for new account
//
//                 address (char[]):
//                   User inputted address for new account
//
//                 this (llist *):
//                   The pointer to the llist object
//                   instance
//
//  Return values: 0 : This function was successful in adding
//                     a record
//                -1 : This function was not successful in 
//                     adding a record, since a record with
//                     its account number already exists
//
**************************************************************/  

int llist::addRecord(int accnumber, char uname[], char uaddress[])
{
    int looper = 1;
    int success = 0;
    struct record * front = this->start;
    struct record * hold = NULL;
    struct record * prev = NULL;

    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Parent class name: llist\n";
    cout << "Method name: addRecord\n";
    cout << "Parameter names and values:\n";
    cout << " - accnumber: " << accnumber << "\n";
    cout << " - uname (char[]): " << uname << "\n";
    cout << " - uaddress (char[]):\n" << uaddress;
    cout << " - this (llist *): " << this << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    if (front != NULL)
    {
        while (looper == 1)
        {
            if (accnumber < front->accountno)
            {
                if (front->next == NULL)
                {
                    hold = new record();
                    front->next = hold;
                    hold->accountno = accnumber;
                    strcpy(hold->name, uname);
                    strcpy(hold->address, uaddress);
                    hold->next = NULL;
                    looper = 0;
                }
                else
                {
                    prev = front;
                    front = front->next;
                }
            }
            else if (accnumber > front->accountno)
            {
                hold = new record();
                if (prev != NULL)
                {
                    prev->next = hold;
                }
                else
                {
                    start = hold;
                }
                hold->next = front;
                hold->accountno = accnumber;
                strcpy(hold->name, uname);
                strcpy(hold->address, uaddress);
                looper = 0;
            }
            else
            {
                success = -1;
                looper = 0;
            }
        }
    }
    else
    {
        this->start = new record();
        this->start->accountno = accnumber;
        strcpy(this->start->name, uname);
        strcpy(this->start->address, uaddress);
        this->start->next = NULL;
    }
    return success;
}

/*************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   If in debug mode, prints out its name,
//                 the name and datatypes of its parameters,
//                 and the value of its parameters. Uses an
//                 overloaded << operator to print out the
//                 contents of the llist object.
//
//  Parameters:    this (llist *):
//                   The pointer to the llist object instance
//
//  Return values: None (void)
//
************************************************************/

void llist::printAllRecords()
{
    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Parent class name: llist\n";
    cout << "Method name: printAllRecords\n";
    cout << "Parameter names and values:\n";
    cout << " - this (llist *): " << this << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    cout << (*this);
}

/**************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   If in debug mode, prints out its name,
//                 the name and datatypes of its parameters,
//                 and the value of its parameters. Takes
//                 in the value of its input parameters and
//                 looks for the record with the same
//                 account number as the inputted number,
//                 entering the list using the start pointer.
//                 If the inputted number does not correspond
//                 to any account, it instead returns an
//                 error value indicating that the account
//                 does not exist. If the list is empty,
//                 it returns an error value indicating
//                 such.
//
//  Parameters:    accnumber (int):
//                   The number of the account the user wants
//                   to retrive
//
//                 this (llist *):
//                   The pointer to the llist object instance
//
//  Return values:  0 : The account was successfully found
//                 -1 : The record is empty
//                  1 : The account does not exist
//
*************************************************************/

int llist::findRecord(int accnumber)
{
    struct record * hold = this->start;
    int success = 0;
    int iterator = 1;

    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Parent class name: llist\n";
    cout << "Method name: findRecord\n";
    cout << "Parameter names and values:\n";
    cout << " - accnumber (int): " << accnumber << "\n";
    cout << " - this (llist *): " << this << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    if (hold != NULL)
    {
        while (iterator == 1)
        {
            if (hold == NULL)
            {
                iterator = 0;
                success = 1;
            }
            else if (hold->accountno == accnumber)
            {
                cout << "\n~~~~~~~~~~~ Account Found ~~~~~~~~~~~\n";
                cout << "Account number: " << hold->accountno << "\n";
                cout << "Account user name: " << hold->name << "\n";
                cout << "Account user address:\n" << hold->address;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                iterator = 0;
            }
            else if (hold->accountno > accnumber)
            {
                hold = hold->next;
            }
            else
            {
                iterator = 0;
                success = 1;
            }
        }
    }
    else
    {
        success = -1;
    }
    return success;
}

/****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   If in debug mode, prints out its name,
//                 the name and datatypes of its parameters,
//                 and the value of its parameters. Deletes the
//                 account with the target user inputted account
//                 number (sets start to NULL if the
//                 account is the only record in the list).
//                 Returns an error if the list is empty
//                 or the account does not exist.
//
//  Parameters:    accnumber (int):
//                   The number of the account to be deleted
//
//                 this (llist *):
//                   The pointer to the llist object instance
//
//  Return values:  0 : This function ran successfully
//                 -1 : This function did not run successfully
//
****************************************************************/

int llist::deleteRecord(int accnumber)
{
    int success = 0;
    int looper = 1;
    struct record * prev = NULL;
    struct record * hold;
    struct record * front;

    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Parent class name: llist\n";
    cout << "Method name: deleteRecord\n";
    cout << "Parameter names and values:\n";
    cout << " - accnumber (int): " << accnumber << "\n";
    cout << " - this (llist *): " << this << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    if (start == NULL)
    {
        success = -1;
    }
    else
    {
        hold = this->start;

        while (looper == 1)
        {
            if (hold->accountno == accnumber)
            {
                if (prev == NULL)
                {
                    if (hold->next == NULL)
                    {
                        start = NULL;
                    }
                    else
                    {
                        start = hold->next;
                    }
                    delete hold;
                    looper = 0;
                }
                else
                {
                    prev->next = front;
                    delete hold;
                    looper = 0;
                }
            }
            else
            {
                if (hold->next == NULL)
                {
                    looper = 0;
                    success = 1;
                }
                else
                {
                    prev = hold;
                    hold = hold->next;
                    front = hold->next;
                }
            }
        }
    }
    return success;
}

/**************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   This function iteratively prints out
//                 the information from every struct record
//                 in the given list to a memory file
//
//  Parameters:    this (llist *):
//                   The pointer to the llist object instance
//
//  Return values: 0: This function ran successfully
//                -1: This function did not run successfully
//
**************************************************************/

int llist::writefile()
{
    ofstream file;
    struct record * hold = this->start;
    int success = 0;

    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Parent class name: llist\n";
    cout << "Method name: writefile\n";
    cout << "Parameter names and values:\n";
    cout << " - this (llist *)\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    file.open("memory.txt");

    if (file.is_open())
    {
        while (hold != NULL)
        {
            file << hold->accountno;
            file << '\n';
            file << hold->name;
            file << '\n';
            file << hold->address;
            file << '\n';
            hold = hold->next;
        }
        file.close();
    }
    else
    {
        success = -1;
    }

    return success;
}

/*************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   This function reads from a memory storage
//                 file (if one exists), and uses addRecord
//                 to continuously add records to the list
//                 using the information found in the
//                 memory file
//
//  Parameters:    this (llist *):
//                   The pointer to the llist object 
//                   instance
//
//  Return values: 0: The function ran successfully
//                -1: The function did not run successfully
//
*************************************************************/

int llist::readfile()
{
    ifstream file;
    int success = 0;
    int accnum = 0;
    int looper = 1;
    int iterator = 0;
    char accname[30];
    char accaddress[50];
    char c;
    char prevc = 0;

    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Parent class name: llist\n";
    cout << "Method name: readfile\n";
    cout << "Parameter names and values:\n";
    cout << " - this (llist *): " << this << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    file.open(this->filename);

    if (!file.is_open())
    {
        success = -1;
    }
    else
    {
        while (looper == 1)
        {
            if (!(file >> accnum))
            {
                looper = 0;
            }
            else
            {
                file.get();
                file.getline(accname, 30);

                looper = 2;
                while (looper == 2)
                {
                    c = file.get();

                    if (c == '\n' && prevc == '\n')
                    {
                        accaddress[iterator] = 0;
                        looper = 1;
                        iterator = 0;
                    }
                    else
                    {
                        accaddress[iterator] = c;
                        prevc = c;
                        iterator++;
                    }
                }
                addRecord(accnum, accname, accaddress);
            }
        }
        file.close();
    }
    return success;
}

/************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   This function deletes and deallocates the
//                 memory spaces of all struct records
//                 in the list
//
//  Parameters:    this (llist *):
//                   The pointer to the llist object
//                   instance
//
//  Return values: None (void)
//
************************************************************/

void llist::cleanup()
{
    struct record * hold = this->start;
    struct record * front;

    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Parent class name: llist\n";
    cout << "Method name: cleanup\n";
    cout << "Parameter names and values:\n";
    cout << " - this (llist *): " << this << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    while (hold != NULL)
    {
        front = hold->next;
        delete hold;
        hold = front;
    }
    this->start = NULL;
}

/**********************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   This is the constructor method for
//                 the llist class
//
//  Parameters:    this (llist *):
//                   The address of the object instance of
//                   the llist class
//
//  Return values: None
//
********************************************************/

llist::llist()
{
    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Parent class name: llist\n";
    cout << "Method name: llist\n";
    cout << "Parameter names and values:\n";
    cout << " - this (llist *): " << this << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    this->start = NULL;
    strcpy(this->filename, "memory.txt");
    readfile();
}

/***********************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   This is an overloaded constructor
//                 method for the llist class, taking
//                 in a string file name input and
//                 constructing an object instance
//                 with the information in that file
//
//  Parameters:    filenamein (char[]):
//                   The name of the file to be
//                   opened
//
//                 this (llist *):
//                   The address of the object instance of
//                   the llist class
//
//  Return values: None
//
*********************************************************/

llist::llist(char filenamein[])
{
    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Parent class name: llist\n";
    cout << "Method name: llist\n";
    cout << "Parameter names and values:\n";
    cout << " - filenamein (char []): " << filenamein << "\n";
    cout << " - this (llist *): " << this << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    this->start = NULL;
    strcpy(this->filename, filenamein);
    readfile();
}

/***********************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   This is an overloaded constructor
//                 method for the llist class, taking in
//                 a llist object reference input and
//                 constructing another object instance
//                 with the data stored in the referenced
//                 object
//
//  Parameters:    clist (llist &):
//                   The reference to the other llist
//                   object
//
//                 this (llist *):
//                   The address of the object instance of
//                   the llist class
//
//  Return values: None
//
**********************************************************/

llist::llist(llist & clist)
{
    struct record * iter = clist.start;

    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Parent class name: llist\n";
    cout << "Method name: llist\n";
    cout << "Parameter names and values:\n";
    cout << " - clist (llist &)\n";
    cout << " - this (llist *): " << this << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    this->start = NULL;
    strcpy(this->filename, clist.filename);

    while (iter != NULL)
    {
        addRecord(iter->accountno, iter->name, iter->address);
        iter = iter->next;
    }
}

/***********************************************************
//
//  Function name: ~llist
//
//  DESCRIPTION:   This is the destructor method for the
//                 llist class
//
//  Parameters:    this (llist *):
//                   The address of the object instance
//                   of the llist class
//
//  Return values: None
//
*********************************************************/

llist::~llist()
{
    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Parent class name: llist\n";
    cout << "Method name: ~llist\n";
    cout << "Parameter names and values:\n";
    cout << " - this (llist *): " << this << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    writefile();
    cleanup();
}

/***********************************************************
//
//  Function name: operator=
//
//  DESCRIPTION:   This is the overloaded equals operator
//                 which is used when equating an llist
//                 object instance with another llist
//                 object
//
//  Parameters:    clist (const llist &):
//                   The const reference to the other
//                   llist instance to be copied
//
//                 this (llist *):
//                   The address of the object instance
//                   of the llist class
//
//  Return values: llist&
//
********************************************************/

llist& llist::operator=(const llist & clist)
{
    struct record * iter = clist.start;

    #ifdef DEBUGMODE
    cout << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    cout << "Parent class name: llist\n";
    cout << "Method name: operator=\n";
    cout << "Parameter names and values:\n";
    cout << " - clist (const llist &)\n";
    cout << " - this (llist *): " << this << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    strcpy(this->filename, clist.filename);
    cleanup();

    while (iter != NULL)
    {
        addRecord(iter->accountno, iter->name, iter->address);
        iter = iter->next;
    }

    return (*this);
}

/*********************************************************
//
//  Function name: operator<<
//
//  DESCRIPTION:   This is the overloaded << operator
//                 for the ostream class
//
//  Parameters:    out (ostream &):
//                   The reference to the output stream
//                   object
//
//                 plist (const llist &):
//                   The reference to the llist object
//                   to be printed
//
//  Return values: ostream&:
//                   The referenced output stream
//                   object
//
*******************************************************/

ostream& operator<<(ostream & out, const llist & plist)
{
    struct record * iter = plist.start;

    #ifdef DEBUGMODE
    out << "\n\n~~~~~~~~~~Debug Mode Output~~~~~~~~~~\n";
    out << "Parent class: ostream\n";
    out << "Method name: operator<<\n";
    out << "Parameter names and values:\n";
    out << " - stream (ostream &)\n";
    out << " - plist (const llist &)\n";
    out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    #endif

    if (iter == NULL)
    {
        out << "\nThe database is currently empty\n\n";
    }

    while (iter != NULL)
    {
        out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        out << "Account number: " << iter->accountno << "\n";
        out << "Account username: " << iter->name << "\n";
        out << "Account user address:\n" << iter->address;
        out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

        iter = iter->next;
    }

    return out;
}
