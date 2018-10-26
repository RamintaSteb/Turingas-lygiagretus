// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

class turing {
	//akjf
private: string B[100]; // busena
		 char K[100]; // kintamasis
		 char P[100]; // pakeicia
		 char J[100]; //juda
		 string N[100]; // nauja busena
		 string eil;
		 int kiek;
		 int kuris;
		 string busena;
public:
	void skaitymas(std::string file)
	{
		ifstream F((file + ".txt").c_str());
		F >> kuris;
		kuris--;//nes skaiciuojam nuo 0
		F >> eil;
		kiek = 0;
		while (!F.eof()) // nuskaito
		{
			F >> B[kiek];
			F >> K[kiek];
			F >> P[kiek];
			F >> J[kiek];
			F >> N[kiek];
			kiek++;
		}
		F.close();
		kiek--;
		busena = "0";
	}
	void judejimas(bool &baigta)
	{
		baigta = false;
		for (int i = 0; i < kiek; i++)
		{
			if (!_kbhit())
			{
				if (i == kiek - 1 && (B[i] != busena || K[i] != eil[kuris])) baigta = true;
				if (B[i] == busena && K[i] == eil[kuris])
				{
					eil[kuris] = P[i];
					if (J[i] == 'R') kuris++;
					else kuris--;
					if (kuris < 0) baigta = true;
					busena = N[i];
					cout << eil << endl;
					i = kiek;
				}
			}
		}
	}
	void last(string &eilut)
	{
		eilut = eil;
	}
};

int main()
{
	turing one;
	turing two;
	turing three;
	turing four;
	bool baigta1=0, baigta2=0, baigta3=0, baigta4=0;
	string eil;
	//------------------------------------------------------
	string file = "1";
	one.skaitymas(file);
	file = "2";
	two.skaitymas(file);
	file = "3";
	three.skaitymas(file);
	file = "4";
	four.skaitymas(file);
	//------------------------------------------------------
	while (baigta1 != 1 || baigta2 != 1 || baigta3 != 1 || baigta4 != 1)
	{
		system("CLS");
		if (!baigta1) one.judejimas(baigta1);
		else 
		{
			one.last(eil);
			cout << eil << endl;
		}
		if (!baigta2) two.judejimas(baigta2);
		else
		{
			two.last(eil);
			cout << eil << endl;
		}
		if (!baigta3) three.judejimas(baigta3);
		else
		{
			three.last(eil);
			cout << eil << endl;
		}
		if (!baigta4) four.judejimas(baigta4);
		else
		{
			four.last(eil);
			cout << eil << endl;
		}
		Sleep(50);
	}
	cout << "Visos programos baige darba" << endl;

	return 0;
}
