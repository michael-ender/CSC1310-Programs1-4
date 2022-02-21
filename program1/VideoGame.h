/***************************************************
 * File Name:       VideoGame.h
 * Author:          Michael Steets
 * Date Created:    02/8/21
 * Date Modified:   02/18/21
 * Purpose:         Header file for VideoGame class
 * *************************************************/

#include <iostream>
#include <fstream>
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

using namespace std;

class VideoGame {

    private:
        Text *title, *platform, *genre, *ageRating;         //VideoGame attributes
        int year;
        float userRating;

    public:
        VideoGame () {              //Default constructor

        };

        VideoGame(Text*, Text*, int, Text*, Text*, float);      //Constructor
        ~VideoGame();                                           //Destructor 
        void printVideoGameDetails ();
        void printVideoGamesDetailsToFile (ofstream &outFile);
        void getVideoGameTitle () const;
};

#endif