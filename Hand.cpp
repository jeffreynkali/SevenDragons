/*
Mpoyo Nkali Glen Jeffrey 7977228
Mohamadou Ly 7974677
*/


#include "Hand.h"
#include <iostream>


Hand& Hand::operator+=(std::shared_ptr<AnimalCard> _card)
{
	this->hand.push_back(_card);
	return *this;
}

Hand& Hand::operator-=(std::shared_ptr<AnimalCard> _card)
{
	std::list<std::shared_ptr<AnimalCard>>::iterator iter = std::find(this->hand.begin(), this->hand.end(), _card);
	if (iter == this->hand.end()) throw MyException("MissingCard");
	this->hand.remove(_card);
	return *this;
	
}

std::shared_ptr<AnimalCard> Hand::operator[](int _index)
{
	std::list<std::shared_ptr<AnimalCard>>::iterator iter;
	//after initialization iter is already on the first element of the list
	iter = this->hand.begin();
	for (int i = 0; i < _index && iter != this->hand.end(); i++, iter++){	
	}
	if (iter == this->hand.end()) throw MyException("IndexOutOfBounds");
	return *iter;
}

int Hand::noCards()
{
	return this->hand.size();
}

void Hand::print()
{
	for (int i = 0; i < this->noCards(); i++) std::cout << i << "  ";
	std::cout << std::endl;
	std::list<std::shared_ptr<AnimalCard>>::iterator iter = this->hand.begin();
	iter = this->hand.begin();
	while (iter != this->hand.end()){
		(*iter)->printRow(EvenOdd::ODD);
		std::cout << " ";
		iter++;
	}
	std::cout << std::endl;
	iter = this->hand.begin();
	while (iter != this->hand.end()){
		(*iter)->printRow(EvenOdd::EVEN);
		std::cout << " ";
		iter++;
	}

	std::cout << std::endl;
}