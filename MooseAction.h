#ifndef MOOSEACTION_H
#define MOOSEACTION_H
#include "ActionCard.h"

class MooseAction : public ActionCard{
public:
	MooseAction();
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};
#endif //MOOSEACTION_H