/*
Mpoyo Nkali Glen Jeffrey 7977228
Mohamadou Ly 7974677
*/

#include "MooseAction.h"
#include <iostream>

MooseAction::MooseAction(){
	for (int i = 0; i < 4; i++) this->animal[i] = 'M';
}

QueryResult MooseAction::query(){
	std::cout << "Les cartes secretes vont etre changees entre les joueurs ! ";
	QueryResult result;
	return result;
}

void MooseAction::perform(Table& _t, Player* _p, QueryResult _qr){
	int nbPlayers = _t.getPlayers().size();
	std::string temp = _t.getPlayers().at(nbPlayers - 1)->getSecretAnimal();
	for (int i = nbPlayers-1; i >= 0; i--){
		_t.getPlayers().at(i)->swapSecretAnimal(_t.getPlayers().at((i - 1 + nbPlayers)%nbPlayers)->getSecretAnimal());
	}
	_t.getPlayers().at(0)->swapSecretAnimal(temp);
}
