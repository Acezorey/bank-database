/****************************************************************
//
//  NAME:        Ace Reyes
//
//  Homework:    project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 27, 2023
//
//  FILE:        record.h
//
//  DESCRIPTION: 
//    This file contains the definition of a struct record
//  
**************************************************************/

#ifndef RECORD
#define RECORD
struct record
{
    int accountno;
    char name[30];
    char address[50];
    struct record * next;
};
#endif
