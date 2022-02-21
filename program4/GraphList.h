/**********************************************************************
	Title:          GraphList.h
	Author:         Michael Steets
	Date Created:   4/20/21
	Purpose:        Class with function to print out a list of adjacent 
                    numbers
***********************************************************************/

#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include <iostream>
using namespace std;

class GraphList {
    private:
        struct ListNode {
            int value;
            ListNode* next;
        };

        ListNode** headArray;
        int numVertices;
        int numEdges;

    public:
        GraphList (int verts) {
            numVertices = verts;
            numEdges = 0;
            headArray = new ListNode*[numVertices];
            for (int i = 0; i < numVertices; i++) {
                headArray[i] = NULL;
            }
        }

        ~GraphList () {
            ListNode *nodePtr;
            ListNode *nextPtr;
            for (int i = 0; i < numVertices; ++i) {
                delete headArray[i];
            }
            delete [] headArray;
        }

        void addEdge (int v1, int v2) {
            ListNode* newNode;
            newNode = new ListNode;
            newNode->value = v2;
            newNode->next = NULL;
            ++numEdges;

            ListNode* temp = headArray[v1];

            if (temp == NULL) {
                headArray[v1] = newNode;
            }
            else {
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void printGraph() {
            cout << endl;
            cout << "Adjacency List..." << endl;
            ListNode *nodePtr;
            for (int i = 0; i < numVertices; ++i) {
                nodePtr = headArray[i];
                bool isEntry = false;
                cout << i << "--->";
                while (nodePtr != NULL){
                    isEntry = true;
                    cout << nodePtr->value << "--->";
                    nodePtr = nodePtr->next;
                    if(nodePtr == NULL) {
                        cout << "NULL" << endl;
                    }
                }
                if (isEntry == false) {
                    cout << "NULL" << endl;
                }
            }
        }

};

#endif