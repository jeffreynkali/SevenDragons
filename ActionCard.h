#ifndef ACTIONCARD_H
#define ACTIONCARD_H
#include "NoSplit.h"
#include "QueryResult.h"
#include "Player.h"
#include "Table.h"

class ActionCard :public NoSplit{

public:
	virtual QueryResult query() = 0;
	virtual void perform(Table&, Player*, QueryResult) = 0;
};
#endif //ACTIONCARD_H