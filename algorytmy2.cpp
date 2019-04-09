#include "algorytmy2.h"


double czas(clock_t poczatek, clock_t koniec)
{
    double p,k;
    p=static_cast < double >( poczatek ) / CLOCKS_PER_SEC;
    k=static_cast < double >( koniec ) / CLOCKS_PER_SEC;
    return (k-p) *(1000/60);
}


void czysc(Wynik tab[M])
{
    for(int i=0; i<M; i++)
    {
        tab[i].czasr=0;
        tab[i].poziomr=0;
    }
}

void przesun(Wynik tab[M], int k)
{
    for(int i=M-2; i>=k; i--)
    {
        tab[i+1].poziomr=tab[i].poziomr;
        tab[i+1].czasr=tab[i].czasr;

    }
}


void znajdz_miejsce(Wynik tab[M], Wynik dana)
{
  for(int i=0; i<M; i++)
  {
    if(dana.czasr < tab[i].czasr)
    {
      przesun(tab,i);
      tab[i].poziomr=dana.poziomr;
      tab[i].czasr=dana.czasr;

     }
    }
 }


bool sprawdz_rozwiazanie(Sud tab[][N])
{
    if( ! wypelnione ( tab ) ) return 0;
    for(int i=0; i<N ; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(! dobrze(tab, j, i, tab[j][i].pole )) return 0;
        }
    }
    return 1;
}


bool wskaz_blad(Sud tab[][N], int &k, int &w)
      {
                    for(int i=0; i<N; i++)
            {
                    for(int j=0; j<N; j++)
                {
                    if(!dobrze(tab,j,i,tab[j][i].pole) )
                    {
                       k=j;
                       w=i;
                      return 1;

                    }
                }
            }

      return 0;
}

  bool zawartosc(Sud tab[][N])
  {
       for(int i=0; i<N; i++)
        {
          for(int j=0; j<N; j++)
            {
               if(tab[j][i].pole!=0) return 1;
             }
         }
              return 0;
  }

