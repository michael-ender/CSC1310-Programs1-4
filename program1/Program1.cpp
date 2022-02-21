/*************************************************
 * File Name:       Program1.cpp
 * Author:          Michael Steets
 * Date Created:    02/8/21
 * Date Modified:   02/18/21
 * Purpose:         Adding Videogames to Library
 * **********************************************/

#include "VideoGameLibrary.h"
#include <iostream>
#include <fstream>
using namespace std;

int main () {

    int choice, maxNum;
    string path;
    ofstream outFile;
    ifstream inFile;

    cout << "How many video games can your library hold?\n";            //First quesion is to ask the user how many videogames their library can hold before going into the loop
    cin >> maxNum;
    while (maxNum < 0){
        cout << "\nINVALID CHOICE! Maximum number must be above 0\n";   //The number for maxNum cannot be zero
        cin >> maxNum;
    }

    videoGameLibrary* randomLibrary = new videoGameLibrary(maxNum);     //This dynamically allocates a library from videoGameLibrary class

    do {
        cout << "What would you like to do?\n";                         //All the functions get called from videoGameLibrary initially
        cout << "1. Load video games from file.\n";                     // even if to call other functionsfrom other classes
        cout << "2. Save vdeo games to a file.\n";
        cout << "3. Add a videogame.\n";
        cout << "4. Remove a video game.\n";
        cout << "5. Display all video games.\n";
        cout << "6. Remove ALL video games from this library and end program.\n";
        cout << "CHOOSE 1-6:\n";
        cin >> choice;
        while (choice < 1 || choice > 6){
            
            cout << "\nINVALID INPUT! Choose 1-6:   ";
            cin >> choice;
        }
        switch (choice) {
            case 1:
                cout << "\nWhich file would you like to pull videogames from? (example.txt) \n";              //Pulls videogames from a file and puts it into the library
                cin >> path;
                randomLibrary->loadVideoGamesFromFile(path);          //Calls for the loadVideoGamesFromFile function in videoGameLibrary
                break;
        
            case 2:
                cout << "\n\nWhat do you want to name the file? (example.txt): ";       //Saves videogames and puts it into a separate text file
                cin >> path;
                randomLibrary->saveToFile(path);                                        //Calls for the saveToFile function in videoGameLibrary
                cout << "\nAll video games in your library have been printed to " << path << endl;
                break;

            case 3: 
                randomLibrary->addVideoGameToArray();               //Allows the user to enter one videogame to their library
                break;

            case 4:
                randomLibrary->removeVideoGameFromArray();          //Allows the user to delete one vidogame from their library 
                break;

            case 5:
                randomLibrary->displayVideoGames();                 //Displays all the current videogames in the library
                break;

            case 6:
                delete randomLibrary;                               //deletes all the videogames in the library and closes out of the loop
        }
    }while(choice != 6);

    cout << "\nGOODBYE!\n";

    inFile.close();

    return 0;
}