#include "grille.h"
#include <iostream>

using namespace std;





void grille::PrintCells() {
	Cellule* current = jeu;
	for (int i = 0; i < 16; i++) {
		if (i % 4 == 0 && i !=0) {
			cout << " | ";
			cout << endl;
			cout << endl;
		}
		cout << " | " << current->getVal();
		current = current->getNext();
	}cout << " | " << endl;
}

Cellule grille::makeByIndex(int index) {
	Cellule* curseur = jeu;
	while (index != 1)
	{
		//std::cout << "index : " << index << " val : " << curseur->getVal() << endl;
		curseur = curseur->getNext(); // Recupération de la bonne cellule 
		
		index--;
	}
	return *curseur;
}

void grille::setUsedByIndex(int index, bool b) {// change le used ds la grille
	Cellule* curseur = jeu;
	while (index != 1)
	{
		curseur = curseur->getNext(); 

		index--;
	}
	curseur->setUsed(b);
}

char grille::getValByIndex(int index) {// va chercher le char voulu dans la grille
	Cellule* curseur = jeu; 
	while (index != 1) 
	{
		curseur = curseur->getNext(); 

		index--; 
	}
	curseur->setUsed(true);
	return curseur->getVal();
}

bool grille::validIndex(int index) {
	return (index >= 1 && index <= 16);
}



void grille::printList(Cellule* list) {
	Cellule* current = list;
	while (current != nullptr) {
		cout << " " << current->getVal();
		current = current->getNext();
	}
}

std::vector<char> grille::getAdjacent2(int index) {
	std::vector<char>* res = new std::vector<char>();
	std::cout << "index : " << index << "premier element : " << res->front();

	const int numRows = 4;
	const int numCols = 4;

	int row = (index - 1) / numCols;
	int col = (index - 1) % numCols;

	for (int r = -1; r <= 1; r++) {
		for (int c = -1; c <= 1; c++) {
			std::cout << "Dans la boucle " << endl;
			int newRow = row + r;
			int newCol = col + c;

			if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols) {
				int newIndex = newRow * numCols + newCol;

				// Find the corresponding Cellule in the list
				char tmp = getValByIndex(newIndex + 1);
				res->push_back(tmp);
			}
		}
	}
	return *res;

}

void grille::printVector(const std::vector<char>& charVector) {
	std::cout << "dans le print vector" << endl;
	for (const char& ch : charVector) {
		std::cout << ch << " ";
	}
	std::cout << std::endl;
}



Cellule* grille::getAdjacent(int index) {
	Cellule cell = makeByIndex(index);
	std::cout << endl << "la premiere cellule est : " << cell.getVal() << endl;
	Cellule* res = new Cellule(cell.getVal()); // Create a new list of adjacent cells
	res->setUsed(true);
	Cellule* current = res;
	int tmpIndex;

	// For the three cells above 'cell'
	for (int i = -5; i < -3; i++) {
		tmpIndex = index + i;
		std::cout << "test dessus index est : " << tmpIndex << endl;
		if (validIndex(tmpIndex)) {
			std::cout << "Index est valid : index tester est : " << tmpIndex << endl;
			Cellule tmpCell = makeByIndex(tmpIndex); // Creation cellule qu'on ajoutera a la liste 
			if (!tmpCell.getUsed()) {
				Cellule* next = new Cellule(tmpCell.getVal());
				current->setNext(next);
				current = next;
			}
		}
	}

	// For the two cells next to 'cell'
	tmpIndex = index - 1;
	if (validIndex(tmpIndex)) {
		const Cellule& tmpCell = makeByIndex(tmpIndex);
		if (!tmpCell.getUsed()) {
			Cellule* next = new Cellule(tmpCell.getVal());
			current->setNext(next);
			current = next;
		}
	}

	tmpIndex = index + 1;
	if (validIndex(tmpIndex)) {
		const Cellule& tmpCell = makeByIndex(tmpIndex);
		if (!tmpCell.getUsed()) {
			Cellule* next = new Cellule(tmpCell.getVal());
			current->setNext(next);
			current = next;
		}
	}

	// For the three cells below 'cell'
	for (int i = 3; i < 5; i++) {
		tmpIndex = index + i;
		if (validIndex(tmpIndex)) {
			const Cellule& tmpCell = makeByIndex(tmpIndex);
			if (!tmpCell.getUsed()) {
				Cellule* next = new Cellule(tmpCell.getVal());
				current->setNext(next);
				current = next;
			}
		}
	}

	return res;
}


