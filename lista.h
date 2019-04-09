#ifndef LISTA_H
#define LISTA_H

#include "pliki.h"

using namespace std;



struct Lista
{
    Wynik dana;
    Lista *next;

};

void wczytaj_liste(string nazwa ,  Lista *&glowa, int& ilosc );
void usun_liste(Lista *glowa);
void usun( int Lp, Lista *&glowa);
void zapisz_liste(string nazwa, Lista *adres );


#endif // LISTA_H
