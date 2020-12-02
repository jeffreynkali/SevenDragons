#include "NoSplit.h"
#include <iostream>


NoSplit::NoSplit(){
	//By default we initialize it at n standing for nosplit
	for (int i = 0; i < 4; i++) this->animal[i] = 'n';
}

NoSplit::NoSplit(char _c){
	for (int i = 0; i < 4; i++) this->animal[i] = _c;
}

void NoSplit::setOrientation(Orientation _o)
{
	this->cardOrientation = _o;

}

void NoSplit::setRow(EvenOdd _eo)
{
	this->cardRow = _eo;
}

void NoSplit::printRow(EvenOdd _eo){
	if (_eo == EvenOdd::ODD)
	{
		if (this->cardOrientation == Orientation::UP)std::cout << this->animal[2] << this->animal[3];
		else std::cout << this->animal[1] << this->animal[0];
	}
	else
	{
		if (this->cardOrientation == Orientation::UP)std::cout << this->animal[0] << this->animal[1];
		else std::cout << this->animal[3] << this->animal[2];
	}
}
