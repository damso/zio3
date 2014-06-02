#include "stdafx.h"
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class PackEnum
{

protected:
	vector<int> m_p; //N
	vector<int> m_w; //N
	int			m_c; //
	int			m_num; //


public:
	//
	PackEnum();
	PackEnum(vector<int>& p, vector<int>& w, int c, int n)
		:m_p(p), m_w(w), m_c(c), m_num(n)
	{}

	//
	int GetBestValue() const
	{
		int bestValue = 0;			//
		int currentValue = 0;		//
		int currentWeight = 0;		//

		const unsigned int max = 2 << m_num; //2N

		//
		for (unsigned int i = 0; i<max; ++i)
		{

			//
			currentValue = 0;
			currentWeight = 0;

			//2
			unsigned int bit = i;
			int j = 0;
			while (bit != 0)
			{
				currentWeight += m_w[j] * (bit & 1);
				currentValue += m_p[j] * (bit & 1);
				//bit1,bit&1 = 1 ,0

				bit >>= 1;
				++j;
			}

			//
			if (currentWeight <= m_c
				&& bestValue < currentValue)
			{
				bestValue = currentValue;
			}

		}
		return bestValue;
	}


};


int wmain(void)
{
	srand(time(NULL));
	//
	int n = 1000; //liczba przedmiotow
	int c = 1000; //pojemnosc


	vector<int> w(n);
	vector<int> p(n);

	for (int i = 0; i<n; ++i)
		w[i] = rand() % (int)(c / 2) + 1;;


	for (int j = 0; j<n; ++j)
		p[j] = rand() % (int)c + 1;

	PackEnum pack(p, w, c, n);

	int bestValue = pack.GetBestValue();

	cout << "?" << bestValue << endl;

	system("PAUSE");
	return 0;
}


