#include "algorytmy.h"



void generuj(Sud tab[][N])
{
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            tab[j][i].pole=0;
            tab[j][i].wypelnione=0;
        }
}



bool poziomo(Sud tab[][N], int w , int liczba )
{

    for(int i=0; i<N; i++)
    {
        if( tab[i][w].pole== liczba) return 0;

    }

    return 1;
}


bool pionowo(Sud tab[][N], int k, int liczba )
{

    for(int i=0; i<N; i++)
    {
        if( tab[k][i].pole== liczba) return 0;

    }
  return 1;
}


bool kwadrat(Sud tab[][N], int k, int w, int liczba )
{
     int m,n;
     m=k/3;
     n=w/3;
     for(int i=3*m; i<(3*m)+3; i++)
     {
         for(int j=3*n; j<(3*n)+3; j++)
         {
             if(tab[i][j].pole==liczba) return 0;
         }
     }


 return 1;
}



bool dobrze(Sud tab[][N], int k, int w, int liczba)
{
     if(kwadrat(tab, k, w, liczba) && poziomo(tab, w, liczba) && pionowo(tab, k, liczba) )
    {
        return 1;
    }
    else return 0;
}


void losuj (Sud tab[][N], int poziom)
{
    int n,k,w;
    int num;
    srand(time(NULL));
    if(poziom==1) n=rand()%5 + 26;
    if(poziom==2) n=rand()%6 + 20;
    if(poziom==3) n=rand()%2 + 19;
    if(poziom==4) n=rand()%2 + 17;


    for(int i=0; i<n; i++)
    {
        do
        {
        k=rand()%9;
        w=rand()%9;
        }while(tab[k][w].pole!=0);

            num= rand()%9 +1;

            while(dobrze(tab, k,w, num)==0 )
            {
                num= rand()%9 +1;
            }

            tab[k][w].pole=num;
            tab[k][w].wypelnione=1;

    }


}


bool wypelnione (Sud tab[][N])
{
    for(int i=0; i<N; i++)
    {

        for(int j=0; j<N; j++)
        {

            if(tab[j][i].pole==0)
                       return 0;
                   }

    }
    return 1;

}
bool szukaj_pustego(Sud tab[][N], int &k, int &w)
{
        for(int i=0; i<N; i++)
        {

        for(int j=0; j<N; j++)
            if(tab[j][i].pole==0)
            {
                k=j;
                w=i;
            return 1;
      }
  }
        return 0;
}

void zapamietaj(Sud tab[][N], Sud tab2[][N])
 {
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab2[j][i].pole=tab[j][i].pole;
            tab2[j][i].wypelnione=tab[j][i].wypelnione;
        }
    }
}




bool rozwiazanie (Sud tab[][N])
{

    int k,w;

    if(! szukaj_pustego( tab, k, w) )
    return 1;

 for(int num=1; num<=9; num++)
    {



            if(dobrze(tab, k, w, num) )
             {
                tab[k][w].pole=num;
                if( rozwiazanie (tab) )
                return 1;

                tab[k][w].pole=0;
             }


    }

      return 0;


}




void dobra_plansza(int poziom, Sud tab2[][N],Sud tab[][N])
{

    generuj(tab);
    losuj(tab,poziom);
    zapamietaj(tab,tab2);
do{

        while( !rozwiazanie(tab)  )
        {

            generuj(tab);
            losuj(tab,poziom);
            zapamietaj(tab,tab2);


        }
   }while ( ! wypelnione(tab) );
}
