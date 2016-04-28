#ifndef SPLITTWO_H
#define SPLITTWO_H
#include "AnimalCard.h"


class SplitTwo :public AnimalCard{
				//because there is actually two kinds of splitTwo cards
	int format;	//this property will be used to create a card splitted horizontally 
				//or vertically  
				//0 = splitted vertically
				//1 = splitted horizontally
public:
	SplitTwo(char, char, int = 0);
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	void printRow(EvenOdd);
};
#endif //SPLITTWO_H