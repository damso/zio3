#include "stdafx.h"
#include "TravelingSalesman.h";
#include <iostream>
#include <algorithm> //next_permutation

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

	//ustawiamy odwiedzone miasta na false
	
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

int TravelingSalesman::greedy() {
	int koszt = 9001;
	int najmniejszyKoszt = 0;
	int numerMiasta;
	int odwiedzaneMiasto;
	int nastepneMiasto = 0;

	bool *odwiedzone = new bool[liczbaMiast];
	for (int i = 0; i < liczbaMiast; i++){
		odwiedzone[i] = false;
	}

	for (int i = 0; i < liczbaMiast - 1; i++) {
		numerMiasta = nastepneMiasto;
		odwiedzone[numerMiasta] = true;
		for (int j = 0; j < liczbaMiast; j++) {
			if (macierzSasiedztwa[numerMiasta][j] < koszt) {
				odwiedzaneMiasto = j;
				if (odwiedzone[odwiedzaneMiasto] == true)
					continue;
				else {
					koszt = macierzSasiedztwa[numerMiasta][j];
					nastepneMiasto = odwiedzaneMiasto;
				}
			}
		}
		najmniejszyKoszt += koszt;
		koszt = 9001;
	}

	najmniejszyKoszt += macierzSasiedztwa[nastepneMiasto][0];
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