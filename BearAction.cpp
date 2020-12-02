#include "BearAction.h"
#include <iostream>

BearAction::BearAction(){
	for (int i = 0; i < 4; i++) this->animal[i] = 'B';
}

QueryResult BearAction::query(){
	std::cout << "Quel est le numero du joueur avec lequel vous souhaitez echanger votre main (index debutant a 0) : ";
	QueryResult result;
	int i;
	std::cin >> i;
	result.setReply1(i);
	return result;
}

void BearAction::perform(Table& _t, Player* _p, QueryResult _qr){
	Hand* temp = _p->getHand();
	_p->setHand(_t.getPlayers().at(_qr.getReply1())->getHand());
	_t.getPlayers().at(_qr.getReply1())->setHand(temp);
}

