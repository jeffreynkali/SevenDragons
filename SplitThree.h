#ifndef SPLITTHREE_H
#define SPLITTHREE_H
#include "AnimalCard.h"

class SplitThree :public AnimalCard{
	int format; //because there is actually two kinds of splitThree cards
				//this property will be used to create a card splitted horizontally 
				//or vertically  
				//0 = splitted vertically
				//1 = splitted horizontally
public:
	SplitThree(char, char, char, int = 0);
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	void printRow(EvenOdd);
};

#endif //SPLITTHREE_H