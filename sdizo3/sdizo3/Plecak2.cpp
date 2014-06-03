#include "stdafx.h"
//#include <vector>
//#include <iostream>
//#include <iomanip>
//#include <string>
//#include "Plecak.h"
//#include <Windows.h>
//#include <time.h>
//#include <fstream>
//#include <conio.h>
//using namespace std;
//
//
////inicjalizacja licznika
//double PCFreq = 0.0;
//__int64 CounterStart = 0;
//int c;
//LARGE_INTEGER performanceCountStart, performanceCountEnd;
//
//void StartCounter()
//{
//	LARGE_INTEGER li;
//	if (!QueryPerformanceFrequency(&li))
//		cout << "QueryPerformanceFrequency failed!\n";
//
//	PCFreq = double(li.QuadPart) / 1000.0;
//
//	QueryPerformanceCounter(&li);
//	CounterStart = li.QuadPart;
//}
//
//
//double GetCounter()
//{
//	LARGE_INTEGER li;
//	QueryPerformanceCounter(&li);
//	return double(li.QuadPart - CounterStart) / PCFreq;
//}
////koniec licznika
//
//double wyniki[20];
//void zapiszWynikiBudowania(double wyniki[]){
//	fstream plik;
//	plik.open("wyniki.txt", ios::out);
//
//	if (plik.good() == true){
//		for (int i = 0; i < 20; i++){
//			plik << wyniki[i] << endl;
//		}
//	}
//	plik.close();
//}
//
//
//Knapsackv2::Knapsackv2(int pojemnosc_plecaka, int liczba_przedm) :
//t_pojemnosc_plecaka(pojemnosc_plecaka),
//t_liczba_przedm(liczba_przedm),
//plecak_tablica(liczba_przedm + 1, vector<int>(pojemnosc_plecaka + 1)),
//wybieranie_plecak(liczba_przedm + 1, vector<int>(pojemnosc_plecaka + 1)){
//	t_przedmiot.reserve(t_liczba_przedm);
//}
//void Knapsackv2::dodaj_przedmiot(int wartosc, int rozmiar) {
//	przedmiot p;
//	p.wartosc = wartosc;
//	p.rozmiar = rozmiar;
//	t_przedmiot.push_back(p);
//}
//int Knapsackv2::algorytm() {
//	//Petla inicjalizujaca. Wypelnianie zerami tablic
//	for (int i = 0; i < t_pojemnosc_plecaka + 1; i++) {
//		plecak_tablica[0][i] = 0;
//		wybieranie_plecak[0][i] = 0;
//	}
//
//	int wiersz = 1;
//
//	for (vector<przedmiot>::iterator przedmIterator = t_przedmiot.begin(); przedmIterator != t_przedmiot.end(); ++przedmIterator) {
//		przedmiot obecnyPrzedm = *przedmIterator;
//		int kolumna = 0; // kolumna zawiera dostêpna pojemnoœæ.
//
//		while (kolumna < t_pojemnosc_plecaka + 1) {
//			if (obecnyPrzedm.rozmiar > kolumna) {
//				plecak_tablica[wiersz][kolumna] = plecak_tablica[wiersz - 1][kolumna];
//
//				wybieranie_plecak[wiersz][kolumna] = 0; //Wpisanie zer do tablicy wyboru
//			}
//			else {
//				//Bierzemy pod uwagê przedmiot
//				int rozmiar_zostal = kolumna - obecnyPrzedm.rozmiar;
//				int new_wartosc = obecnyPrzedm.wartosc + plecak_tablica[wiersz - 1][rozmiar_zostal];
//				int prev_wartosc = plecak_tablica[wiersz - 1][kolumna];
//				if (prev_wartosc >= new_wartosc) {
//					// Czy poprzednia wartosc jest wieksza niz nowa wartosc
//					plecak_tablica[wiersz][kolumna] = plecak_tablica[wiersz - 1][kolumna];
//					wybieranie_plecak[wiersz][kolumna] = 0;
//				}
//				else {
//					// Dodanie przedmiotu do plecaka
//					plecak_tablica[wiersz][kolumna] = new_wartosc;
//					// Aktualizacja tablicy wyboru, czyl wpisanie 1 w odpowiednie miejsce
//					wybieranie_plecak[wiersz][kolumna] = 1;
//				}
//			}
//			kolumna++;
//		}
//		wiersz++;
//	}
//	return plecak_tablica[t_liczba_przedm][t_pojemnosc_plecaka];
//}
//
//
//Knapsackv2::~Knapsackv2() {}
//
//
//
//void wczytaj_z_pliku(){
//	vector<int> wektor;
//	int x;
//	fstream plik;
//	plik.open("1.txt", std::ios::in | std::ios::out);
//
//	if (plik.good() == true){
//		while (!plik.eof()){
//			plik >> x;
//			wektor.push_back(x);
//		}
//		plik.close();
//	}
//
//	int pojemnosc = wektor[0];
//	int li_przedmiotow = wektor[1];
//
//	cout << "Pojemnosc plecaka: " << pojemnosc << endl;
//	cout << "Liczba przedmiotow: " << li_przedmiotow << endl;
//	cout << "-----------------------------" << endl;
//	for (int i = 2; i < wektor.size(); i++){
//		cout << "Wartosc: " << wektor[i] << " || Waga: " << wektor[i + 1] << endl;
//		i++;
//	}
//
//
//	Knapsackv2 plecak(pojemnosc, li_przedmiotow);
//	int licz = 0;
//	for (int i = 2; i < wektor.size(); i++){
//		plecak.dodaj_przedmiot(wektor[i], wektor[i + 1]);
//		i++;
//	}
//
//	int rozwiazanie = plecak.algorytm();
//	cout << endl << "Wartosc : " << rozwiazanie << std::endl;
//
//}
//
//
//
//void losowanie(int pojemnosc, int li_przedmiotow){
//	srand(time(NULL));
//
//	//int pojemnosc = 21;	// Pojemnosc plecaka B
//	//int li_przedmiotow = 8; //Liczba przedmiotów N
//
//	Knapsackv2 plecak(pojemnosc, li_przedmiotow);
//	for (int i = 0; i < li_przedmiotow; i++){
//		int x = rand() % (int)pojemnosc + 1;
//		int y = rand() % (int)(pojemnosc / 2) + 1;
//		plecak.dodaj_przedmiot(x, y);
//	}
//
//	int rozwiazanie = plecak.algorytm();
//	cout << endl << "Wartosc : " << rozwiazanie << std::endl;
//}
//
//void menu_glowne(){
//	int wybor;
//	system("cls");
//	cout << "          MENU WYBORU" << endl;
//	cout << "-------------------------------" << endl;
//	cout << "1. Wczytaj z pliku" << endl;
//	cout << "2. Generuj losowo" << endl;
//	cout << "0. Zakoncz" << endl;
//	cout << "-------------------------------" << endl;
//
//	wybor = _getch();
//	switch (wybor){
//	case '1':
//		system("cls");
//		wczytaj_z_pliku();
//		system("pause");
//		menu_glowne();
//	case '2':
//		int pojemnosc, li_przedmiotow;
//		system("cls");
//		cout << "Podaj pojemnosc plecaka: ";
//		cin >> pojemnosc;
//		cout << "Podaj liczbe przedmiotow: ";
//		cin >> li_przedmiotow;
//		losowanie(pojemnosc, li_przedmiotow);
//		system("pause");
//		menu_glowne();
//	case '0':
//		exit(0);
//	default:
//		menu_glowne();
//	}
//}
//
//
//
//int wmain(int argc, char **argv) {
//
//	menu_glowne();
//
//	system("PAUSE");
//	return 0;
//}