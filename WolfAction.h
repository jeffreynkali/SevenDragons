#ifndef WOLFACTION_H
#define WOLFACTION_H
#include "ActionCard.h"

class WolfAction : public ActionCard{
public:
	WolfAction();
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};
#endif //WOLFACTION_H