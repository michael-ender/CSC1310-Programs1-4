/**********************************************************************
	Title:          LinkedList.h
	Author:         Michael Steets
	Date Created:   2/28/2021
    Date Modified:  2/28/2021
	Purpose:        header file containing your LinedList
                    template class
***********************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template<typename T>
class LinkedList {
    private:
        struct LinkNode {
            T value;
            struct LinkNode* next;
        };

        LinkNode* head;
        LinkNode* tail;
        int numNodes;
    public:
        LinkedList(){         //Constructor
            head = NULL;
            tail = NULL;
            numNodes = 0;
        }

        ~LinkedList() {         //Destructor
            LinkNode *nodePtr;
            LinkNode *nextNode;

            nodePtr = head;

            while (nodePtr != NULL) {
                nextNode = nodePtr->next;
                delete nodePtr;
                nodePtr = nextNode;
            }
        }

        int getLength();
        T getNodeValue(int position);
        void insertNode(T place);
};

template<typename T>
int LinkedList<T>::getLength() {                 //Returns the number of items in the list
    LinkNode *nodePtr;

    nodePtr = head;
    numNodes = 0;
    while (nodePtr != tail){
        numNodes++;
        nodePtr = nodePtr->next;
            if (nodePtr == tail)
                numNodes++;
    }

    return numNodes;
};

template<typename T>                       //Returns the value of a node
T LinkedList<T>::getNodeValue(int pos) {
    LinkNode *nodePtr;
    int orig_pos = 0;

    if(head != NULL) {
        nodePtr = head;
        while (nodePtr != NULL && pos != orig_pos) {
            nodePtr = nodePtr->next;
            ++orig_pos;
        }        
    }
    else {
        cout << "There are no nodes to print.\n\n";
    }
    return nodePtr->value;
}

template<typename T>
void LinkedList<T>::insertNode(T place) {
    LinkNode *nodePtr;
    LinkNode *newNode;
    LinkNode *prevNode;

    newNode = new LinkNode;
    newNode->value = place;
    newNode->next = NULL;

    if(!head){
        head = newNode;
        tail = newNode;
    }
    else {
        if(newNode->value < head->value){
            newNode->next = head;
            head = newNode;
            return;
        }
        if(newNode->value > tail->value){
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
            return;
        }
        nodePtr = head;
        while (nodePtr->value < newNode->value){
                prevNode = nodePtr;
                nodePtr = nodePtr->next;
        }
        newNode->next = nodePtr;
        prevNode->next = newNode;
    }
}

#endif 