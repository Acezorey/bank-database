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
//  FILE:        llist.h
//
//  DESCRIPTION:
//   Within this header file is the definition of the llist
//   class
//
****************************************************************/

#ifndef LLIST
#define LLIST

using namespace std;

class llist
{
    private:
    record * start;
    char filename[20];
    int readfile();
    int writefile();
    void cleanup();

    public:
    llist();
    llist(char[]);
    llist(llist&);
    ~llist();
    int addRecord(int, char[], char[]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
    llist& operator=(const llist&);
    friend ostream& operator<<(ostream&, const llist&);
};
#endif
