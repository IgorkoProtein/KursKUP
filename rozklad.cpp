#include "rozklad.h"

void rozklad::setStHr(){
	cout << "¬вед≥ть час початку вистави (гг:хх) :";
	getline(cin, startHr);

	//int size = startHr.length();
	//int* position = new int[size];
	//char symbol;


	//for (int j = 32, i = 0; j < 256; j++)
	//{
	//	if (j < 48 || j > 58){
	//		symbol = j;
	//		//4294967295
	//		if (startHr.find(symbol) != 4294967295){
	//			position[i] = startHr.find(symbol);
	//			i++;
	//		}
	//	}
	//}

	//for (int i = 0; i < size; i++)
	//{
	//	cout << position[i] << endl;
	//	
	//	if (position[i] != -842150451){
	//		startHr.replace(position[i], 1, "");
	//	}
	//}

	//cout << startHr << endl;
	//delete[] position;
}

void rozklad::setPerform(perform prfm){
	//ѕерев≥рка доступност≥ години
	for (int i = 0; i < Performs.size(); i++){
		if (prfm.getTime() < Performs[i].getTime()){

		}
	}

	Performs.push_back(prfm);
}
