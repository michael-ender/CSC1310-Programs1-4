/**************************************************
 * File Name:       VideoGame.cpp
 * Author:          Michael Steets
 * Date Created:    02/8/21
 * Date Modified:   02/18/21
 * Purpose:         Functions for VideoGame class
 * ************************************************/

#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

VideoGame::VideoGame(Text* title, Text* platform, int year, Text* genre, Text* ageRating, float userRating){        //Constructor for VideoGame class
    this->title = title;
    this->platform = platform;
    this->year = year;
    this->genre = genre;
    this->ageRating = ageRating;
    this->userRating = userRating;
}

VideoGame::~VideoGame() {       //Destructor for VideoGame class
    delete title;
    delete platform;
    delete genre;
    delete ageRating;
    cout << "\nVideoGame destructor: Released memry for title, platform, genre, and age rating.";
}

void VideoGame::printVideoGameDetails (){       //Prints all the information currently in the library (called from displayVideoGames in videoGameLibrary)
    cout << "       Game Title: ";
    title->displayText();
    cout << endl;
    cout << "       Platform: ";
    platform->displayText();
    cout << endl;
    cout << "       Year Released: ";
    cout << year << endl;
    cout << "       Genre: ";
    genre->displayText();
    cout << endl;
    cout << "       Rating: ";
    ageRating->displayText();
    cout << endl;
    cout << "       Number of Stars: ";
    cout << userRating << endl;
}

void VideoGame::printVideoGamesDetailsToFile (ofstream& outFile) {          //Prints all the information in a library into a file (called from saveToFile in videoGameLibrary)
    char temp[1000];

    strncpy(temp, title->getText(), 1000);
    outFile << temp << endl;
    strncpy(temp, platform->getText(), 1000);
    outFile << temp << endl;
    outFile << year << endl;
    strncpy(temp, genre->getText(), 1000);
    outFile << temp << endl;
    strncpy(temp, ageRating->getText(), 1000);
    outFile << temp << endl;
    outFile << userRating << endl;
}

void VideoGame::getVideoGameTitle () const {                //Displays the title of a videogame
    title->displayText();
}