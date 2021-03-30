#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
#include <fstream>
#include <string.h>

using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny (statyczna baza) lub  latwe, trudne (czytanie z pliku)." << endl;
    cout << endl;
    return 1;
  }

  if(strcmp(argv[1],"latwy") &&  strcmp(argv[1],"trudny") ){    /* Opcje czytania z plikow latwe.dat lub trudne.dat*/

    cout << endl;
    cout << " Start testu arytmetyki zespolonej: " ;


    stat          Statystyka_dyn;           /* Statystyka odpowiedzi */
    ifstream      PlikWej;                  /* Uchwyt do pliku */
    WyrazenieZesp Wczyt_wyrazenie;          /* Wczytane wyrazenie zespolone */
    LZespolona    Odpowiedz_2;              /* Udzielona odpowiedz */
    LZespolona    Wynik_2;                  /* Wynik wyliczony przez program */
    int           Bledy_czytania_2, Odczytano_2, Bledy_obliczen_2 ;     /* Zmienne kontrolne bledow */ 
    string        Nazwa;                    /* Zmienna przechowujaca pierwsza linie z pliku ( Informacja dla uzytkownika )*/

    if(!strcmp(argv[1],"latwe"))    /* Wybor pliku */
      PlikWej.open("latwe.dat");
    else if(!strcmp(argv[1],"trudne"))
      PlikWej.open("trudne.dat");
    else{
      cout << " Niepoprawna opcja. Dopuszczalne nazwy to:  latwy, trudny (statyczna baza) lub  latwe, trudne (czytanie z pliku)." << endl;
      return 1;
    }

    if(!PlikWej.is_open())  /* Jezeli nie udalo sie otworzyc pliku program konczy dzialanie */
      return 1;
    
    getline(PlikWej, Nazwa);  /* Wczytanie linii informacyjnej */

    cout << Nazwa << endl << endl;
    
    Statystyka_dyn.inicjuj(0); /* Inicjacja statystyki bez podania ilosci pytan */

    while(!PlikWej.eof()){    /* Przeprowadzaj czytanie az do konca pliku */
      Bledy_czytania_2 = 0;
      Odczytano_2 = 0;
      Bledy_obliczen_2 = 0;


      PlikWej >> Wczyt_wyrazenie;

      if(PlikWej.good()){

        try{                                    /* Sprawdzenie dzielenia przez 0 */
        Wynik_2 = Wczyt_wyrazenie.Oblicz();
        }
        catch ( const char* blad){
          cerr << blad << endl << endl;
          Bledy_obliczen_2++;
        }

        if(!Bledy_obliczen_2){      /* Brak bleadow - Poczatek testu */
          Statystyka_dyn.max++;
          cout << " Podaj wynik operacji: " << Wczyt_wyrazenie << "=" << endl;
          while(Bledy_czytania_2 < 3 && Odczytano_2 == 0){  /* Umozliwienie 3 poprawek wpisywania liczb */
            cout << " Twoja odpowiedz: ";
            cin >> Odpowiedz_2;
            if(cin.fail())
              Bledy_czytania_2++;
            else
              Odczytano_2++;

            cin.clear();
            cin.ignore(1024,'\n');
            if(Bledy_czytania_2 > 0 && Odczytano_2 == 0 && Bledy_czytania_2 < 3){
            cout << endl << " Blad zapisu liczby zespolonej. Sprobuj jescze raz." << endl << endl;
            }
          }

          if(Odpowiedz_2 == Wynik_2 && Bledy_czytania_2 != 3){  /* Udzielono poprawnej odpowiedzi */
            Statystyka_dyn.prawda += 1;
            cout << " Poprawna odpowiedz!" << endl;
            cout << endl;
          }
          else{                   /* Udzielono blednej odpowiedzi lub wpisano 3 razy bledne wyrazenie */
            Statystyka_dyn.falsz += 1;
            cout << " Bledna odpowiedz! Poprawna odpowiedz to: " << Wynik_2; 
            cout << endl << endl;
          }
        }
      }
      else{
        if(!PlikWej.eof())  /* Komunikat o blednym wyrazeniu w pliku ( Gdy blad powoduje koniec pliku komunikat sie nie wyswietla ) */
          cerr << " !!! Napotkano bledne wyrazenie. Zostalo ono pominiete !!!" << endl << endl ;
        PlikWej.clear();    /* Umozliwienie dalszego czytania */
        PlikWej.ignore(1024,'\n'); /* Pominiecie linijki z blednym wyrazeniem */
      }
    }

    PlikWej.close();  /* Zamkniecie pliku i koniec testu */ 
    cout << endl;
    cout << " Koniec testu" << endl;
    cout << endl;
    cout << Statystyka_dyn; /* Wyswietlenie statystyki */
  }



  else{  /* Jezeli nie wybrano czytania z pliku dane testowe brane sa z bazy */

    BazaTestu   BazaT = { nullptr, 0, 0 };

    if (InicjalizujTest(&BazaT,argv[1]) == false) {
      cerr << " Inicjalizacja testu nie powiodla sie." << endl;
      return 1;
    }


    
    cout << endl;
    cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
    cout << endl;

    WyrazenieZesp   WyrZ_Testowe;     /* Wyrazenie testowe*/
    LZespolona      Odpowiedz;        /* Odpowiedz */
    LZespolona      Wynik;            /* Wynik obliczony przez program */
    stat            Statystyka_stat;  /* Statystyka odpowiedzi */
    int             Bledy_czytania, Odczytano, Bledy_obliczen ; /* Kody bledow */



    Statystyka_stat.inicjuj(BazaT.IloscPytan); /* Inicjalizacja statystyki iloscia bytan z bazy */

    while (PobierzNastpnePytanie(&BazaT,&WyrZ_Testowe)) { /* Petla wybierajaca wyrazenia z bazy */
      Bledy_czytania = 0;
      Odczytano = 0;
      Bledy_obliczen = 0;

      try{        /* Wylapywanie dzielenia przez 0 */
      Wynik = WyrZ_Testowe.Oblicz();
      }
      catch ( const char* blad){
        cerr << blad << endl << endl;
        Statystyka_stat.max--;
        Bledy_obliczen++;
      }

      if(!Bledy_obliczen){  /* Brak bledow - poczatek testu */
        cout << " Podaj wynik operacji: " << WyrZ_Testowe << "=" << endl;
        while(Bledy_czytania < 3 && Odczytano == 0){  /* Umozliwienie porawy wpisania liczby */
          cout << " Twoja odpowiedz: ";
          cin >> Odpowiedz;
          if(cin.fail())
            Bledy_czytania++;
          else
            Odczytano++;

          cin.clear();        /* Umozliwienie ponownego wpisania liczby */
          cin.ignore(1024,'\n');
          if(Bledy_czytania > 0 && Odczytano == 0 && Bledy_czytania < 3){
          cout << endl << " Blad zapisu liczby zespolonej. Sprobuj jescze raz." << endl << endl;
          }
        }

        if(Odpowiedz == Wynik && Bledy_czytania != 3){ /* Podanie prawidlowej odpowiedzi - wykluczenie gdy 3 razy blednie wprowadzono liczbe */
          Statystyka_stat.prawda += 1;
          cout << " Poprawna odpowiedz!" << endl;
          cout << endl;
        }
        else{
          Statystyka_stat.falsz += 1;
          cout << " Bledna odpowiedz! Poprawna odpowiedz to: " << Wynik; 
          cout << endl << endl;
        }
      }
    }

    /* Koniec testu i wyswietlenie statystyki */
    cout << endl;     
    cout << " Koniec testu" << endl;
    cout << endl;
    cout << Statystyka_stat;
  }
}