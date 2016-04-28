#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Hand.h"

class Player{
	std::string name;
	std::string secretAnimal;
	Hand* hand;
public:
	Player(std::string, std::string);
	std::string swapSecretAnimal(std::string&);
	std::string getSecretAnimal();
	std::string getName();
	Hand* getHand();
	void setHand(Hand*);
	void print();
	~Player();
};
#endif PLAYER_H