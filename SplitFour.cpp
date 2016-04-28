/*
Mpoyo Nkali Glen Jeffrey 7977228
Mohamadou Ly 7974677
*/

#include <iostream>
#include "SplitFour.h"

SplitFour::SplitFour(char _animal1, char _animal2, char _animal3, char _animal4)
{

	this->animal[2] = _animal1;
	this->animal[3] = _animal2;
	this->animal[0] = _animal3;
	this->animal[1] = _animal4;
}

void SplitFour::setOrientation(Orientation _o)
{
	this->cardOrientation = _o;
}

void SplitFour::setRow(EvenOdd _eo)
{
	this->cardRow = _eo;
}

void SplitFour::printRow(EvenOdd _eo)
{
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