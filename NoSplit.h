#ifndef NOSPLIT_H
#define NOSPLIT_H
#include "AnimalCard.h"

class NoSplit : public AnimalCard{
public:
	NoSplit();
	NoSplit(char);
	void setOrientation(Orientation);
	void setRow(EvenOdd);
    void printRow(EvenOdd);
};
#endif //NOSPLIT_H