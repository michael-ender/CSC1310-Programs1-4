/**********************************************************************
	Title:          BinaryTree.h
	Author:         Michael Steets
	Date Created:   3/30/21
	Purpose:        Binary tree class template that can hold values
                    of any type.
***********************************************************************/
#include <iostream>
using namespace std;

#ifndef BINARY_H
#define BINARY_H

template <class T>
class BinaryTree {
    private:
        struct TreeNode {
            T value;
            TreeNode *left;
            TreeNode *right;
        };

        TreeNode *root;

        void Insert(TreeNode *&, TreeNode *&);
        void destroySubTree(TreeNode *);
        void displayInOrder(TreeNode *) const;        
    public:
        BinaryTree() {
            root = NULL;
        }

        ~BinaryTree() {
            destroySubTree(root);
        }
        
        void insertNode(T); 
        void displayInOrder() {
            displayInOrder(root);
        }
        bool searchNode(T);
};

template <class T>
void BinaryTree<T>::Insert(TreeNode *&nodePtr, TreeNode *&newNode) {    //inserts the node passed through insertNode into the tree
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        Insert(nodePtr->left, newNode);
    else
        Insert(nodePtr->right, newNode);
}

template <typename T>
void BinaryTree<T>::insertNode(T lilGuy) {                                //creates a node to be passed to the insert function
    TreeNode *newNode = nullptr;

    newNode = new TreeNode;
    newNode->value = lilGuy;
    newNode->left = newNode->right = nullptr;

    Insert(root, newNode);
}

template <typename T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr) {                 //called by destructor and destroys all the nodes
    if (nodePtr) {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

template <class T>
bool BinaryTree<T>::searchNode(T item) {                                //searches for a node and returns true if found and false if not found
    TreeNode *nodePtr = root;

    while (nodePtr) {
        if (nodePtr->value == item)
            return true;
        else if (item < nodePtr->value)
            nodePtr = nodePtr->left;
        else    
            nodePtr = nodePtr->right;
    }
    return false;
}

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const {           //displays the nodes InOrder formation
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

#endif