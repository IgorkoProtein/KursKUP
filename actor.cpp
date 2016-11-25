#include "actor.h"

actor::actor(){
	name = "";
	surName = "";
	pseudonym = "";
}

actor::actor(string a, string b, string c){
	name = a;
	surName = b;
	pseudonym = c;
}

void actor::SetName(){
	cout << "Ім'я актора: ";
	cin >> name;
}

void actor::SetName(string a){
	name = a;
}

void actor::SetSurName(){
	cout << "Прізвище актора:";
	cin >> surName;
}

void actor::SetSurName(string b){
	surName = b;
}

void actor::SetPseudonym(){
	cout << "Псевдонім актора:";
	cin >> pseudonym;
}

void actor::SetPseudonym(string c){
	pseudonym = c;
}

string actor::getName(){
	return name;
}

string actor::getSurName(){
	return surName;
}

string actor::getPseudonym(){
	return pseudonym;
}

void actor::Show(){
	cout << "Актор: " << surName << " " << name << endl;
	cout << "Псевдонім: " << pseudonym << endl << endl;
}