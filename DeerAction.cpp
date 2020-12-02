#include "DeerAction.h"
#include <iostream>

DeerAction::DeerAction(){
	for (int i = 0; i < 4; i++) this->animal[i] = 'D';
}

QueryResult DeerAction::query(){
	std::cout << "Quel est le numero du joueur avec lequel vous souhaitez echanger votre carte secrete (index debutant a 0): ";
	QueryResult result;
	int i;
	std::cin >> i;
	result.setReply1(i);
	return result;
}

void DeerAction::perform(Table& _t, Player* _p, QueryResult _qr){
	std::string temp = _p->getSecretAnimal();
	_p->swapSecretAnimal(_t.getPlayers().at(_qr.getReply1())->getSecretAnimal());
	_t.getPlayers().at(_qr.getReply1())->swapSecretAnimal(temp);
}
