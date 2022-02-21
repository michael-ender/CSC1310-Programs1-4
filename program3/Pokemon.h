/**********************************************************************
	Title:        Pokemon.h
	Author:       Michael Steets
	Date Created: 3/30/21
	Purpose:      To hold all the pokemon and their IDs
***********************************************************************/
#include <iostream>
using namespace std;

#ifndef POKEMON_H
#define POKEMON_H

class Pokemon {
    private:
        int index;
        string name;
    public:
        Pokemon(int id = 0, string n = "None"){
            this->index = id;
            this->name = n;
        }

        void setID(int id) {
            this->index = id;
        }

        void setName(string poke) {
            this->name = poke;
        }

        int getID() {
            return index;
        }

        string getName() {
            return name;
        }
        
        bool operator <(const Pokemon& p)
		{
			if(this->index < p.index)
				return true;
			return false;
		}

        bool operator ==(const Pokemon& p)
		{
			if(this->index == p.index)
				return true;
			return false;
		}

        friend ostream & operator <<(ostream& os, const Pokemon& p)
		{
			os << "Pokemon Index Number: " << p.index << "  Name: " << p.name;
			
			return os;
		}
};

#endif