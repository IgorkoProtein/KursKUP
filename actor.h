#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class actor{
	string name;
	string surName;
	string pseudonym;

public:
	actor();
	actor(string, string, string);

	void SetName();
	void SetName(string);
	void SetSurName();
	void SetSurName(string);
	void SetPseudonym();
	void SetPseudonym(string);

	string getName();
	string getSurName();
	string getPseudonym();

	void Show();
};