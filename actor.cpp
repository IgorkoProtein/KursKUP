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
	cout << "��'� ������: ";
	cin >> name;
}

void actor::SetName(string a){
	name = a;
}

void actor::SetSurName(){
	cout << "������� ������:";
	cin >> surName;
}

void actor::SetSurName(string b){
	surName = b;
}

void actor::SetPseudonym(){
	cout << "�������� ������:";
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
	cout << "�����: " << surName << " " << name << endl;
	cout << "��������: " << pseudonym << endl << endl;
}