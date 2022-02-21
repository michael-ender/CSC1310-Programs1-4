/*******************************************************
 * File Name:       VideoGameLibrary.cpp
 * Author:          Michael Steets
 * Date Created:    02/8/21
 * Date Modified:   02/18/21
 * Purpose:         Functions for VideoGameLibary class
 * *****************************************************/

#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "Text.h"
#include <iostream>
#include <fstream>
using namespace std;

void videoGameLibrary::resizeVideoGameArray(){              //Resizes the maxNum to double it if the max is reached
    VideoGame** dbl = new VideoGame* [maxGames*2];          //Dynamically allocates a new temp array to put videoGameArray into
    for(int i = 0; i < maxGames; i++){
        dbl[i] = videoGamesArray[i];
    }
    delete [] videoGamesArray;                              //Deletes the current information in videoGameArray to make sure there's no memory leak
    videoGamesArray = dbl;                                  //The information in dbl goes to videoGameArray;
    cout << "Array has been resized from " << maxGames << " to " << maxGames*2 << endl;
    maxGames = maxGames*2;
}

videoGameLibrary::videoGameLibrary(int max){                //Constructor for videoGameLibrary
    this->numGames = 0;
    this->maxGames = max;
    videoGamesArray = new VideoGame*[max];
}

videoGameLibrary::~videoGameLibrary(){                      //Destructor for videoGameLibrary
    for (int i = 0; i < numGames; i++){
        delete videoGamesArray [i];
    }    
    delete [] videoGamesArray;
    cout << "\nVideoGameLibrary destructor: Released memory for each game in the video game array and the array itself.";
}

void videoGameLibrary::addVideoGameToArray(){               //Adds one videogame to the videogame library
    char temp[10000];
    Text *myTitle, *myPlatform, *myGenre, *myAgeRating;
    int myYear;
    float myUserRating;

    cin.ignore();
    cout << "\nVideo Game TITLE: ";
    cin.getline(temp, 10000);
    myTitle = new Text(temp);
    cout << "\n\nVideo Game PLATFORM: ";
    cin.getline(temp, 10000);
    myPlatform = new Text(temp);
    cout << "\n\nVideo Game YEAR: ";
    cin >> myYear;
    cin.ignore();
    cout << "\n\nVideo Game GENRE: ";
    cin.getline(temp, 10000);
    myGenre = new Text(temp);
    cout << "\n\nVideo Game AGE RATING: ";
    cin.getline(temp, 10000);
    myAgeRating = new Text(temp);
    cout << "\n\nVideo Game USER RATING (out of 100): ";
    cin >> myUserRating;
    while (myUserRating < 0 || myUserRating > 100){
        cout << "\nNumber must be between 0 and 100\n\n";
        cout << "Video Game USER RATING (out of 100): ";
        cin >> myUserRating;
    }
    cin.ignore();

    VideoGame* newVideoGame = new VideoGame(myTitle, myPlatform, myYear, myGenre, myAgeRating, myUserRating);       //Dynamically allocates a temporary array to be stored into videoGameArray

    if (numGames == maxGames) {                         //Calls the resize function to double the size of the array if numGames is equal to maxGames
        videoGameLibrary::resizeVideoGameArray();
    }   

    videoGamesArray[numGames] = newVideoGame;

    ++numGames;
}

void videoGameLibrary::displayVideoGames(){                 //Calls a function in VideoGame.cpp that prints out ALL the videogame information in the library
    for (int i = 0; i < numGames; i++){
        cout << "               ---------- Video Game " << i+1 << " ----------\n";
        videoGamesArray[i]->printVideoGameDetails();
    }
}

void videoGameLibrary::displayVideoGameTitles(){           //Prints out the title for the videogames
    for(int i = 0; i < numGames; i++){
        cout << i+1 << ": ";
        videoGamesArray[i]->getVideoGameTitle();
        cout << endl;
    }    

}

void videoGameLibrary::loadVideoGamesFromFile(string file) {        //Loads videogames from files and puts it into the videogame library
    
    Text *myTitle, *myPlatform, *myGenre, *myAgeRating;
    int myYear;
    float myUserRating;   
    
    char temp[10000];
    int tracker;
    ifstream inFile;

    inFile.open(file.c_str());

    if (inFile.good()){
        while (!inFile.eof()){
            inFile.getline(temp, 10000);
            myTitle = new Text(temp);
            inFile.getline(temp, 10000);  
            myPlatform = new Text(temp);
            inFile >> myYear;   
            inFile.ignore();         
            inFile.getline(temp, 10000);
            myGenre = new Text(temp);
            inFile.getline(temp, 10000);
            myAgeRating = new Text(temp);
            inFile >> myUserRating;
            inFile.ignore();


            VideoGame* newVideoGame = new VideoGame(myTitle, myPlatform, myYear, myGenre, myAgeRating, myUserRating);

            myTitle->displayText();
            cout << " has been added to the video game library!\n";

            videoGamesArray[numGames] = newVideoGame;

            ++numGames;
            ++tracker;

            if (numGames == maxGames) {
                videoGameLibrary::resizeVideoGameArray();
            }                 
        }
    }
    else 
        cout << "\nSorry, I was unable to open the file.\n\n"; 

    inFile.close();

    cout << tracker << " video games were added from the file and added to your VideoGame library.\n\n";
}

void videoGameLibrary::removeVideoGameFromArray(){              //Removes one videogame from the videogame library
    int remove;
    Text *myTitle, *myPlatform, *myGenre, *myAgeRating;
    int myYear;
    float myUserRating;
    
    if (numGames > 0){
        videoGameLibrary::displayVideoGameTitles();
        cout << "\nChoose a videogame to remove between 1 & " << numGames << ": ";
        cin >> remove;
        videoGamesArray[remove-1]->getVideoGameTitle();
        cout << " has been removed.\n";
        delete videoGamesArray[remove-1];
        int numElemMoveBack = numGames-1;
        for (int i = remove-1; i < numElemMoveBack; i++){
            videoGamesArray[i]=videoGamesArray[i+1];
        }
        videoGamesArray[numElemMoveBack] = NULL;
        --numGames;
    }
    else   
        cout << "\nThere are no videogames to remove\n\n";
}

void videoGameLibrary::saveToFile(string path){         //Saves all videogames in the library to a text file
    ofstream outFile;

    outFile.open(path.c_str());
    for (int i = 0; i < numGames; i++){
    videoGamesArray[i]->printVideoGamesDetailsToFile(outFile);
    }
    outFile.close();

}