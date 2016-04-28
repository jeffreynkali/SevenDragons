/*
Mpoyo Nkali Glen Jeffrey 7977228
Mohamadou Ly 7974677
*/

#include "HareAction.h"
#include <iostream>

HareAction::HareAction(){
	for (int i = 0; i < 4; i++) this->animal[i] = 'H';
}

QueryResult HareAction::query(){
	QueryResult result;
	std::cout << "# de ligne de la carte que vous souhaitez deplacer (0-102) : ";
	int i;
	std::cin >> i;
	result.setReply1(i);
	std::cout << "# de colonne de la carte que vous souhaitez deplacer (0-102): ";
	std::cin >> i;
	result.setReply2(i);
	std::cout << "# de ligne de l'emplacement ou vous souhaitez deposer la carte (0-102): ";
	std::cin >> i;
	result.setReply3(i);
	std::cout << "# de colonne de l'emplacement ou vous souhaitez deposer la carte (0-102): ";
	std::cin >> i;
	result.setReply4(i);
	return result;
}

void HareAction::perform(Table& _t, Player* _p, QueryResult _qr){
	std::shared_ptr<AnimalCard> temp;
	temp = _t.pickAt(_qr.getReply1(), _qr.getReply2());
	if (temp == nullptr)throw MyException("NullPointer");
	_t.addAt(temp, _qr.getReply3(), _qr.getReply4());
}