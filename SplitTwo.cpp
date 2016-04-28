/*
Mpoyo Nkali Glen Jeffrey 7977228
Mohamadou Ly 7974677
*/

#include <iostream>
#include "SplitTwo.h"


SplitTwo::SplitTwo(char _animal1, char _animal2, int _format) :format(_format)
{

	if (this->format){ //format == 1 splitted horizontally
		this->animal[2] = _animal1;
		this->animal[3] = _animal1;
		this->animal[0] = _animal2;
		this->animal[1] = _animal2;
	}
	else{
		this->animal[2] = _animal1;
		this->animal[0] = _animal1;
		this->animal[3] = _animal2;
		this->animal[1] = _animal2;
	}
	
}

void SplitTwo::setOrientation(Orientation _o)
{
	this->cardOrientation = _o;

}

void SplitTwo::setRow(EvenOdd _eo)
{
	this->cardRow = _eo;
}

void SplitTwo::printRow(EvenOdd _eo){
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