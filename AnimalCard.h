#ifndef ANIMALCARD_H
#define ANIMALCARD_H
#include <vector>

enum class Orientation{
	UP, DOWN
};

enum class EvenOdd{
	EVEN,ODD
};

class AnimalCard{

protected:
	std::vector<char> animal;		//vector containing the 4 char elements representing this card
									//the first 2 elements = row0 or bottom row
									//the last 2 elements = row1 or top row
	Orientation cardOrientation;
	EvenOdd cardRow;
public:
	AnimalCard();
	AnimalCard(char);
	virtual void setOrientation(Orientation);
	virtual void setRow(EvenOdd);
	virtual void printRow(EvenOdd);
	Orientation getOrientation();
	char getAnimalChar(int);

};
#endif //ANIMALCARD_H