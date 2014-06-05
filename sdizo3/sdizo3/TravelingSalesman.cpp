#include "stdafx.h"
#include "TravelingSalesman.h";
#include <iostream>

using namespace std;

//************** KONSTRUKTOR ********************
TravelingSalesman::TravelingSalesman(vector <int> wagiKrawedziKonstruktor){
	liczbaMiast = wagiKrawedziKonstruktor.front(); //pierwszy element wczytany z pliku do wektora to liczba miast
	//wagiKrawedzi = wagiKrawedziKonstruktor;
	
	//pozostale wartosci, to wagi krawedzi
	auto it = wagiKrawedziKonstruktor.begin() + 1;

	for (int i = 0; i < liczbaMiast; i++){
		macierz[i] = new int[liczbaMiast];
	}

	for (int i = 0; i < liczbaMiast; i++){
		for (int j = 0; j < liczbaMiast; j++){
			macierz[i][j] = *it;
			it++;
		}
	}
}

// *********** METODY ***************************
void TravelingSalesman::pokazWage() {
	int *wierzcholki = new int[liczbaMiast];

	for (int i = 0; i < liczbaMiast; i++) {
		wierzcholki[i] = i;
	}
	
	cout << macierz[wierzcholki[0]][wierzcholki[1]];
}

//************* WYSWIETLENIE MACIERZY (GRAFU) *******
void TravelingSalesman::wyswietlMacierz(){
	for (int i = 0; i < liczbaMiast; i++){
		for (int j = 0; j < liczbaMiast; j++){
			cout << macierz[i][j]<<" ";
		}
		cout << "\n";
	}
}


//************* AKCESORY *****************************
/*vector <int> TravelingSalesman::getWagiKrawedzi(){
	return wagiKrawedzi;
}

void TravelingSalesman::setLiczbaMiast(vector <int> _wagiKrawedzi){
	liczbaMiast = _wagiKrawedzi.front();
}

int TravelingSalesman::getLiczbaMiast(){
	return liczbaMiast;
}*/