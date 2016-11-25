#include "theatre.h"

void theatre::getFFPerf(string path) {
	ifstream pr(path);
	perform tempPr;
	char* Buffer = new char[2000];
	char* ptr;// = new char[];
	int i = 0;

	Performs.clear();

	if (!pr.is_open()) {
		cout << "Файл " << path << " не знайдено!!" << endl;
	}
	else {
		while (!pr.eof())
		{
			pr.getline(Buffer, 2000, '\n');
			ptr = strtok(Buffer, ",");
			int i = 0;

			while (ptr)
			{
				switch (i)
				{
				case 0: tempPr.setName(ptr); break;
				case 1: tempPr.setDuration(ptr); break;
				case 2: tempPr.setTime(ptr); break;
				case 3: tempPr.setDay(ptr); break;
				case 4: tempPr.setActorName(ptr, 0); break;
				case 5: tempPr.setActorSurname(ptr, 0); break;
				case 6: tempPr.setActorPseudonym(ptr, 0); break;
				case 7: tempPr.setActorName(ptr, 1); break;
				case 8: tempPr.setActorSurname(ptr, 1); break;
				case 9: tempPr.setActorPseudonym(ptr, 1); break;
				case 10: tempPr.setActorName(ptr, 2); break;
				case 11: tempPr.setActorSurname(ptr, 2); break;
				case 12: tempPr.setActorPseudonym(ptr, 2); break;
				}
				ptr = strtok(NULL, ",");
				i++;
			}
			Performs.push_back(tempPr);
		}
	}
	pr.close();
	delete Buffer;
}
void theatre::addPerform(string path) {
	perform temp;
	system("cls");
	cout << "New performs:" << endl;
	temp.setName();
	temp.setDuration();
	temp.setTime();
	temp.setDay();
	temp.AddActor(Actors);
	Performs.push_back(temp);
	system("cls");

	ofstream Prf(path, ios_base::app);
	Prf << "\n" << temp.getName() << ",";
	Prf << temp.getDuration() << ",";
	Prf << temp.getStartTime() << ",";
	Prf << temp.getDay() << ",";
	for (int i = 0; i < temp.currrentActors.size(); i++)
	{
		Prf << temp.currrentActors[i].getName() << ",";
		Prf << temp.currrentActors[i].getSurName() << ",";
		if (i == 2) {
			Prf << temp.currrentActors[i].getPseudonym();
		}
		else {
			Prf << temp.currrentActors[i].getPseudonym() << ",";
		}
	}
	Prf.close();
}

void theatre::getActors(string road) {
	ifstream pr(road);
	actor tempPr;
	char* Buffer = new char[500];
	char* ptr;// = new char[];
	int i = 0;

	Actors.clear();

	if (!pr.is_open()) {
		cout << "Файл " << road << " не знайдено!!" << endl;
	}
	else {
		while (!pr.eof())
		{
			pr.getline(Buffer, 2000, '\n');
			ptr = strtok(Buffer, " ,");
			int i = 0;

			while (ptr)
			{
				switch (i)
				{
				case 0: tempPr.SetName(ptr); break;
				case 1: tempPr.SetSurName(ptr); break;
				case 2: tempPr.SetPseudonym(ptr); break;
				}
				ptr = strtok(NULL, " ,");
				i++;
			}
			Actors.push_back(tempPr);
		}
	}
	pr.close();
	delete Buffer;
}
void theatre::addActors(string road) {
	actor temp;
	system("cls");
	cout << "New actor" << endl;
	temp.SetName();
	temp.SetSurName();
	temp.SetPseudonym();
	Actors.push_back(temp);
	system("cls");

	ofstream obj(road, ios_base::app);
	obj << endl << temp.getName() << ",";
	obj << temp.getSurName() << ",";
	obj << temp.getPseudonym();
	obj.close();
}

void theatre::deleteActor(string road) {
	system("cls");
	int number;

	if (Actors.size() != 0) {
		for (int i = 0; i < Actors.size(); i++)
		{
			cout << "Actor[" << i + 1 << "] ";
			Actors[i].Show();
			cout << endl;
		}
		do {
			cout << "Choise actor:";
			cin >> number;
		} while (number > Actors.size() || number < 0 || !cin);

		Actors.erase(Actors.begin() + (number - 1));

		ofstream actWrite(road, ios_base::trunc);

		for (int i = 0; i < Actors.size(); i++)
		{
			actWrite << Actors[i].getName() << ",";
			actWrite << Actors[i].getSurName() << ",";
			if (i == (Actors.size() - 1)) {
				actWrite << Actors[i].getPseudonym();
			}
			else {
				actWrite << Actors[i].getPseudonym() << "\n";
			}
		}
		actWrite.close();
	}
	else {
		cout << "Load data from file actors!!!" << endl;
		system("pause");
	}
	system("cls");
}


void theatre::detetePerform(string road) {
	system("cls");
	int number;

	if (Performs.size() != 0) {
		for (int i = 0; i < Performs.size(); i++)
		{
			cout << "Perform[" << i + 1 << "] ";
			Performs[i].showName();
			cout << endl;
		}
		do {
			cout << "Choise perform by index :";
			cin >> number;
		} while (number > Performs.size() || number < 0);

		Performs.erase(Performs.begin() + (number - 1));

		ofstream actWrite(road, ios_base::trunc);

		for (int i = 0; i < Performs.size(); i++)
		{
			actWrite << Performs[i].getName() << ",";
			actWrite << Performs[i].getDuration() << ",";
			actWrite << Performs[i].getStartTime() << ",";
			actWrite << Performs[i].getDay() << ",";
			actWrite << Performs[i].getEndTime() << ",";
			actWrite << Performs[i].currrentActors[i].getName() << ",";
			actWrite << Performs[i].currrentActors[i].getSurName() << ",";

			if (i == (Performs.size() - 1)) {
				actWrite << Performs[i].currrentActors[i].getSurName();
			}
			else {
				actWrite << Performs[i].currrentActors[i].getSurName() << "\n";
			}
		}
		actWrite.close();
	}
	else {
		cout << "Load data from file actors!!!" << endl;
		system("pause");
	}
	system("cls");
}
