#include "stdafx.h"
#include "TravelingSalesman.h";
#include <iostream>
#include <algorithm>

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
void TravelingSalesman::bruteforce(){
	int *wierzcholki = new int[liczbaMiast];
	int koszt;

	for (int i = 0; i < liczbaMiast; i++) {
		wierzcholki[i] = i;
	}

	do {
		
		for (int i = 0; i < liczbaMiast; i++)
			cout << wierzcholki[i] << " ";
		cout << "\n";
	} 
	while (next_permutation(wierzcholki, wierzcholki + liczbaMiast));
}

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