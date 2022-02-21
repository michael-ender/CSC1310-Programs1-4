/**********************************************************************
	Title:          Program4.cpp
	Author:         Michael Steets
	Date Created:   4/20/21
	Purpose:        Calls GraphList.h and GraphMatrix.h and uses the
                    functions inside the print matrixes and lists
***********************************************************************/
#include "GraphList.h"
#include "GraphMatrix.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    int numVertices;
    int v1, v2;
    string file;
    ifstream inFile;
    int topVertex;
    int first = 0;

    //User enters file name
    cout << "What file are you printing a graph from?\n";
    cout << "Enter file name: ";
    getline(cin, file);

    inFile.open(file);
    if(!inFile) {
        cout << "Could not open file";
        exit(1);
    }

    //first number in file is the number of vertices in the graph
    inFile >> numVertices;
    cout << "Number of vertices added: " << numVertices << endl;

    GraphList myGraphList(numVertices);    
    GraphMatrix myGraphMatrix(numVertices);

    //adds vertices to the list and matrix
    while (inFile >> v1) {
        inFile >> v2;
        myGraphList.addEdge(v1, v2);
        myGraphMatrix.addEdge(v1, v2);
    }

    //prints the list and matrix
    cout << endl;
    myGraphMatrix.printGraph();
    myGraphList.printGraph();

    Stack<int> DFS;
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++){
        visited[i] = false;
    }

    cout << "\nNow traversing and printing graph vertices with DFS.\n\n";
    int currentV;
    DFS.push(first);
    cout << first << "  ";
    while (!DFS.isEmpty()){                                                         //loops through to make sure the stack isn't empty
        DFS.peek(currentV);
        bool restart = false;
        if (visited[currentV] != true)                                              //makes sure to "visit" nodes that haven't been visited yet
            visited[currentV] = true;
        for (int i = 0; i < numVertices || restart == true; ++i) {                  //loops through graph and restarts if a node is found and equal to true
            if (restart == true){
                i = 0;
                restart = false;
            }
            if (myGraphMatrix.isThereAnEdge(currentV, i) && !visited[i]) {
                DFS.push(i);
                visited[i] = true;
                cout << i << "  ";
                currentV = i;
                restart = true;
            }
        }
        DFS.pop(currentV);                                                          //pops value off stack
    }
    cout << endl;

    inFile.close();

    return 0;
}