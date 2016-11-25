#pragma once
#include <iostream>
#include <string>
#include "perform.h"
using namespace std;

class rozklad
{
	vector<perform> Performs;
	string startHr;
	string endHr;
	string name;

public:
	void setStHr();
	void setEnHr();
	void setName();
	
	void setPerform(perform);

};
