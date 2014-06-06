#ifndef TRAVELINGSALESMAN_H
#define TRAVELINGSALESMAN_H
#include <vector>

using namespace std;

class TravelingSalesman {
	int liczbaMiast;
	int **macierzSasiedztwa;
	int *miasta;

public:
	//konstruktor
	TravelingSalesman(vector <int> wagiKrawedzi);

	//metody
	int bruteforce();
	int greedy();
	void wyswietlMacierz();

	//destruktor
	~TravelingSalesman();
};
#endif