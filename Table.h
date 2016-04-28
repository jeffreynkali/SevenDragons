#ifndef TABLE_H
#define TABLE_H
#include <memory>
#include <algorithm>
#include <string>
#include <iostream>
#include "AnimalCard.h"
#include "SplitFour.h"
#include "Player.h"

class Table{
	std::vector<std::vector<std::shared_ptr<AnimalCard>>> table;
	//We added a vector of players to be able to access all the players
	//in order to perform the actions
	std::vector<std::shared_ptr<Player>> players;
	//I made this method public so as to be able to call it from the main
	//to check whether or not a position was valid
	int countMatches(std::shared_ptr<AnimalCard>, int, int);
public:
	Table();
	int addAt(std::shared_ptr<AnimalCard>, int, int);
	std::shared_ptr<AnimalCard> pickAt(int, int);
	std::shared_ptr<AnimalCard> get(int, int);
	void set(std::shared_ptr<AnimalCard>, int, int);
	bool win(std::string& animal);
	void addPlayer(std::shared_ptr<Player>);
	std::vector<std::shared_ptr<Player>> getPlayers();
	void print();
	int firstPrintableLine();
	int lastPrintableLine();
	int firstPrintableColumn();
	int lastPrintableColumn();
	void write(std::ostream&);
	void read(std::istream& is);
	
};
#endif //TABLE_H