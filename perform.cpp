#include "perform.h"

perform::perform() {
	name = "";
	duration = 0;
	startTimeH = 0;
	startTimeM = 0;
	endTimeH = 0;
	endTimeM = 0;
	dayP = monday;
}

perform::perform(string nm, int dur, int stH, int stM, int endH, int endM, day d) {
	name = nm;
	duration = dur;
	startTimeH = stH;
	startTimeM = stM;
	endTimeH = endH;
	endTimeM = endM;
	dayP = d;
}
void perform::setName(string nm) {
	name = nm;
}
void perform::setName() {
	cout << "Введіть назву вистави :";
	cin >> name;
}
void perform::setDuration(string dr) {
	duration = stoi(dr);
}
void perform::setDuration() {
	int n;
	while (true)
	{
		cout << "Введіть тривалість вистави у хвилинах:";
		cin >> n;
		if (!cin) {
			cout << "Недопустимі символи для задання тривалості " << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	duration = n;
}
void perform::setTime(string t) {
	string buffer;

	buffer = t.substr(0, 2);
	startTimeH = stoi(buffer);
	buffer = t.substr(2, 2);
	startTimeM = stoi(buffer);

	if (duration > 59) {
		endTimeH = startTimeH + duration / 60;
		endTimeM = startTimeM + duration % 60;
		if (endTimeM > 59) {
			endTimeH++;
			endTimeM = endTimeM - 60;
		}
	}
	else {
		if ((startTimeM + duration) > 59) {
			endTimeM = startTimeM + duration - 60;
			endTimeH = startTimeH + 1;
		}
		else {
			endTimeM = startTimeM + duration;
			endTimeH = startTimeH;
		}
	}
}
void perform::setTime() {
	int h, m;
	while (true) {
		cout << "Введіть час початку вистави(гг:хх):";
		cout << "год: ";
		cin >> h;
		cout << "хв:";
		cin >> m;
		if (!cin) {
			cout << "Недопустимі символи для задання часу " << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else {
			if (h < 0 || h>24) {
				cout << "Недопустимий формат введення години!!!" << endl;
				cout << "Допустимий діапазон [0-24]" << endl;
			}
			else if (m < 0 || m>59) {
				cout << "Недопустимий формат введення хвилин!!!" << endl;
				cout << "Допустимий діапазон [0-59]" << endl;
			}
			else {
				break;
			}
		}
	}
	startTimeH = h;
	startTimeM = m;
	if (duration > 59) {
		endTimeH = startTimeH + duration / 60;
		endTimeM = startTimeM + duration % 60;
		if (endTimeM > 59) {
			endTimeH++;
			endTimeM = endTimeM - 60;
		}
	}
	else {
		if ((startTimeM + duration) > 59) {
			endTimeM = startTimeM + duration - 60;
			endTimeH = startTimeH + 1;
		}
		else {
			endTimeM = startTimeM + duration;
			endTimeH = startTimeH;
		}
	}

}
void perform::setDay(string day) {
	switch (stoi(day))
	{
	case 1: dayP = monday;
	case 2: dayP = thuesday;
	case 3: dayP = wednesday;
	case 4: dayP = thursday;
	case 5: dayP = friday;
	case 6: dayP = saturday;
	case 7: dayP = sunday;
	}
}
void perform::setDay() {
	int d;
	do
	{
		cout << "Введіть номер дня (monday - 1, thuesday - 2 ... sunday - 7):";
		cin >> d;
		if (!cin || d > 7 || d < 1) {
			cout << "Не вірний номер дня";
		}
		else {
			break;
		}
	} while (true);

	switch (d)
	{
	case 1: dayP = monday; break;
	case 2: dayP = thuesday; break;
	case 3: dayP = wednesday; break;
	case 4: dayP = thursday; break;
	case 5: dayP = friday; break;
	case 6: dayP = saturday; break;
	case 7: dayP = sunday; break;
	}
}
//void perform::setEndTime() {
//	if (duration > 59) {
//		endTimeH = startTimeH + duration / 60;
//		endTimeM = startTimeM + duration % 60;
//	}
//	else {
//		if ((startTimeM + duration) > 59) {
//			endTimeM = startTimeM + duration - 60;
//			endTimeH = startTimeH + 1;
//		}
//		else {
//			endTimeM = startTimeM + duration;
//			endTimeH = startTimeH;
//		}
//	}
//}

void perform::showName() {
	cout << name << endl;
}

void perform::show() {
	cout << "##################################" << endl;
	cout << "Вистава : " << name << endl;
	cout << "Тривалість (хв) : " << duration << endl;
	cout << "Час початку : " << startTimeH << ":";
	if (startTimeM == 0) cout << "00" << endl; else cout << startTimeM << endl;
	cout << "Час закінчення вистави: " << endTimeH << ":";
	if (endTimeM == 0) cout << "00" << endl; else cout << endTimeM << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Актор [" << i + 1 << "] ";
		currrentActors[i].Show();
	}
}

string perform::getName() {
	return name;
}

int perform::getDuration() {
	return duration;
}
string perform::getStartTime() {
	string temp;
	char hh[20];
	char mm[20];
	itoa(startTimeH, hh, 10);
	itoa(startTimeM, mm, 10);

	temp.insert(0, hh);
	temp.insert(2, mm);

	return temp;
}
day perform::getDay() {
	return dayP;
}

string perform::getEndTime() {

	string temp;
	char hh[2];
	char mm[2];
	itoa(endTimeH, hh, 10);
	itoa(endTimeM, mm, 10);

	temp.insert(0, hh);
	temp.insert(2, mm);

	return temp;
}

void perform::AddActor(vector<actor>&AC) {
	int choise, k = 1;
	const int size = 3;
	int selected[size];
	bool writeAcc = true;

	for (int i = 0; i < AC.size(); i++) {
		cout << "ID Актора [" << i << "]" << endl;
		AC[i].Show();
	}

	do
	{
		cout << "Виберіть " << k << " через ID:";
		cin >> choise;
		for (int i = 0; i < size; i++)
		{
			if (choise == selected[i]) {
				writeAcc = false;
				break;
			}
			else {
				writeAcc = true;
			}
		}

		if (writeAcc) {
			currrentActors.push_back(AC[choise]);
			selected[k - 1] = choise;
			k++;
		}
		else {
			cout << "Цей актор уже бере учатсь у виставі" << endl;
		}
	} while (k <= 3);

}


void perform::setActorName(string str, int i) {
	actor temp;
	temp.SetName(str);
	currrentActors.push_back(temp);
}

void perform::setActorSurname(string str, int i) {
	currrentActors[i].SetSurName(str);
}

void perform::setActorPseudonym(string str, int i) {
	currrentActors[i].SetPseudonym(str);
}

