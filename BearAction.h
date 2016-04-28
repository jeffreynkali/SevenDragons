#ifndef BEARACTION_H
#define BEARACTION_H
#include "ActionCard.h"
#include "Hand.h"

class BearAction : public ActionCard{
public :
	BearAction();
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};
#endif //BEARACTION_H