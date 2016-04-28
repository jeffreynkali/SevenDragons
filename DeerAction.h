#ifndef DEERACTION_H
#define DEERACTION_H
#include "ActionCard.h"

class DeerAction : public ActionCard{
public :
	DeerAction();
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};
#endif //DEERACTION_H