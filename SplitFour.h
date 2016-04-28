#ifndef SPLITFOUR_H
#define SPLITFOUR_H
#include "AnimalCard.h"

class SplitFour :public AnimalCard{
	//unlike the splitThree and splitTwo classes this class does not need
	//a format attribute because it does not have all the possible configuration
	//that those 2 other classes had
public: 
	SplitFour(char, char, char, char);
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	void printRow(EvenOdd);
};
#endif //SPLITFOUR_H