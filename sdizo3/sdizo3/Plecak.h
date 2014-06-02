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