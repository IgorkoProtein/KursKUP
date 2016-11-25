#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "actor.h"

#include "perform.h"

using namespace std;

class theatre{
public:
	vector<perform> Performs;
	vector<actor> Actors;

	void addPerform(string);
	void getFFPerf(string);
	void detetePerform(string);

	void addActors(string);
	void getActors(string);
	void deleteActor(string);


};