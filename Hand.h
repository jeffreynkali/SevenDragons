#ifndef HAND_H
#define HAND_H
#include <list>
#include <algorithm>
#include <memory>
#include "AnimalCard.h"
#include "MyException.h"



class Hand {

	std::list<std::shared_ptr<AnimalCard>> hand;
public :
	Hand& operator+=(std::shared_ptr<AnimalCard>);
	Hand& operator-=(std::shared_ptr<AnimalCard>);
	std::shared_ptr<AnimalCard> operator[](int);
	int noCards();
	void print();
};
#endif HAND_H