#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


struct przedmiot {
	int wartosc;
	int rozmiar;
};

class Knapsackv2 {
public:
	Knapsackv2(int pojemnosc_plecaka, int liczba_przedm); //konstruktor
	~Knapsackv2(); //destruktor

	void dodaj_przedmiot(int wartosc, int rozmiar); //funkcja dodajaca przedmiot do wektora
	int  algorytm(); //glowny algorytm Knapsack albo Rucksack



private:
	vector<przedmiot> t_przedmiot;
	int t_pojemnosc_plecaka;
	int t_liczba_przedm;

	vector<vector<int> > plecak_tablica; //Tablica przechowujaca wynik poœredni obliczeñ plecakowych
	vector<vector<int> > wybieranie_plecak; //Tablica przechowujaca wynik posredni przedmiotów wybranych. 
};


Knapsackv2::Knapsackv2(int pojemnosc_plecaka, int liczba_przedm) :
t_pojemnosc_plecaka(pojemnosc_plecaka),
t_liczba_przedm(liczba_przedm),
plecak_tablica(liczba_przedm + 1, vector<int>(pojemnosc_plecaka + 1)),
wybieranie_plecak(liczba_przedm + 1, vector<int>(pojemnosc_plecaka + 1)){
	t_przedmiot.reserve(t_liczba_przedm);
}
void Knapsackv2::dodaj_przedmiot(int wartosc, int rozmiar) {
	przedmiot p;
	p.wartosc = wartosc;
	p.rozmiar = rozmiar;
	t_przedmiot.push_back(p);
}
int Knapsackv2::algorytm() {
	//Petla inicjalizujaca. Wypelnianie zerami tablic
	for (int i = 0; i < t_pojemnosc_plecaka + 1; i++) {
		plecak_tablica[0][i] = 0;
		wybieranie_plecak[0][i] = 0;
	}

	int wiersz = 1;

	for (vector<przedmiot>::iterator przedmIterator = t_przedmiot.begin(); przedmIterator != t_przedmiot.end(); ++przedmIterator) {
		przedmiot obecnyPrzedm = *przedmIterator;
		int kolumna = 0; // kolumna zawiera dostêpna pojemnoœæ.

		while (kolumna < t_pojemnosc_plecaka + 1) {
			if (obecnyPrzedm.rozmiar > kolumna) {
				plecak_tablica[wiersz][kolumna] = plecak_tablica[wiersz - 1][kolumna];

				wybieranie_plecak[wiersz][kolumna] = 0; //Wpisanie zer do tablicy wyboru
			}
			else {
				//Bierzemy pod uwagê przedmiot
				int rozmiar_zostal = kolumna - obecnyPrzedm.rozmiar;
				int new_wartosc = obecnyPrzedm.wartosc + plecak_tablica[wiersz - 1][rozmiar_zostal];
				int prev_wartosc = plecak_tablica[wiersz - 1][kolumna];
				if (prev_wartosc >= new_wartosc) {
					// Czy poprzednia wartosc jest wieksza niz nowa wartosc
					plecak_tablica[wiersz][kolumna] = plecak_tablica[wiersz - 1][kolumna];
					wybieranie_plecak[wiersz][kolumna] = 0;
				}
				else {
					// Dodanie przedmiotu do plecaka
					plecak_tablica[wiersz][kolumna] = new_wartosc;
					// Aktualizacja tablicy wyboru, czyl wpisanie 1 w odpowiednie miejsce
					wybieranie_plecak[wiersz][kolumna] = 1;
				}
			}
			kolumna++;
		}
		wiersz++;
	}
	return plecak_tablica[t_liczba_przedm][t_pojemnosc_plecaka];
}


Knapsackv2::~Knapsackv2() {}







void losowanie(int pojemnosc, int li_przedmiotow){
	srand(time(NULL));

	//int pojemnosc = 21;	// Pojemnosc plecaka B
	//int li_przedmiotow = 8; //Liczba przedmiotów N

	Knapsackv2 plecak(pojemnosc, li_przedmiotow);
	for (int i = 0; i < li_przedmiotow; i++){
		int x = rand() % (int)pojemnosc + 1;
		int y = rand() % (int)(pojemnosc / 2) + 1;
		plecak.dodaj_przedmiot(x, y);
	}

	int rozwiazanie = plecak.algorytm();
	cout << endl << "Wartosc : " << rozwiazanie << std::endl;
}