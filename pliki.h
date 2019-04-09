#ifndef PLIKI_H
#define PLIKI_H

#include <string>

#include "algorytmy2.h"

void do_wczytania(string nazwa, ifstream &plik);
void zapisz_gre(string nazwa, Sud tab[][N], Sud tab2[][N], Wynik dana);
bool wczytanie_gry(string nazwa, Sud tab[][N], Sud tab2[][N], Wynik &dana);
bool zapisz_wyniki(string nazwa, Wynik dana );

#endif // PLIKI_H
