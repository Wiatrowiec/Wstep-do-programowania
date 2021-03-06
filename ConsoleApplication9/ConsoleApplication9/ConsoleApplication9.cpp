// Zbior zadan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;
//----------------------------------------------------------------------
// WYSWIETLANIE //
void wyswietl(vector<int> wyswietl)
{
	for (int y = 0; y < wyswietl.size(); y++)
	{
		cout << wyswietl[y] << '\t';
	}
	cout << endl;
}
void wyswietl(map<int, int> wysmap)
{
	for each (auto element in wysmap)
	{
		cout << element.first << " " << element.second << endl;
	}
}
void wyswietl(vector<vector<int>> tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		wyswietl(tab[i]);
	}
}
//----------------------------------------------------------------------
int suma(vector<int> suma)
{
	int d = 0;
	for (int iy = 0; iy < suma.size(); iy++)
	{
		d += suma[iy];
	}
	return d;
}
//----------------------------------------------------------------------
float srednia(vector<int> srednia)
{
	float wynik = suma(srednia);
	return wynik / srednia.size();
}
//----------------------------------------------------------------------
int minimum(vector<int> minm)
{
	int x = minm[0];
	for (int i = 1; i < minm.size(); i++)
	{
		if (x>minm[i])
		{
			x = minm[i];
		}
	}
	return x;
}
//----------------------------------------------------------------------
int maksymalny(vector<int> max)
{
	int x = max[0];
	for (int i = 1; i < max.size(); i++)
	{
		if (x < max[i])
		{
			x = max[i];
		}
	}
	return x;
}
//----------------------------------------------------------------------
bool belong(vector<int> belong, int a)
{


	for (int i = 0; i < belong.size(); i++)
	{
		if (a == belong[i])
		{
			return true;
		}
	}
	return false;
}

bool belong(map<int, int> mapa, int wartosc)
{
	for each(auto element in mapa)
	{
		//element.first
		//element.second
		if (element.second == wartosc)
		{
			return true;
		}
	}
	return false;
}

bool belongindex(map <int, int > mapa, int wartosc)
{
	for each(auto element in mapa)
	{
		if (element.first == wartosc)
		{
			return true;
		}
	}
	return false;
}
//----------------------------------------------------------------------
bool unikalnosc2(vector<int> podstawa, vector<int> sprawdzacz)  //czy wektor zawiera sie w wektorze
{
	for (int i = 0; i < sprawdzacz.size(); i++)
	{
		if (!belong(podstawa, sprawdzacz[i]))
		{
			return false;
		}
	}
	return true;
}
//----------------------------------------------------------------------
vector<int>unikal(vector<int> costam) //usuwanie duplikatow
{
	vector<int>wynik;
	for (int i = 0; i < costam.size(); i++)
	{
		if (!belong(wynik, costam[i]))
		{
			wynik.push_back(costam[i]);
		}
	}
	return wynik;
}

map<int, int>czestosc(vector<int> czesto) // ilosc powtorzen w wektorze zapisana jako mapa
{
	map<int, int>czestosc2;
	for (int i = 0; i < czesto.size(); i++)
	{
		if (!belongindex(czestosc2, czesto[i]))
		{
			czestosc2.insert(pair<int, int>(czesto[i], 1));
		}
		else
		{
			czestosc2[czesto[i]]++;
		}
	}
	return czestosc2;
}
//----------------------------------------------------------------------
vector<int>generowanie(int ile) //Generowanie pseudolosowego wektora o dlugosci "ile"
{
	vector<int>wynik;
	for (int i = 0; i < ile; i++)
	{
		wynik.push_back(rand() % 20);
	}
	return wynik;
}
vector < vector<int>> generowanie(int ilewierszy, int ilekolumn) // Generowanie vektora dwuwymiarowego
{
	vector<vector<int>>wynik;
	for (int i = 0; i < ilewierszy; i++)
	{
		vector<int>wiersz = generowanie(ilekolumn);
		wynik.push_back(wiersz);
	}
	return wynik;
}
//-----------------------------------------------------------------------
vector<int> kolumna(vector<vector<int>> tab, int kolumn)
{
	vector<int>wynik;
	for (int i = 0; i < tab.size(); i++)
	{
		wynik.push_back(tab[i][kolumn]);
	}

	return wynik;
}
//-----------------------------------------------------------------------
map<int, int>gender(vector<vector<int>>tab)
{
	vector<int>costam = kolumna(tab, tab[0].size() - 1);
	map<int, int>gender = czestosc(costam);
	return gender;
}
//-----------------------------------------------------------------------
int najmniejszy_macierzy(vector<vector<int>>macierze)
{
	int pomocnicza = macierze[0][0];
	for (int i = 0; i < 4; i++)
	{
		if ((minimum(kolumna(macierze, i)) < pomocnicza))
		{
			pomocnicza = minimum(kolumna(macierze, i));
		}
	}

	return pomocnicza;
}
//------------------------------------------------------ 
// W index = {najmniejsza wartosc,numer wiersza,numer kolumny};
vector<int> najmniejszy_macierzy1(vector<vector<int>>macierze)
{
	int pomocnicza = macierze[0][0];
	vector<int>index = { 0,0,0 };
	{
		for (int i = 0; i < macierze.size(); i++)
		{
			for (int y = 0; y < macierze[i].size(); y++)
			{
				if (macierze[i][y] < pomocnicza)
				{
					pomocnicza = macierze[i][y];
					index[1] = i+1;
					index[2] = y+1;
					index[0] = pomocnicza;
				}
			}
		}
	}
	return index;
}

int main()
{
	vector<int> nieliczby;
	vector<int> liczby;
	for (int i = 0; i < 5; i++)
	{
		liczby.push_back(rand() % 9999);
	}
	liczby.push_back(41);
	for (int i = 0; i < 5; i++)
	{
		nieliczby.push_back(i);
	}
	vector<vector<int>>macierz;
	vector<int>w = { 3, 4, 5, 6, 7, 2 };
	macierz.push_back(w);
	wyswietl(liczby);
	cout << "\n";
	cout << "Rozmiar wektora:   ";
	cout << liczby.size() << endl;
	cout << "\n";
	cout << "Suma: ";
	cout << suma(liczby);
	cout << "\n";
	cout << "Srednia: ";
	cout << srednia(liczby);
	cout << "\n";
	cout << "Minimalny element: ";
	cout << minimum(liczby) << endl;
	cout << "Maksymalny element: ";
	cout << maksymalny(liczby) << endl;
	cout << "Wyswietl" << endl;
	wyswietl(unikal(liczby));
	cout << endl;
	cout << "Czy wektor jest podzbiorem (0 falsz, 1 prawda) " << unikalnosc2(liczby, nieliczby) << endl;
	cout << "Czestotliwosc: " << endl;
	wyswietl(czestosc(liczby));
	cout << "Pseudolosowy wktor n-elementowy" << endl;
	wyswietl(generowanie(14));
	cout << endl;
	cout << "Wyswietl macierz: " << endl;
	wyswietl(generowanie(4, 4));
	cout << endl;
	vector<vector<int>> costam = generowanie(4, 4);
	wyswietl(costam);
	cout << endl;
	wyswietl(kolumna(costam, 3));
	cout << endl;
	map<int, int>plec = gender(costam);
	wyswietl(plec);
	cout << endl;
	vector<vector<int>> costam12 = generowanie(4, 4);
	wyswietl(costam12);
	wyswietl(najmniejszy_macierzy1(costam));
	system("pause");

	return 0;
}