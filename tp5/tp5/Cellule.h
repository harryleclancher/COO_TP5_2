#pragma once
#include <cstdlib>

using namespace std;

class Cellule
{
private:
	char val;
	bool used;
	Cellule* next;
	
public:

	Cellule() {
		int randNum = int('a') + rand() % 26;
		val = (char)randNum;
		used = false;
		next = nullptr;
	}


	//Constructeur permettant de faire des test 
	Cellule(char my_val) {
		val = my_val; 
		used = false;
		next = nullptr;
	}


	Cellule(const Cellule& other) {
		val = other.val;
		used = other.used;
		// Create a deep copy of the 'next' cell to avoid sharing pointers.
		if (other.next) {
			next = new Cellule(*(other.next));
		}
		else {
			next = nullptr;
		}
	}






	char getVal() const {
		return val;
	}

	bool getUsed() const {
		return used;
	}

	Cellule* getNext() {
		return next;
	}


	void setUsed(bool b) {
		used = b;
	}

	void setNext(Cellule* my_cell) {
		next = my_cell;
	}



};

