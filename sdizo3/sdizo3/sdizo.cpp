#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include "Plecak2.h"
#include "Plecak.h"
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <list>
#include "TravelingSalesman.h"
using namespace std;

void menu_glowne();

//inicjalizacja licznika
double PCFreq = 0.0;
__int64 CounterStart = 0;
int c;
LARGE_INTEGER performanceCountStart, performanceCountEnd;

void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}


double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}
//koniec licznika

double wyniki[20];
void zapiszWynikiBudowania(double wyniki[]){
	fstream plik;
	plik.open("wyniki.txt", ios::out);

	if (plik.good() == true){
		for (int i = 0; i < 20; i++){
			plik << wyniki[i] << endl;
		}
	}
	plik.close();
}




void wczytaj_z_pliku_plecak(){
	vector<int> wektor;
	int x;
	fstream plik;
	plik.open("1.txt", std::ios::in | std::ios::out);

	if (plik.good() == true){
		while (!plik.eof()){
			plik >> x;
			wektor.push_back(x);
		}
		plik.close();
	}

	int pojemnosc = wektor[0];
	int li_przedmiotow = wektor[1];

	cout << "Pojemnosc plecaka: " << pojemnosc << endl;
	cout << "Liczba przedmiotow: " << li_przedmiotow << endl;
	cout << "-----------------------------" << endl;
	for (int i = 2; i < wektor.size(); i++){
		cout << "Waga: " << wektor[i] << " || Wartosc: " << wektor[i + 1] << endl;
		i++;
	}


	Knapsackv2 plecak(pojemnosc, li_przedmiotow);
	int licz = 0;
	for (int i = 2; i < wektor.size(); i++){
		plecak.dodaj_przedmiot(wektor[i+1], wektor[i]);
		i++;
	}

	int rozwiazanie = plecak.algorytm();
	cout << endl << "Wartosc max: " << rozwiazanie << std::endl;

}


void menu_brute(){
	int wybor;
	system("cls");
	cout << "          MENU WYBORU - Przeglad zupelny" << endl;
	cout << "-------------------------------" << endl;
	cout << "1. Wczytaj z pliku" << endl;
	cout << "2. Generuj losowo" << endl;
	cout << "0. Wroc" << endl;
	cout << "-------------------------------" << endl;

	wybor = _getch();
	switch (wybor){
	case '1':
		system("cls");
		wczytaj_z_pliku_brute();
		system("pause");
		menu_brute();
	case '2':
		int pojemnosc, li_przedmiotow;
		system("cls");
		cout << "Podaj pojemnosc plecaka: ";
		cin >> pojemnosc;
		cout << "Podaj liczbe przedmiotow: ";
		cin >> li_przedmiotow;
		losowanie_brute(pojemnosc, li_przedmiotow);
		system("pause");
		menu_brute();
	case '0':
		menu_glowne();
	default:
		menu_brute();
	}
}

void menu_dynamic(){
	int wybor;
	system("cls");
	cout << "          MENU WYBORU - programowanie dynamiczne" << endl;
	cout << "-------------------------------" << endl;
	cout << "1. Wczytaj z pliku" << endl;
	cout << "2. Generuj losowo" << endl;
	cout << "0. Wroc" << endl;
	cout << "-------------------------------" << endl;

	wybor = _getch();
	switch (wybor){
	case '1':
		system("cls");
		wczytaj_z_pliku_plecak();
		system("pause");
		menu_dynamic();
	case '2':
		int pojemnosc, li_przedmiotow;
		system("cls");
		cout << "Podaj pojemnosc plecaka: ";
		cin >> pojemnosc;
		cout << "Podaj liczbe przedmiotow: ";
		cin >> li_przedmiotow;
		losowanie(pojemnosc, li_przedmiotow);
		system("pause");
		menu_dynamic();
	case '0':
		menu_glowne();
	default:
		menu_dynamic();
	}
}

// ************** KOMIWOJA¯ER ******************
vector <int> wagiKrawedzi;
void komiwojazerzPliku(){
	vector<int> wektor;
	int x;
	fstream plik;
	plik.open("2.txt", std::ios::in | std::ios::out);

	if (plik.good() == true){
		while (!plik.eof()){
			plik >> x;
			wektor.push_back(x);
		}
		plik.close();
	}
	wagiKrawedzi = wektor;
}

/* NA POTRZEBY OBLICZEN */
vector<int> wynikiObliczen;

void obliczeniaDoPliku(vector<int> wynikiObliczen){
	auto it = wynikiObliczen.begin();

	fstream plik;
	plik.open("wynikiTSP.txt", ios::out);
	if (plik.good() == true){
		for (int i = 0; i < wynikiObliczen.size(); i++){
			plik << *it << endl;
			it++;
		}
	}

	plik.close();
}


TravelingSalesman *komiwojazer;
void menuKomiwojazera(){
	int wybor;
	system("cls");
	cout << "          MENU KOMIWOJAZERA" << endl;
	cout << "-------------------------------" << endl;
	cout << "1. Wczytaj z pliku" << endl;
	cout << "2. Wyswietl macierz sasiedztwa" << endl;
	cout << "3. Przeglad zupelny" << endl;
	cout << "4. Algorytm zachlanny" << endl;
	cout << "-------------------------------" << endl;
	cout << "9. Menu Glowne" << endl;
	cout << "0. Wyjscie" << endl;
	cout << "-------------------------------" << endl;

	wybor = _getch();
	switch (wybor){
	case '1':
		komiwojazerzPliku();
		komiwojazer = new TravelingSalesman(wagiKrawedzi);
		system("pause");
		menuKomiwojazera();
	case '2':
		system("cls");
		komiwojazer->wyswietlMacierz();
		system("pause");
		menuKomiwojazera();
	case '3':
		system("cls");
		cout << "Najmniejszy koszt: " << komiwojazer->bruteforce() << "\n";
		system("pause");
		menuKomiwojazera();
	case '4':
		system("cls");
		cout << "Najmniejszy koszt: " << komiwojazer->greedy() << "\n";
		system("pause");
		menuKomiwojazera();
	case '9':
		menu_glowne();
	case '0':
		komiwojazer->~TravelingSalesman();
		exit(0);
	default:
		menuKomiwojazera();
	}
}

void menu_glowne(){
	int wybor;
	system("cls");
	cout << "          MENU GLOWNE" << endl;
	cout << "-------------------------------" << endl;
	cout << "1. Problem plecakowy - przeglad zupelny" << endl;
	cout << "2. Problem plecakowy - programowanie dynamiczne" << endl;
	cout << "3. Asymetryczny Problem Komiwojazera" << endl;
	cout << "0. Zakoncz" << endl;
	cout << "-------------------------------" << endl;

	wybor = _getch();
	switch (wybor){
	case '1':
		system("cls");
		menu_brute();
	case '2':
		menu_dynamic();
	case '3':
		menuKomiwojazera();
	case '0':
		exit(0);
	default:
		menu_glowne();
	}
}

int main(int argc, char **argv) {

	menu_glowne();

	system("PAUSE");
	return 0;
}