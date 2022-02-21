/**********************************************************************
	Title:          Program3.cpp
	Author:         Michael Steets
	Date Created:   3/30/21
	Purpose:        Executes all the functions to be printed when the
                    program is are called in the command prompt
***********************************************************************/
#include "BinaryTree.h"
#include "Pokemon.h"
#include <fstream>
#include <iostream>
using namespace std;

void readFromFile(BinaryTree<Pokemon>&);

int main () {

	BinaryTree<Pokemon> tree;

	readFromFile(tree);
	
	cout << "******************** POKEDEX ********************\n";
	tree.displayInOrder();

	return 0;
}

void readFromFile(BinaryTree<Pokemon>& tree)
{
	ifstream inFile;
	string path = "pokedex.txt";
	string temp, pokemon;
	int pokeID;
	int count = 0;

	inFile.open(path.c_str());
	if (!inFile) {
		cout << "Unable to open file\n";
	}
	else {
		while(getline(inFile, temp, '#')) {
			pokeID = stoi(temp);
			getline(inFile, temp, '#');
			pokemon = temp;
			Pokemon PokemonList(pokeID, pokemon);
			if (tree.searchNode(PokemonList) == true){
				cout << "This Pokemon is already in the list!\n";
			}
			else {
				cout << "Inserting Pokemon with an index " << pokeID << " into the Pokedex.\n";
				count++;
				tree.insertNode(PokemonList);
			}
		}
	inFile.close();		
	}
	
	cout << endl;
	cout << count << " Pokemon have been added to the list!\n\n";
}