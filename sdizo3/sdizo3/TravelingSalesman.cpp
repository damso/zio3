#include "stdafx.h"
#include "TravelingSalesman.h";
#include <iostream>
#include <algorithm>

using namespace std;

//************** KONSTRUKTOR ********************
TravelingSalesman::TravelingSalesman(vector <int> wagiKrawedzi){
	liczbaMiast = wagiKrawedzi.front(); //pierwszy element wczytany z pliku do wektora to liczba miast
	
	//tworze macierz sasiedztwa
	for (int i = 0; i < liczbaMiast; i++){
		macierzSasiedztwa[i] = new int[liczbaMiast];
	}

	//wypelniam macierz sasiedztwa kolejnymi wagami z wektora
	auto it = wagiKrawedzi.begin() + 1;
	for (int i = 0; i < liczbaMiast; i++){
		for (int j = 0; j < liczbaMiast; j++){
			macierzSasiedztwa[i][j] = *it;
			it++;
		}
	}

	//tworze tablice miast (wierzcholkow), ktore posluza do permutacji
	for (int i = 0; i < liczbaMiast; i++) {
		miasta[i] = i;
	}
}

//*************** METODY *************************
int TravelingSalesman::bruteforce(){
	int najmniejszyKoszt = 9001;

	do {
		int koszt = 0;
		for (int i = 0; i < liczbaMiast - 1; i++) {
			koszt += macierzSasiedztwa[miasta[i]][miasta[i + 1]];
		}
		koszt += macierzSasiedztwa[miasta[liczbaMiast - 1]][miasta[0]];
		if (koszt < najmniejszyKoszt)
			najmniejszyKoszt = koszt;
	} 
	while (next_permutation(miasta, miasta + liczbaMiast));

	return najmniejszyKoszt;
}

void TravelingSalesman::wyswietlMacierz(){
	for (int i = 0; i < liczbaMiast; i++){
		for (int j = 0; j < liczbaMiast; j++){
			cout << macierzSasiedztwa[i][j] << " ";
		}
		cout << "\n";
	}
}

TravelingSalesman::~TravelingSalesman(){
	for (int i = 0; i < liczbaMiast; i++)
		delete[] macierzSasiedztwa[i];
	delete[] macierzSasiedztwa;

	delete[] miasta;
}