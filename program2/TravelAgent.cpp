/**********************************************************************
	Title:          TravelAgent.cpp
	Author:         Michael Steets
	Date Created:   2/28/2021
    Date Modified:  2/28/2021
	Purpose:        Contains the main function and any additional
                    functions you created to make the program run
***********************************************************************/
#include "Destination.h"
#include "LinkedList.h"

#include <iostream>
#include <fstream>
#include <limits>
#include <ctime>
using namespace std;

void Gavin ();
//void enterPlacesFromFile(&list);

int main() {

    LinkedList<Destination*> list;

    ifstream inFile;
    string path = "placeFile.txt";
    string temp;
    string response;
    float response1;
    char response2 , response3;
    string name, desc;
    float cost;
    int danger, randomNum;

    srand(time(0));

    inFile.open(path.c_str());
    if(!inFile){
        cout << "\nUnable to open this file.\n";
    }
    else {    
        //enterPlacesFromFile(&list);
        while(getline(inFile, temp, '#')) {
            name = temp;
            getline(inFile, desc, '#');
            getline(inFile, temp, '#');
            cost = stof(temp);
            getline(inFile, temp, '#');
            danger = stoi(temp);
            Destination* places = new Destination(name, desc, cost, danger);
            list.insertNode(places);
        }
    }
// I pass in *list, list->insertNode(param)
    cout << "\n\nHello!  My name is Gavin O Cleirigh and I am your professional travel agent, tour director, and guide!\n";
    Gavin();
    cout << endl;

    //cout << "pizza " << list.getLength() << endl;   //Problem here

    for(int i = 0; i < list.getLength(); ++i){                                                          //Lists all the destinations readily available to choose
        cout << "************************** DESTINATION " << i+1 << " **************************\n";
        cout << *(list.getNodeValue(i));
    }

    cout << "\nPlease answer the following four questions and I will determine the place you should travel.\n";     //Question 1
    cout << "   What is your full name?\n";
    getline(cin, response);            
    while(!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nOops! You entered something wonky. Please enter your full name:";
        cin >> response;
    }

    cout << "   \nHow much money do you make per year?\n";                                                          //Question 2
    cin >> response1;
    while(!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                       
        cout << "\nOops! You entered something wonky. Please enter your salary:";
        cin >> response1;
    }

    cout << "   \nIf I asked nicely, would you show me your social security numbers? (y or n)\n";                   //Question 3
    cin >> response2;
    while(!cin || (response2 != 'n' && response2 != 'y'))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                       
        cout << "\nOops! You entered something wonky. Please enter in y or n:";
        cin >> response2;
    }
    
    cout << "   \nWill you go to prom with me? (y or n)\n";                                                         //Question 4
    cin >> response3;
    while(!cin || (response3 != 'n' && response3 != 'y'))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                       
        cout << "\nOops! You entered something wonky. Please enter in y or n:";
        cin >> response3;
    }

    //Statement that prints what the user put in the questions
    cout << endl;
    cout << response << ", based on your salary (" << response1 << ") and the fact that you ";
    if (response3 == 'y')
        cout << "will";
    else
        cout << "won't";
    cout << " give us your social security numbers, and that you ";
    if (response2 == 'y')
        cout << "will";
    else    
        cout << "won't";
    cout << " go to prom with me, you are going to travel to the folowing Destination!\n\n";
    
    //Destination output (randomly based)
    randomNum = rand() % list.getLength() + 1;
    if (randomNum == 1)
        cout << *(list.getNodeValue(0));
    else if (randomNum == 2)
        cout << *(list.getNodeValue(1));
    else if (randomNum == 3)
        cout << *(list.getNodeValue(2));
    else if (randomNum == 4)
        cout << *(list.getNodeValue(3));
    else if (randomNum == 5)
        cout << *(list.getNodeValue(4));
    else if (randomNum == 6)
        cout << *(list.getNodeValue(5));
    else if (randomNum == 7)
        cout << *(list.getNodeValue(6));

    //print the place here after doing srand() and stuff
    cout << "\nHAVE FUN!\n";

    return 0;
}

