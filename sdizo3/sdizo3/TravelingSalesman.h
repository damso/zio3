#ifndef TRAVELINGSALESMAN_H
#define TRAVELINGSALESMAN_H
#include <vector>
#include <list>

using namespace std;

class TravelingSalesman {
	int liczbaMiast;
	int **macierz = new int * [liczbaMiast];
	//vector <int> wagiKrawedzi;

public:
	//konstruktor
	TravelingSalesman(vector <int> wagiKrawedziKonstruktor);

	//metody
	void pokazWage();

	//metody tworzenia i wyswietlania grafu
	void wyswietlMacierz();
	//int getMacierz();

	//pozosta³e gettery i settery
	//vector <int> getWagiKrawedzi();
	//void setLiczbaMiast(vector <int> _wagiKrawedzi);
	//int getLiczbaMiast();

	~TravelingSalesman();
};
#endif