/***********************************************
 * File Name:       Text.cpp
 * Author:          Michael Steets
 * Date Created:    02/8/21
 * Date Modified:   02/18/21
 * Purpose:         Functions for Text Class
 * *********************************************/

#include "Text.h"
#include <iostream>
#include <cstring>
using namespace std;

    Text::Text(const char *myText){             //Constructor for Text
        textLength = strlen(myText);            //Length of parameter
        char* tempArr = new char[textLength+1]; //Creates a temporary array for new items to then be transferred into the textArray
        strcpy(tempArr, myText);                //Copies myText into tempArr
        textArray = tempArr;
    }

    Text::~Text(){
        delete [] textArray;                    //Destructor for Text
        cout << "\nText destructor: Released memory for textArray.";
        //DESTROYS TEXT
    }

    void Text::displayText(){                   //Displays either a line of text or multiple lines of text depending on the function that calls this function
        cout << textArray;
    }

    const char* Text::getText() const{          //Returns text that the user entered or got from file
        return textArray;
    }

    int Text:: getLength() const{               //Returns the length of an array of text
        return textLength;
    }