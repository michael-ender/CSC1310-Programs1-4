/**********************************************************
 * File Name:       VideoGameLibrary.h
 * Author:          Michael Steets
 * Date Created:    02/8/21
 * Date Modified:   02/18/21
 * Purpose:         Header file for VideoGameLibrary class
 * ********************************************************/

#include "Text.h"
#include "VideoGame.h"
#include <iostream>
#include <fstream>
#ifndef VIDGAMELIB_H
#define VIDGAMELIB_H

using namespace std;

class videoGameLibrary {
   
    private:
        int maxGames, numGames;                 //videoGameLibrary attributes 
        VideoGame** videoGamesArray;
        
    public:  
        void resizeVideoGameArray();
        videoGameLibrary(int);              //Constructor
        ~videoGameLibrary();                //Deconstructor
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(string);
        void removeVideoGameFromArray();
        void saveToFile(string);
};

#endif