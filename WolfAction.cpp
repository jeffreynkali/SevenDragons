#include "WolfAction.h"
#include <iostream>

WolfAction::WolfAction(){
	for (int i = 0; i < 4; i++) this->animal[i] = 'W';
}

QueryResult WolfAction::query(){
	std::cout << "# de ligne de la carte  que vous souhaitez recuperer : ";
	QueryResult result;
	int i;
	std::cin >> i;
	result.setReply1(i);
	std::cout << "# de colonne de la carte que vous souhaitez recuperer : ";
	std::cin >> i;
	result.setReply2(i);
	return result;
}

void WolfAction::perform(Table& _table, Player* _p, QueryResult _query){
	std::shared_ptr<AnimalCard> temp;
	temp = _table.pickAt(_query.getReply1(), _query.getReply2());
	if (temp == nullptr)throw MyException("NullPointer");
	_p->getHand()->operator+=(temp);
}
