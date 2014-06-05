#include "stdafx.h"
#include "TravelingSalesman.h";
#include <iostream>
#include <algorithm>

using namespace std;

//************** KONSTRUKTOR ********************
TravelingSalesman::TravelingSalesman(vector <int> wagiKrawedziKonstruktor){
	liczbaMiast = wagiKrawedziKonstruktor.front(); //pierwszy element wczytany z pliku do wektora to liczba miast
	
	//pozostale wartosci, to wagi krawedzi
	for (int i = 0; i < liczbaMiast; i++){
		macierz[i] = new int[liczbaMiast];
	}

	auto it = wagiKrawedziKonstruktor.begin() + 1;
	for (int i = 0; i < liczbaMiast; i++){
		for (int j = 0; j < liczbaMiast; j++){
			macierz[i][j] = *it;
			it++;
		}
	}

	for (int i = 0; i < liczbaMiast; i++) {
		wierzcholki[i] = i;
	}
}

//*************** METODY *************************
int TravelingSalesman::bruteforce(){
	int najmniejszyKoszt = 9001;

	do {
		int koszt = 0;
		for (int i = 0; i < liczbaMiast - 1; i++) {
			koszt += macierz[wierzcholki[i]][wierzcholki[i + 1]];
		}
		koszt += macierz[wierzcholki[liczbaMiast - 1]][wierzcholki[0]];
		if (koszt < najmniejszyKoszt)
			najmniejszyKoszt = koszt;
	} 
	while (next_permutation(wierzcholki, wierzcholki + liczbaMiast));

	return najmniejszyKoszt;
}

void TravelingSalesman::wyswietlMacierz(){
	for (int i = 0; i < liczbaMiast; i++){
		for (int j = 0; j < liczbaMiast; j++){
			cout << macierz[i][j]<<" ";
		}
		cout << "\n";
	}
}

TravelingSalesman::~TravelingSalesman(){
	for (int i = 0; i < liczbaMiast; i++)
		delete [] macierz[i];
	delete [] macierz;

	delete [] wierzcholki;
}