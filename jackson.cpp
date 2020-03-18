// SPD_Jackson.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
// Grupa: WT 13: Junak Tadeusz, Karol Kędzia

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;


int r[1000]; //termin dostępności (punkt)
int p[1000]; //czas wykonania (okres)
int pom;

int main()
{
	fstream plik;

	int rozmiar = 0;

	plik.open("JACK4.DAT", ios::in);

	if (plik.good() == true){

	// wczytanie rozmiaru (liczba wierszy->liczba zadań)
		plik >> rozmiar;

		int c[1000];

	// wczytanie danych po kolei (w każdym wierszu jest para r i p)
		for (int i = 0; i < rozmiar; i++){
			plik >> r[i];
			plik >> p[i];
		}

	// sortowanie bąbelkowe (po "r", a zamiana r i p, każda para r[i] i p[i] stanowi jeden element)	
		for (int i = 0; i < rozmiar; i++) {
			for (int j = 1; j < rozmiar; j++) {
				if (r[j - 1] > r[j]) {
					pom = r[j - 1];
					r[j - 1] = r[j];
					r[j] = pom;
					pom = p[j - 1];
					p[j - 1] = p[j];
					p[j] = pom;
				}
			}

		}
		c[0] = r[0];
	
		// wyswietlenie zawartosci (sprawdza się, czy zadania są posortowane od najmniejszej do największej liczby po r)
		for (int i = 0; i < rozmiar; i++){
			cout << r[i] << " ";
			cout << p[i] << endl;
		}

		cout << rozmiar << endl;


		plik.close();

		//algorytm - wyznaczenie Cmax (c to termin zakończenia)
		for (int i = 0; i < rozmiar; i++) {
			if (c[i] >= r[i]) { // bierze się max (c,r)
				c[i + 1] = c[i] + p[i];
			}
			else {
				c[i + 1] = r[i] + p[i];
			}
		}

		cout << "C maksymalne to: " << c[rozmiar] << endl;
	}


	system("PAUSE");
	return(0);
}

