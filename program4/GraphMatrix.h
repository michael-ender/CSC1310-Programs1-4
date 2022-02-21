/**********************************************************************
	Title:          GraphMatrix.h
	Author:         Michael Steets
	Date Created:   4/20/21
	Purpose:        Class with functions to create a matrix of adjacent
                    numbers.
***********************************************************************/

#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
#include <iostream>
using namespace std;

class GraphMatrix {
    private:
        int** vertexMatrix;
        int numVertices;
        int numEdges;
    public:
        GraphMatrix(int verts) {
            numVertices = verts;
            numEdges = 0;
            vertexMatrix = new int*[numVertices];
            for (int i = 0; i < numVertices; i++){
                vertexMatrix[i] = new int[numVertices];
            }
            for (int i = 0; i < numVertices; i++) {
                for (int x = 0; x < numVertices; x++) {
                    vertexMatrix[i][x] = 0;
                }
            }
        }

        ~GraphMatrix() {
            for (int i = 0; i < numVertices; ++i) {
                delete [] vertexMatrix[i];
            }
            delete [] vertexMatrix;
        }

        void addEdge (int v1, int v2){
            if (vertexMatrix[v1][v2] == 0) {
                ++numEdges;
            }
            vertexMatrix[v1][v2] = 1;
        }

        void printGraph() {
            cout << "Adjacency Matrix" << endl;
            for (int i = 0; i < numVertices; i++) {
                for (int x = 0; x < numVertices; x++){
                    cout << vertexMatrix[i][x] << " ";
                }
                cout << endl;
            }
        }

        bool isThereAnEdge(int v1, int v2) {
            if (vertexMatrix[v1][v2] == 1) {
                return true;
            }
            else
                return false;
        }

};

#endif