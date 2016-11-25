
#include <iostream>
#include <string>
#include <Windows.h>


#include "rozklad.h"
#include "theatre.h"

using namespace std;

void menuPerforms();
void menuActor();

theatre  kup;


void main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int ch;

	kup.getActors("actor.txt");
	kup.getFFPerf("performs.txt");

	do
	{
		cout << "[1][Актори]" << endl;
		cout << "[2][Вистави]" << endl;
		cout << "[3][Розклад]" << endl;
		cout << "[4][Вихід]" << endl;
		cout << "------------" << endl;

		cout << endl << "Виберіть пункт меню:";
		cin >> ch;

		system("cls");

		if (!cin || ch > 4 || ch < 0){
			cout << "Ви ввели неіснуючий пункт меню!!!" << "\n\n";
			cin.clear();
			cin.get();
		}
		else{
			switch (ch){
			case 1: menuActor(); break;
			case 2: menuPerforms(); break;
			case 3: break;
			case 4: exit(0); break;
			}
		}
	} while (true);


	system("pause");
}

void menuPerforms(){
	int ch;
	bool back = true;
	do
	{
		cout << "[1][Список вистав театру]" << endl;
		cout << "[2][Додати нову виставу]" << endl;
		cout << "[3][Відмінити виставу]" << endl;
		cout << "[4][Пошук вистави]" << endl;
		cout << "[5][Сортування]" << endl;
		cout << "[6]<-Назад" << endl;
		cout << "------------" << endl;

		cout << endl << "Виберіть пункт меню:";
		cin >> ch;

		system("cls");

		if (!cin || ch > 6 || ch <= 0){
			cout << "Ви ввели неіснуючий пункт меню!!!" << "\n\n";
			cin.clear();
			cin.get();
		}
		else{
			switch (ch){
			case 1: kup.getFFPerf("performs.txt");
				for (int i = 0; i < kup.Performs.size(); i++) kup.Performs[i].show(); break;
			case 2: kup.addPerform("performs.txt"); break;
			case 3: kup.detetePerform("performs.txt"); break;
			case 4: break;
			case 5: break;
			case 6: back = false; break;
			}
		}
	} while (back);
}

void menuActor(){
	int th;
	bool ct = true;
	do
	{
		cout << "[1][Список акторів театру]" << endl;
		cout << "[2][Додати актора]" << endl;
		cout << "[3][Видалити актора]" << endl;
		cout << "[4][назад]" << endl;

		cout << endl << "Виберіть пункт меню:";
		cin >> th;

		system("cls");

		if (!cin || th <= 0 || th > 5){
			cout << "Ви ввели неіснуючий пункт меню!!!" << "\n\n";
			cin.clear();
			cin.get();
		}
		else{
			switch (th)
			{
			case 1: kup.getActors("actor.txt");
				for (int i = 0; i<kup.Actors.size(); i++) kup.Actors[i].Show(); break;
			case 2: kup.getActors("actor.txt"); 
				kup.addActors("actor.txt"); break;
			case 3: kup.deleteActor("actor.txt"); break;
			case 4: ct = false; break; 
			}
		}
	} while (ct);
}


