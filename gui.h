#ifndef GUI_H
#define GUI_H

#include "lista.h"
#include <limits>

void start();
void podzial_kwadrat(int k, int w );
void wyswietl(Sud tab[][N]);
void wyswietl_liste(Lista *adres);
void wyswietl_najlepsze(string nazwa, Lista *&adres, int &ilosc);
void gra( Sud tab[][N], Sud tab2[][N],double dodatkowy, int poziom );
#endif // GUI_H
