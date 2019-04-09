#include "gui.h"

void start()
{
    int wybor=0;
    int i;
   Sud tab[N][N], tab2[N][N];
    Wynik dana;
    char decyzja;
    int poziom;
    int element;
    int ilosc;
    Lista *adres;

    while(wybor!=4)
 {
        cout<< "Witaj w grze Sudoku, co chcesz zrobic?" <<endl;


    cout<< "Rozpaczasc nowa gre (1)"<<endl;
    cout<< "Wczytaj wczesniej zapisana gre (2)" <<endl;
    cout<< "Wyswietl najlepsze rezultaty (3)" <<endl;
    cout<< "Wyjdz (4) "<<endl;
    cout<<"Wprowadz odpowiednia liczbe: ";
    cin>>wybor;


    while(wybor!=1 && wybor!=2 && wybor!=3 && wybor!=4)
    {
    cout<<"Wprowadz poprawne dane"<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n') ;
    cin>>wybor;
    }





    if(wybor==1)
    {


        cout << "Wybierz poziom: "<<endl;
        cout << "Latwy (1)" <<endl;
        cout << "Sredni(2)" <<endl;
        cout << "Trudny (3)" <<endl;
        cout << "Ekspert (4)" <<endl;

        cin>>poziom;

        while(poziom!=1 && poziom !=2 && poziom!= 3 && poziom !=4)
        {
        cout<<"Wprowadz poprawne dane"<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n') ;
        cin>>poziom;
        }






        dobra_plansza(poziom, tab, tab2);

        gra(tab, tab2, 0,poziom);


    }

    else if(wybor==2)
    {
        if( wczytanie_gry("Zapis.txt",  tab, tab2, dana) )
        {
            gra(tab ,tab2, dana.czasr, dana.poziomr);
        } else cout<<"Brak zapisu"<<endl;
    }
    else if(wybor==3)
    {

        wyswietl_najlepsze("Najszybsze.txt",  adres , ilosc);


        cout<<"Chcesz usunac jakos pozycje?(T/N) "<<endl;
        cin>>decyzja;
        while(decyzja !='T' && decyzja !='t' && decyzja !='N' && decyzja !='n' )
        {
            cout<<"Podano zle dane, wprowadz ponownie"<<endl;
            cout<<"Chcesz usunac jakos pozycje?(T/N) "<<endl;
            cin>>decyzja;
        }

        if(decyzja=='T' || decyzja=='t')
        {
            cout<<"Ktory elemnt usunac?"<<endl;
            cin>>element;
             if(element<1 || element>ilosc) cout<<"Nie ma takiej danej"<<endl;
             else
             {
             usun( element, adres);
             wyswietl_liste(adres);
             zapisz_liste( "Najszybsze.txt", adres);
             }
        }
        usun_liste(adres);


    }
    else if(wybor=4) exit(0);



}


}
void podzial_kwadrat( int k, int w )
{

     int m,n;
     m=k/3;
     n=w/3;

     if(3*n==w && k==0)
     {
         cout<<"------------"<<endl;

     }
      if(k==0) cout<<w+1;
      if(3*m==k) cout<<"|";


}

void wyswietl(Sud tab[][N])
{
    cout<<"  123 456 789"<<endl;
    for(int j=0; j<N; j++)
    {
        for(int i=0; i<N; i++)
        {
            podzial_kwadrat( i , j );
            cout<<tab[i][j].pole;
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

void wyswietl_liste(Lista *adres)
{
    int Lp=1;
    while(adres!=NULL)
    {
        cout<<Lp<<endl;
        cout<<"Poziom: " << adres->dana.poziomr <<"  ";

        cout<<"Czas: " <<fixed<< setprecision(3)<<adres->dana.czasr <<endl;
        adres=adres->next;
        Lp++;
    }
}
void wyswietl_najlepsze(string nazwa, Lista *&adres, int &ilosc)
{
    ifstream plik_wcz;
    do_wczytania(nazwa.c_str(), plik_wcz);
    wczytaj_liste(nazwa.c_str(), adres, ilosc);
    wyswietl_liste(adres);
    plik_wcz.close();
}

void gra( Sud tab[][N], Sud tab2[][N],double dodatkowy, int poziom )
{

    clock_t poczatek = clock();
    int k,w,num;
     char opcje;
    Wynik dana;
    int k2,w2;
    while(! sprawdz_rozwiazanie(tab ) )
    {
        wyswietl(tab);

            cout << "Wprowadz wartosci" <<endl;
            cout << "Kolumna: ";
            cin >> k;




            while(k!=1 && k!=2 && k!=3 && k!=4 && k!=5 && k!=6 && k!=7 && k!=8 && k!=9)
            {
            cout<<"Wprowadz poprawne dane"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n') ;
            cin>>k;
            }

            cout << "Wiersz: ";
            cin >> w;


            while(w!=1 && w!=2 && w!=3 && w!=4 && w!=5 && w!=6 && w!=7 && w!=8 && w!=9)
            {
            cout<<"Wprowadz poprawne dane"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n') ;
            cin>>w;
            }


            cout << "Wartosc: ";
            cin >> num;

            while(num!=1 && num!=2 && num!=3 && num!=4 && num!=5 && num!=6 && num!=7 && num!=8 && num!=9)
            {
            cout<<"Wprowadz poprawne dane"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n') ;
            cin>>num;
            }


                cout<<endl;
                cout<<"Opcje: "<<endl<<endl;
                cout<< "Kontynuj (K)" <<endl;
                cout<<"Pokazac rozwiazanie? (R)"<<endl;
                cout<< "Zapisz i wyjdz (Z)" <<endl;
                cout<<"Pokaz blad (B)" <<endl;
                cin>>opcje;
                system( "cls");
                if(opcje=='R' || opcje== 'r')  wyswietl (tab2);
                else if(opcje=='Z'|| opcje== 'z')
                {
                    clock_t koniec = clock();
                    dana.czasr=dodatkowy + czas(poczatek,koniec);
                    dana.poziomr=poziom;
                     zapisz_gre("Zapis.txt" ,tab, tab2, dana);
                     exit(0);
                }
                else if(opcje=='B' || opcje =='b')
                {

                   if( wskaz_blad( tab, k2, w2) ) cout<<"Nieprawidlowa wartosc w kolumnie "<<k<<" i wierszu "<<w<<endl;
                   else cout<<"Nie znaleziono bledu"<<endl;
                }



                cout<<endl<<endl;

                if( ( (k>9 || k<1) || (w>9 || w<1) || (num>9 || num<1) ) && k!=10 && w!=10 && num!=10 ) cout<<endl<<"Bledne dane, podaj ponownie"<<endl<<endl;
            else if(tab[k-1][w-1].wypelnione==1) cout<<endl<<"Nie mozna zmienic tej wartosci"<<endl<<endl;
            else if (k>=1 && k<=9 && w>=1 && w<=9 && tab[k-1][w-1].wypelnione==0)
                        tab[k-1][w-1].pole=num;



    }
    clock_t koniec = clock();
    dana.czasr= dodatkowy+ czas(poczatek,koniec);
    dana.poziomr=poziom;
    cout<<"Brawo!! Udalo Ci sie rozwiazac gre w czasie "<<czas(poczatek,koniec)+dodatkowy <<"minut"<<endl;
    zapisz_wyniki("Najszybsze.txt", dana);

}





