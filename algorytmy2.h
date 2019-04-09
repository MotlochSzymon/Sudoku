#ifndef ALGORYTMY2_H
#define ALGORYTMY2_H

#include <fstream>

#include "algorytmy.h"



//#include <cstdio>
//#include <ctime>

struct Wynik
{
    double czasr;
    int poziomr;
};

double czas(clock_t poczatek, clock_t koniec);
void czysc(Wynik tab[M]);
void przesun(Wynik tab[M], int k);
void znajdz_miejsce(Wynik tab[M], Wynik dana);
bool sprawdz_rozwiazanie(Sud tab[][N]);
bool wskaz_blad(Sud tab[][N], int &k, int &w);
bool zawartosc(Sud tab[][N]);


#endif // ALGORYTMY2_H
