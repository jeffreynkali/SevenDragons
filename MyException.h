#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <string>

class MyException{
	std::string msg;
public:
	MyException(std::string);
	void print();
};
#endif //MYEXCEPTION_H