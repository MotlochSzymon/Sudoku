#ifndef ALGORYTMY_H
#define ALGORYTMY_H


#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstdio>

#include "struktury.h"

using namespace std;

/** \brief Struktura która stanowi plansze sudoku.
 *
 * Składa się z liczby całkowitej oraz wartosci logicznej
 * 
 */


struct Sud
{
    ///
    int pole;
    bool wypelnione;
};
void a();
void b();
void generuj(Sud tab[][N]);
bool poziomo(Sud tab[][N], int w , int liczba );
bool pionowo(Sud tab[][N], int k, int liczba );
bool kwadrat(Sud tab[][N], int k, int w, int liczba );
bool dobrze(Sud tab[][N], int k, int w, int liczba);
void losuj (Sud tab[][N], int poziom);
bool wypelnione (Sud tab[][N]);
bool szukaj_pustego(Sud tab[][N], int &k, int &w);
void zapamietaj(Sud tab[][N], Sud tab2[][N]);
bool rozwiazanie ( Sud tab[][N] );
 void dobra_plansza(int poziom, Sud tab2[][N],Sud tab[][N]);


#endif // ALGORYTMY_H
