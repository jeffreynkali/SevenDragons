#ifndef QUERYRESULT_H
#define QUERYRESULT_H

class QueryResult{
	int reply1, reply2, reply3, reply4;
public:
	QueryResult();
	void setReply1(int);
	void setReply2(int);
	void setReply3(int);
	void setReply4(int);
	int getReply1();
	int getReply2();
	int getReply3();
	int getReply4();
};
#endif //QUERYRESULT_H