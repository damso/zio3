#ifndef TRAVELINGSALESMAN_H
#define TRAVELINGSALESMAN_H
#include <vector>

using namespace std;

class TravelingSalesman {
	int liczbaMiast;
	int **macierzSasiedztwa = new int*[liczbaMiast];
	int *miasta = new int[liczbaMiast];

public:
	//konstruktor
	TravelingSalesman(vector <int> wagiKrawedzi);

	//metody
	int bruteforce();
	void wyswietlMacierz();

	//destruktor
	~TravelingSalesman();
};
#endif