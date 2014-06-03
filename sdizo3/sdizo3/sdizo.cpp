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
		cout << "Wartosc: " << wektor[i] << " || Waga: " << wektor[i + 1] << endl;
		i++;
	}


	Knapsackv2 plecak(pojemnosc, li_przedmiotow);
	int licz = 0;
	for (int i = 2; i < wektor.size(); i++){
		plecak.dodaj_przedmiot(wektor[i], wektor[i + 1]);
		i++;
	}

	int rozwiazanie = plecak.algorytm();
	cout << endl << "Wartosc : " << rozwiazanie << std::endl;

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

void menu_glowne(){
	int wybor;
	system("cls");
	cout << "          MENU GLOWNE" << endl;
	cout << "-------------------------------" << endl;
	cout << "1. Problem plecakowy - przeglad zupelny" << endl;
	cout << "2. Problem plecakowy - programowanie dynamiczne" << endl;
	cout << "3. Komiwojazer jakis tam" << endl;
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
		menu_glowne();
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