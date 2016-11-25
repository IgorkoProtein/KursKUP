#include "perform.h"

perform::perform() {
	name = "";
	duration = 0;
	startTime = 0;
	endTime = startTime + duration;
	dayP = monday;
}

perform::perform(string nm, int dur, int st, day d) {
	name = nm;
	duration = dur;
	startTime = st;
	endTime = startTime + duration;
	dayP = d;
}
void perform::setName(string nm) {
	name = nm;
}
void perform::setName() {
	cout << "Enter name of perfomance :";
	cin >> name;
}
void perform::setDuration(string dr) {
	duration = stoi(dr);
}
void perform::setDuration() {
	int n;
	while (true)
	{
		cout << "Enter duration of perfomance :";
		cin>>n;
		if(!cin){
			cout<<"Error, enter new numbers "<<endl;
			cin.clear();
			while(cin.get() !='\n');
		}
		else break;
	}
	duration = n;
}
void perform::setTime(string t) {
	startTime = stoi(t);
}
void perform::setTime() {
	int n;
	while (true)
	{
		cout << "Enter start time of perfomance :";
		cin>>n;
		if(!cin){
			cout<<"Error, enter new numbers "<<endl;
			cin.clear();
			while(cin.get() !='\n');
		}
		else break;
	}
	startTime = n;
	endTime = startTime + duration;
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
			cout << "Не";
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
void perform::setEndTime() {
	endTime = startTime + duration;
}

void perform::showName(){
	cout << name << endl;
}

void perform::show() {
	cout << endl;
	cout << "Performens name: " << name << endl;
	cout << "Duration: " << duration << endl;
	cout << "Start time: " << startTime << endl;
	cout << "End time: " << endTime << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Actor[" << i + 1<<"] " << currrentActors[i].getName() << " " << currrentActors[i].getSurName() << endl;
		cout << "His pseudonym is: " << currrentActors[i].getPseudonym() << endl << endl;
	}
	cout << endl;
}


string perform::getName() {
	return name;
}

int perform::getDuration() {
	return duration;
}
int perform::getTime() {
	return startTime;
}
day perform::getDay() {
	return dayP;
}

int perform::getEndTime(){
	endTime = startTime + duration;
	return endTime;
}

void perform::AddActor(vector<actor>&AC) {
	int choise, k = 1;
	const int size = 3;
	int selected[size];
	bool writeAcc = true;

	for (int i = 0; i < AC.size(); i++) {
		cout << "Actor ID [" << i << "]" << endl;
		AC[i].Show();
	}

	do
	{
		cout << "Please choise actor "<<k<< " by ID:";
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
			cout << "This actor was added, choise another" << endl;
		}
		
	} while (k<=3);

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

