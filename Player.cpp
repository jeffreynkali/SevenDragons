#include "Player.h"
#include <iostream>

Player::Player(std::string _name, std::string _secretAnimal):name(_name), secretAnimal(_secretAnimal)
{
	hand = new Hand();
}

std::string Player::swapSecretAnimal(std::string& _secretAnimal)
{
	std::string temp = this->secretAnimal;
	this->secretAnimal = _secretAnimal;
	return temp;
}

std::string Player::getSecretAnimal(){ return this->secretAnimal; }

std::string Player::getName(){ return this->name; }

Hand* Player::getHand(){ return this->hand; }

void Player::setHand(Hand* _hand){ this->hand = _hand; }

void Player::print()
{
	std::cout << "Player : " << name << ", secretAnimal : " << secretAnimal << std::endl;
	hand->print();
}

Player::~Player(){
	delete hand;
}
