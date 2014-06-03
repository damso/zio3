#include "stdafx.h"
////#include <iostream>
////#include <vector>
////#include <time.h>
////
////using namespace std;
////
////class PackEnum
////{
////
////protected:
////	vector<int> m_p; //N
////	vector<int> m_w; //N
////	int			m_c; //
////	int			m_num; //
////
////
////public:
////	
////	PackEnum();
////	PackEnum(vector<int>& p, vector<int>& w, int c, int n)
////		:m_p(p), m_w(w), m_c(c), m_num(n)
////	{}
////
////	
////	int GetBestValue() const
////	{
////		int bestValue = 0;			//
////		int currentValue = 0;		//
////		int currentWeight = 0;		//
////
////		const unsigned int max = 2 << m_num; //2N
////
////		
////		for (unsigned int i = 0; i<max; ++i)
////		{
////
////			
////			currentValue = 0;
////			currentWeight = 0;
////
////			2
////			unsigned int bit = i;
////			int j = 0;
////			while (bit != 0)
////			{
////				currentWeight += m_w[j] * (bit & 1);
////				currentValue += m_p[j] * (bit & 1);
////				bit1,bit&1 = 1 ,0
////
////				bit >>= 1;
////				++j;
////			}
////
////			
////			if (currentWeight <= m_c
////				&& bestValue < currentValue)
////			{
////				bestValue = currentValue;
////			}
////
////		}
////		return bestValue;
////	}
////
////
////};
////
////
////int wmain(void)
////{
////	srand(time(NULL));
////	
////	int n = 1000; //liczba przedmiotow
////	int c = 1000; //pojemnosc
////
////
////	vector<int> w(n);
////	vector<int> p(n);
////
////	for (int i = 0; i<n; ++i)
////		w[i] = rand() % (int)(c / 2) + 1;;
////
////
////	for (int j = 0; j<n; ++j)
////		p[j] = rand() % (int)c + 1;
////
////	PackEnum pack(p, w, c, n);
////
////	int bestValue = pack.GetBestValue();
////
////	cout << "?" << bestValue << endl;
////
////	system("PAUSE");
////	return 0;
////}
//
//#include "stdafx.h"
//#include <vector>
//#include <iostream>
//#include <iomanip>
//#include <Windows.h>
//#include <time.h>
//#include <fstream>
//#include <conio.h>
//#include "math.h" 
//
//using namespace std;
//
//
////Jest N przedmiotów, wiêc wyborów jest 2^n. Jest to bardzo czasoch³onne. Oznaczamy bitowo 1 albo 0
////0 nie ma, 1 jest
//void konwersja(int n, vector<int> &b) //zamiana 
//{
//	int i;
//	for (i = 0; i <b.size(); i++)
//	{
//		//b.push_back(n % 2);
//		b.insert(b.begin() + i, n%2);
//		n = n / 2;
//		if (n == 0) break;
//	}
//}
//
//
//void losowanie_brute(int pojemnosc, int n){	
//	for (int k = 0; k < 1; k++){
//		int i, j;
//		float maxv, temp_w, temp_v;
//
//		vector<int> w;
//		vector<int> v;
//		vector<int> b;
//		vector<int> temp;
//		
//
//		srand(time(NULL));
//		for (i = 0; i < n; i++){
//			int y = rand() % (int)(pojemnosc / 2) + 1;
//			w.push_back(y);
//		}
//
//		for (i = 0; i < n; i++){
//			int x = rand() % (int)pojemnosc + 1;
//			v.push_back(x);
//		}
//
//
//		maxv = 0;
//		for (j = 0; j < n; j++)
//		{
//			b.push_back(0);
//			temp.push_back(0);
//			//b.insert(b.begin() + j, 0);
//			//temp.insert(temp.begin() + j, 0);
//
//		}
//
//
//		StartCounter();
//		for (i = 0; i < pow((double)2, (double)n); i++) //wszystkie mozliwe kombinacje
//		{
//			konwersja(i, b);
//			temp_w = 0;
//			temp_v = 0;
//			for (j = 0; j <n; j++) //petla sprawdzaj¹ca czy wybrany przedmiot nalezy do optymalnego wyboru * /
//			if (b[j] == 1)
//			{
//				temp_w = temp_w + w[j];
//				temp_v = temp_v + v[j];
//			}
//			if ((temp_w <= pojemnosc) && (temp_v> maxv))
//			{
//				maxv = temp_v;
//				for (j = 0; j < n; j++)
//					temp[j] = b[j];
//			}
//		}
//
//		wyniki[k] = GetCounter();
//		cout << "Wartosc max: " << maxv << endl;
//	}
//zapiszWynikiBudowania(wyniki);
//
//	
//}
//
//void wczytaj_z_pliku_brute(){
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
//	int i, j;
//	float maxv, temp_w, temp_v;
//
//	vector<int> w;
//	vector<int> v;
//	vector<int> b;
//	vector<int> temp;
//	srand(time(NULL));
//
//
//	for (int i = 2; i < wektor.size(); i++){
//		v.push_back(wektor[i]);
//		w.push_back(wektor[i + 1]);
//		i++;
//	}
//
//
//	maxv = 0;
//	for (j = 0; j <li_przedmiotow; j++)
//	{
//		b.push_back(0);
//		temp.push_back(0);
//		//b.insert(b.begin() + j, 0);
//		//temp.insert(temp.begin() + j, 0);
//
//	}
//	for (i = 0; i <pow((double)2, (int)li_przedmiotow); i++) //exhaustive of all possible selection to identify the optimal choice
//	{
//		konwersja(i, b);
//		temp_w = 0;
//		temp_v = 0;
//		for (j = 0; j <li_przedmiotow; j++) //loop to determine whether the current selection to meet the optimal choice * /
//		if (b[j] == 1)
//		{
//			temp_w = temp_w + w[j];
//			temp_v = temp_v + v[j];
//		}
//		if ((temp_w <= pojemnosc) && (temp_v> maxv))
//		{
//			maxv = temp_v;
//			for (j = 0; j <li_przedmiotow; j++)
//				temp[j] = b[j];
//		}
//	}
//
//	cout << "Wartosc max: " << maxv << endl;
//
//
//
//
//
//}
//
//void menu_brute(){
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
//		wczytaj_z_pliku_brute();
//		system("pause");
//		menu_brute();
//	case '2':
//		int pojemnosc, li_przedmiotow;
//		system("cls");
//		cout << "Podaj pojemnosc plecaka: ";
//		cin >> pojemnosc;
//		cout << "Podaj liczbe przedmiotow: ";
//		cin >> li_przedmiotow;
//		losowanie_brute(pojemnosc, li_przedmiotow);
//		system("pause");
//		menu_brute();
//	case '0':
//		exit(0);
//	default:
//		menu_brute();
//	}
//}
//
//int main()
//{
//	
//	menu_brute();
//		
//	system("pause");
//	return 0;
//}