#include <iostream>

using namespace std;

/*************************************************
 * File Name:       Text.h
 * Author:          Michael Steets
 * Date Created:    02/8/21
 * Date Modified:   02/18/21
 * Purpose:         Header File for Text Class
 * ***********************************************/

#ifndef TEXT_H
#define TEXT_H

class Text {
    
    private:                    //Attributes for Text class
        int textLength;    
        const char *textArray;

    public:
        Text () {              //Default constructor

        }   
        
        Text(const char *textArray);        //Constructor  
        ~Text();                            //Destructor
        void displayText();
        const char* getText() const;
        int getLength() const;
};

#endif