void Gavin () {
    cout << "                                                                                        (//#&%####/#(*,\n";                                                                                              
    cout << "                                                                                    #((%%%&%&&%&@%%%%%%(\n";                                                                                           
    cout << "                                                                                   (&#%%%%%%%%&&##%%#(###/\n";                                                                                          
    cout << "                                                                                  #%%&(////**,,*,,,....,*&#\n";                                                                                         
    cout << "                                                                                  %&%**,,,...............,((,\n";                                                                                       
    cout << "                                                                                  ##(**,,,................/(/\n";                                                                                       
    cout << "                                                                                 ((/**,,,,...............*(/\n";                                                                                       
    cout << "                                                                                 .%(*/##(((/*,,...,*////*..//\n";                                                                                       
    cout << "                                                                                 *(/(***(#%////*..*/(((/*,..(,/\n";                                                                                      
    cout << "                                                                                 //,,,,,**,,,*,..,,,,,,.,..,,\n";                                                                                       
    cout << "                                                                                 ,***,,....,*,...,,........,\n";                                                                                        
    cout << "                                                                                  .****,,,**/(,,,**,,,..,...\n";                                                                                        
    cout << "                                                                                    ********,,*,,,,,,,*,,,\n";                                                                                          
    cout << "                                        ...                                         ***,,/@/.....,,&/*,,,,\n";                                                                                          
    cout << "                                       *,,..                                        .//*,**///*//**,,,,,,\n";                                                                                           
    cout << "                                        *,,,.                                     *(,,//,,,,,,,,,,,,,.,,                                                        ..,\n";                                 
    cout << "                                        /*,,.                               ,***////(..,//*,,,,,,,,,,**  ,,..                                                  ,,.,\n";                                 
    cout << "                                        /*,,.                      ,,,,,,,,,*,,,**///(...,,,*******/     ,.,***,,,,,,,,,,,,.,                                 ,,,,,\n";                                 
    cout << "                                ,*,,,... .....            ,*,,,,,,,,,,,,,,,,*,,*****//*......%@&&&&%&&(  *,,,,,,,,,,,,,,,,,,,/,                              ,,,,,\n";                                  
    cout << "                              .....,(*,,.......           %/(*,,,,,,,,,,,,,,,,/,,,,*****.,*.  ..&&&%&  .,**,,,,,,,,,,,,,,,,,,,,,.                            ,,,,.,,.......\n";                          
    cout << "                             /**,,....(*,......        .***,,,,,,,,,,,,,,,,**,*,,,*****.. ... ..,&%%.  . *,,,,,,,,,,,,,,,,,,,,**/,.                        ,,,,,,,.........\n";                         
    cout << "                            ..,,,*,,,.....,,,,,.      ,,,,,,***,*,,,,,,,,,,,,,,,,,,*,****      ..#&%#%/   /,,,,,,,,,,,,*,,,,,,/(,*,*,,                     *,,,,*,,*,.,,....,,\n";                       
    cout << "                           ****,,,./,,,,,,,,,,     ,****,//*,,*/,,***,,,*,,,*,,,,,,,****     .  &&%##%%  .*,,,,,,,,,,,*,,,,,*/**,,.,,,,.                  **,,,**/,.....,.,..\n";                       
    cout << "                          *,,,//*,,,.....,,# ,    /**,,/(*,,,(***,,*,,,*.,,,,,,,(,,,,***.      .&%%####.  /,,,,,,,,,,,*,*,*,*/,*,*,,,,,,,,**/          */ /**,,*****,,,*...,,.\n";                      
    cout << "                           .***,,,//,,,,*   .*, #,,,,,,,,,,,#**%/,,,*/*,,,,,,,,,,(,,,****      .&%%####% .,,,,,,,,,,,,,***,,,*,,****,,,,,,,,,,,*,,,,***/# (*******,*,...,..,..\n";                 
    cout << "                             @***,,,,.  .,******#(,,,,,/(*,,,,**/*,*,/**,,,,,,,,,*,,,,***       &%######  ,*,,,,,*,,,,,,*/***///,,,***,,,/*******/*//////.##/**,,*****/....,,\n";                       
    cout << "                            ##@,.., ....,/**/**//*,,,,,,,,,,.%*,#*,*//**,,,,**,,,,/,,,,**,      *%##%%##% .*,,,,*,,,*,**,****(***///*/******/*/*/////(/(((..#(((/***,**,,.\n";                          
    cout << "                            #%@@@(, */#&*////**,,,,,,,,,,,,**,*,#/**/****,,,,,****,#,,,,**      .%##%##%%../,,,,**,,******,*/(#(((((////*//(//////(//////((&*. %@&((/.\n";                       
    cout << "                            .(@@@@@@&*//*/////**,*,/***,****,***#(*/******,,,,,*****#,,,,*       %%%###%%../,,,,**,*******///#(((((#(/////(////////////(/////@@&,.../\n";                               
    cout << "                             ,%/***////////////****%**/,,***///(%(((/*******,,***,***(,,,**      %%#%%####./*,,,**********//*  ***/(////(((/(//////////(//////%@@&@&%\n";                               
    cout << "                              ##///////////////***(***,*/////(( /##((//**************(*,,,*      %%%%%%%%% ,*,,**********///,          .***/////////////////***,.\n";                                   
    cout << "                               /(/////((///////***/**///////.    /##(//******,*,****,*/,,**      &%%%%%%%% ***,**********//*\n";                                                                        
    cout << "                                 ((//((//(///////*////((*         /#(////*************/#,**.     #%%%%%%(%/***,********///**\n";                                                                        
    cout << "                                  /////////////*////(/*           /#((///**************/%,*,     /%%%%%%%%#,/********//////*\n";                                                                        
    cout << "                                    ////////,*(((*                /(((///**************/(%**...  ,%(%%%%%%%,(*********////,/\n";                                                                        
    cout << "                                                                  /((////***************/#(*    .,%%%%%%%%%,/*******/*///***.\n";                                                                       
    cout << "                                                                  /((/////**************/(#*,.  .,&%%%%%%&&.,/********//**//.\n";                                                                       
    cout << "                                                                  (((/////***************/(#,....,&%%#%%%%&*.///*****///*///\n";                                                                        
    cout << "                                                                 /(((//////***************/(/  ..,&%%%%%%%&%./*/*****///*//*.\n";                                                                       
    cout << "                                                                 ((((/////*****************#*. ..,&%%%%%%%&&..(***//*///**//,\n";                                                                       
    cout << "                                                                *#((((///***********,****/(# ....,&%%%%%&%&&...*/*****///*/*,*\n";                                                                      
    cout << "                                                                (((((////****************///   ..,&%%%&&&&&&...,//////////**,%\n";                                                                      
    cout << "                                                               ((((((////****************//* .. .,&%%&&&&&&& .,,//*////////*,,,\n";                                                                     
    cout << "                                                              /#%#((((/////********/******/.   ...&&&&%&&&&& ...*//////////*,*,\n";                                                                     
    cout << "                                                              (((/##//***///******/*******/     ....&&&&&&.   ..,(*////////*,,,\n";                                                                     
    cout << "                                                            /((/(((((////,//**/*/**/**/*/.       ....,(       .,/#***/*///*,,,.\n";                                                                    
    cout << "                                                             (/(((/****//////*////**//*///             ..      ..,(////////*,,.,\n";                                                                    
    cout << "                                                             (/(((*****//***////****//(//.,               .   ....*(/////*/*,,*,\n";                                                                    
    cout << "                                                            /#/((((((/****/////////////**.....       .............**(////,/*,,,*\n";                                                                   

};

