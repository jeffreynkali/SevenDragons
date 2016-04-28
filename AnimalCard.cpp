/*
Mpoyo Nkali Glen Jeffrey 7977228
Mohamadou Ly 7974677
*/

#include <iostream>
#include "AnimalCard.h"

//Default constructor that creates a Moose Card oriented upwards and points on its top row
AnimalCard::AnimalCard():animal(4,'m'), cardOrientation(Orientation::UP), cardRow(EvenOdd::ODD){}

//One Argument constructor
AnimalCard::AnimalCard(char _animal): animal(4,_animal), cardOrientation(Orientation::UP), cardRow(EvenOdd::ODD){}

void AnimalCard::setOrientation(Orientation _o)
{
	this->cardOrientation = _o;
}

void AnimalCard::setRow(EvenOdd _eo)
{
	this->cardRow = _eo;
}

//Because this is the method that will be called on a one animal card
//we already know that the animal will have the same letter for all the 4 sections  
void AnimalCard::printRow(EvenOdd _eo)
{
	//we do not really have to take into consideration the odd or even row property here
	//as this is a one animal card all the 4 values of animal will be the same

	//Also even though the best way to go through a vector is by using an iterator
	//for simplicity reasons and also ease of use we will just use the index to access the elements
	//we can do this because we know that our vector is suppose to always have a size of 4
	if (_eo == EvenOdd::ODD)
	{
		if (this->cardOrientation == Orientation::UP)std::cout << this->animal[2] << this->animal[3];
		else std::cout << this->animal[1] << this->animal[0] ;
	}
	else
	{
		if (this->cardOrientation == Orientation::UP)std::cout << this->animal[0] << this->animal[1] ;
		else std::cout << this->animal[3] << this->animal[2] ;
	}
}

Orientation AnimalCard::getOrientation(){ return this->cardOrientation; }

char AnimalCard::getAnimalChar(int _index){ return animal[_index]; }
