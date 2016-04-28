/*
Mpoyo Nkali Glen Jeffrey 7977228
Mohamadou Ly 7974677
*/

#include "MyException.h"
#include <iostream>

MyException::MyException(std::string _msg) :msg(_msg){}

void MyException::print()
{
	std::cout << "Une exception de type :" << msg << ", a ete lancee" << std::endl;
}