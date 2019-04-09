#include "pliki.h"


void do_wczytania(string nazwa, ifstream &plik)
{

        plik.open(nazwa.c_str() );
        if( !plik.is_open() )
        {
            plik.close();
            exit(0);
         }
}





void zapisz_gre(string nazwa, Sud tab[][N], Sud tab2[][N], Wynik dana)
{
    ofstream plik(nazwa.c_str());
        for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            plik<<tab[j][i].pole<<endl;
            plik<<tab[j][i].wypelnione<<endl;
        }

         for(int i=0; i<N; i++)
         for(int j=0; j<N; j++)
        {
            plik<<tab2[j][i].pole<<endl;
            plik<<tab2[j][i].wypelnione<<endl;
        }
        plik<<dana.poziomr<<endl;
        plik<<dana.czasr<<endl;
        plik.close();
}

bool wczytanie_gry(string nazwa, Sud tab[][N], Sud tab2[][N], Wynik &dana)
{
     ifstream plik;
     do_wczytania(nazwa.c_str() , plik);
     generuj(tab);
        for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            plik>>tab[j][i].pole;
            plik>>tab[j][i].wypelnione;
        }

         for(int i=0; i<N; i++)
         for(int j=0; j<N; j++)
        {
            plik>>tab2[j][i].pole;
            plik>>tab2[j][i].wypelnione;
        }
        plik>>dana.poziomr;
        plik>>dana.czasr;
        plik.close();
        if( zawartosc(tab)) return 1;
        else return 0;
}


bool zapisz_wyniki(string nazwa, Wynik dana )
{
    int i=0;

    ifstream plik;
    Wynik tab[M];
    czysc(tab);

        do_wczytania(nazwa.c_str() ,plik);

         while(!plik.eof() )
         {
            plik>>tab[i].poziomr;
            plik>>tab[i].czasr;
            i++;
         }

    if( dana.czasr>tab[M-1].czasr) return 0;
    else
    {
        znajdz_miejsce(tab,  dana);
    }

    plik.close();
    ofstream plik1(nazwa.c_str());
    for(int i=0; i<M; i++)
    {
        plik1<<tab[i].poziomr;
        plik1<<tab[i].czasr;
    }



    plik1.close();
    return 1;
}



