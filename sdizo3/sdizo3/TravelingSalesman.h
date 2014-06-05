#ifndef TRAVELINGSALESMAN_H
#define TRAVELINGSALESMAN_H
#include <vector>
#include <list>

using namespace std;

class TravelingSalesman {
	int liczbaMiast;
	int **macierz = new int * [liczbaMiast];
	int *wierzcholki = new int[liczbaMiast];

public:
	//konstruktor
	TravelingSalesman(vector <int> wagiKrawedziKonstruktor);

	//metody
	int bruteforce();
	void wyswietlMacierz();

	//destruktor
	~TravelingSalesman();
};
#endif