#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <conio.h>
#include "math.h" 

using namespace std;


//Jest N przedmiotów, wiêc wyborów jest 2^n. Jest to bardzo czasoch³onne. Oznaczamy bitowo 1 albo 0
//0 nie ma, 1 jest
void konwersja(int n, vector<int> &b) //zamiana 
{
	int i;
	for (i = 0; i <b.size(); i++)
	{
		//b.push_back(n % 2);
		b.insert(b.begin() + i, n % 2);
		n = n / 2;
		if (n == 0) break;
	}
}


void losowanie_brute(int pojemnosc, int n){
		int i, j;
		float maxv, temp_w, temp_v;

		vector<int> w;
		vector<int> v;
		vector<int> b;
		vector<int> temp;


		srand(time(NULL));
		for (i = 0; i < n; i++){
			int y = rand() % (int)(pojemnosc / 2) + 1;
			w.push_back(y);
		}

		for (i = 0; i < n; i++){
			int x = rand() % (int)pojemnosc + 1;
			v.push_back(x);
		}


		maxv = 0;
		for (j = 0; j < n; j++)
		{
			b.push_back(0);
			temp.push_back(0);
			//b.insert(b.begin() + j, 0);
			//temp.insert(temp.begin() + j, 0);

		}


		for (i = 0; i < pow((double)2, (double)n); i++) //wszystkie mozliwe kombinacje
		{
			konwersja(i, b);
			temp_w = 0;
			temp_v = 0;
			for (j = 0; j <n; j++) //petla sprawdzaj¹ca czy wybrany przedmiot nalezy do optymalnego wyboru * /
			if (b[j] == 1)
			{
				temp_w = temp_w + w[j];
				temp_v = temp_v + v[j];
			}
			if ((temp_w <= pojemnosc) && (temp_v> maxv))
			{
				maxv = temp_v;
				for (j = 0; j < n; j++)
					temp[j] = b[j];
			}
		}

		cout << "Wartosc max: " << maxv << endl;



}

void wczytaj_z_pliku_brute(){
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

	int i, j;
	float maxv, temp_w, temp_v;

	vector<int> w;
	vector<int> v;
	vector<int> b;
	vector<int> temp;
	srand(time(NULL));


	for (int i = 2; i < wektor.size(); i++){
		v.push_back(wektor[i+1]);
		w.push_back(wektor[i]);
		i++;
	}


	maxv = 0;
	for (j = 0; j <li_przedmiotow; j++)
	{
		b.push_back(0);
		temp.push_back(0);
		//b.insert(b.begin() + j, 0);
		//temp.insert(temp.begin() + j, 0);

	}
	for (i = 0; i <pow((double)2, (int)li_przedmiotow); i++) //exhaustive of all possible selection to identify the optimal choice
	{
		konwersja(i, b);
		temp_w = 0;
		temp_v = 0;
		for (j = 0; j <li_przedmiotow; j++) //loop to determine whether the current selection to meet the optimal choice * /
		if (b[j] == 1)
		{
			temp_w = temp_w + w[j];
			temp_v = temp_v + v[j];
		}
		if ((temp_w <= pojemnosc) && (temp_v> maxv))
		{
			maxv = temp_v;
			for (j = 0; j <li_przedmiotow; j++)
				temp[j] = b[j];
		}
	}

	cout << "Wartosc max: " << maxv << endl;





}