#ifndef ANIMALCARDFACTORY_H
#define ANIMALCARDFACTORY_H
#include <iterator>
#include <random>
#include <algorithm>
#include "Deck.h"
#include "AnimalCard.h"
#include "Joker.h"
#include "BearAction.h"
#include "DeerAction.h"
#include "HareAction.h"
#include "MooseAction.h"
#include "WolfAction.h"
#include "SplitTwo.h"
#include "SplitThree.h"
#include "SplitFour.h"


class AnimalCardFactory{
	AnimalCardFactory();
	static AnimalCardFactory* factory; 
	Deck<std::shared_ptr<AnimalCard>> deck;
public :
	static AnimalCardFactory* getFactory();
	Deck<std::shared_ptr<AnimalCard>> getDeck();
	~AnimalCardFactory();
};
#endif //ANIMALCARDFACTORY_H