#include "stdafx.h"
#include "TravelingSalesman.h";
#include <iostream>

using namespace std;

//************** KONSTRUKTOR ********************
TravelingSalesman::TravelingSalesman(vector <int> wagiKrawedziKonstruktor){
	setLiczbaMiast(wagiKrawedziKonstruktor);
	wagiKrawedzi = wagiKrawedziKonstruktor;
}

// *********** METODY ***************************


//************* STWORZENIE MACIERZY (GRAFU) *****
void TravelingSalesman::setMacierz(){
	int liczbaMiast = getLiczbaMiast();
	vector <int> wagiKrawedzi = getWagiKrawedzi();
	vector<int>::iterator it;
	it = wagiKrawedzi.begin()+1;
	int **macierzMetody = new int *[liczbaMiast];

	for (int i = 0; i < liczbaMiast; i++){
		macierzMetody[i] = new int[liczbaMiast];
	}

	for (int i = 0; i < liczbaMiast; i++){
		for (int j = 0; j < liczbaMiast; j++){
			macierzMetody[i][j] = *it;
			it++;
		}
	}

	macierz = macierzMetody;
}

//************* WYSWIETLENIE MACIERZY (GRAFU) *******
int TravelingSalesman::getMacierz(){
	/*int liczbaMiast = getLiczbaMiast();
	for (int i = 0; i < liczbaMiast; i++){
		for (int j = 0; j < liczbaMiast; j++){
			cout << macierz[i][j]<<" ";
		}
		cout << "\n";
	}*/
	return **macierz;
}


//************* AKCESORY *****************************
vector <int> TravelingSalesman::getWagiKrawedzi(){
	return wagiKrawedzi;
}

void TravelingSalesman::setLiczbaMiast(vector <int> _wagiKrawedzi){
	liczbaMiast = _wagiKrawedzi.front();
}

int TravelingSalesman::getLiczbaMiast(){
	return liczbaMiast;
}