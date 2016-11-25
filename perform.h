#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "actor.h"

using namespace std;

enum day { monday = 1, thuesday, wednesday, thursday, friday, saturday, sunday };

class perform {
	string name;
	int duration;
	int startTimeH;
	int startTimeM;
	int endTimeH;
	int endTimeM;
	day dayP;
public:
	vector<actor> currrentActors;
	perform();
	perform(string, int, int, int, int,int, day);

	void setName();
	void setName(string);
	void setDuration();
	void setDuration(string);
	void setTime();
	void setTime(string);
	void setDay();
	void setDay(string);

	void AddActor(vector<actor>&);
	void setActorName(string, int);
	void setActorSurname(string, int);
	void setActorPseudonym(string, int);
	void showName();
	void show();

	string getName();
	int getDuration();
	string getStartTime();
	string getEndTime();
	day getDay();
	

};

