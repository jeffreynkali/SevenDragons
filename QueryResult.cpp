#include "QueryResult.h"

QueryResult::QueryResult() : reply1(0), reply2(0), reply3(0), reply4(0){}

void QueryResult::setReply1(int _reply){ reply1 = _reply; }

void QueryResult::setReply2(int _reply){ reply2 = _reply; }

void QueryResult::setReply3(int _reply){ reply3 = _reply; }

void QueryResult::setReply4(int _reply){ reply4 = _reply; }

int QueryResult::getReply1(){ return reply1; }

int QueryResult::getReply2(){ return reply2; }

int QueryResult::getReply3(){ return reply3; }

int QueryResult::getReply4(){ return reply4; }
