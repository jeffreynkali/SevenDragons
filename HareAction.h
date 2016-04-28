#ifndef HAREACTION_H
#define HAREACTION_H
#include "ActionCard.h"

class HareAction : public ActionCard{
public:
	HareAction();
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};
#endif //HAREACTION_H