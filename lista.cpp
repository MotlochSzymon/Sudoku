#include "lista.h"



void wczytaj_liste(string nazwa ,  Lista *&glowa, int & ilosc )
{
    ilosc=0;
    ifstream plik;
    Lista *akt, *ogon;
    akt=NULL;
    glowa=NULL;
    do_wczytania( nazwa.c_str() , plik );
    while( !plik.eof() )
    {
        ogon=akt;
        akt=new Lista;
        plik>>akt->dana.poziomr;
        plik>>akt->dana.czasr;
        if(ogon==NULL) glowa=akt;
        else ogon->next=akt;

        akt->next=NULL;
        ilosc++;

    }

}
void usun_liste(Lista *glowa)
{
    Lista *pom;
    while(glowa!=NULL)
    {
        pom=glowa;
        glowa=glowa->next;
        delete pom;
    }
}


void usun( int Lp, Lista *&glowa)
{
    Lista *akt, *poprz;
    if(Lp==1)
    {
        akt=glowa;
        glowa=glowa->next;
        delete akt;

    }else
    {
    akt=glowa;
    for(int i=0; i<Lp-1; i++)
    {
        poprz=akt;
        akt=akt->next;
    }

    poprz->next=akt->next;
    delete akt;
}
}

void zapisz_liste(string nazwa, Lista *adres )
{
    ofstream plik(nazwa.c_str());
    plik.clear();
    while(adres!=NULL)
    {

       plik << adres->dana.poziomr<<endl;
       plik << adres->dana.czasr<<endl;
       adres = adres->next;


    }
    plik.close();

}




