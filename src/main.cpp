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

  if(strcmp(argv[1],"latwy") &&  strcmp(argv[1],"trudny") ){

    cout << endl;
    cout << " Start testu arytmetyki zespolonej: " ;


    stat          Statystyka_dyn;
    ifstream      PlikWej;
    WyrazenieZesp Wczyt_wyrazenie;
    LZespolona    Odpowiedz_2;
    LZespolona    Wynik_2;
    int           Bledy_czytania_2, Odczytano_2, Bledy_obliczen_2 ;    
    string        Nazwa;

    if(!strcmp(argv[1],"latwe"))
      PlikWej.open("latwe.dat");
    else if(!strcmp(argv[1],"trudne"))
      PlikWej.open("trudne.dat");
    else{
      cout << " Niepoprawna opcja. Dopuszczalne nazwy to:  latwy, trudny (statyczna baza) lub  latwe, trudne (czytanie z pliku)." << endl;
      return 1;
    }

    if(!PlikWej.is_open())
      return 1;
    
    getline(PlikWej, Nazwa);

    cout << Nazwa << endl << endl;
    
    Statystyka_dyn.inicjuj(0);

    while(!PlikWej.eof()){
      Bledy_czytania_2 = 0;
      Odczytano_2 = 0;
      Bledy_obliczen_2 = 0;


      PlikWej >> Wczyt_wyrazenie;

      if(PlikWej.good()){

        try{
        Wynik_2 = Wczyt_wyrazenie.Oblicz();
        }
        catch ( const char* blad){
          cerr << blad << endl << endl;
          Bledy_obliczen_2++;
        }

        if(!Bledy_obliczen_2){
          Statystyka_dyn.max++;
          cout << " Podaj wynik operacji: " << Wczyt_wyrazenie << "=" << endl;
          while(Bledy_czytania_2 < 3 && Odczytano_2 == 0){ 
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

          if(Odpowiedz_2 == Wynik_2 && Bledy_czytania_2 != 3){
            Statystyka_dyn.prawda += 1;
            cout << " Poprawna odpowiedz!" << endl;
            cout << endl;
          }
          else{
            Statystyka_dyn.falsz += 1;
            cout << " Bledna odpowiedz! Poprawna odpowiedz to: " << Wynik_2; 
            cout << endl << endl;
          }
        }
      }
      else{
        if(!PlikWej.eof())
          cerr << " !!! Napotkano bledne wyrazenie. Zostalo ono pominiete !!!" << endl << endl ;
        PlikWej.clear();
        PlikWej.ignore(1024,'\n');
      }
    }

    PlikWej.close();
    cout << endl;
    cout << " Koniec testu" << endl;
    cout << endl;
    cout << Statystyka_dyn;
  }



  else{

    BazaTestu   BazaT = { nullptr, 0, 0 };

    if (InicjalizujTest(&BazaT,argv[1]) == false) {
      cerr << " Inicjalizacja testu nie powiodla sie." << endl;
      return 1;
    }


    
    cout << endl;
    cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
    cout << endl;

    WyrazenieZesp   WyrZ_Testowe;
    LZespolona      Odpowiedz;
    LZespolona      Wynik;
    stat            Statystyka_stat;
    int             Bledy_czytania, Odczytano, Bledy_obliczen ;



    Statystyka_stat.inicjuj(BazaT.IloscPytan);

    while (PobierzNastpnePytanie(&BazaT,&WyrZ_Testowe)) {
      Bledy_czytania = 0;
      Odczytano = 0;
      Bledy_obliczen = 0;

      try{
      Wynik = WyrZ_Testowe.Oblicz();
      }
      catch ( const char* blad){
        cerr << blad << endl << endl;
        Statystyka_stat.max--;
        Bledy_obliczen++;
      }

      if(!Bledy_obliczen){
        cout << " Podaj wynik operacji: " << WyrZ_Testowe << "=" << endl;
        while(Bledy_czytania < 3 && Odczytano == 0){ 
          cout << " Twoja odpowiedz: ";
          cin >> Odpowiedz;
          if(cin.fail())
            Bledy_czytania++;
          else
            Odczytano++;

          cin.clear();
          cin.ignore(1024,'\n');
          if(Bledy_czytania > 0 && Odczytano == 0 && Bledy_czytania < 3){
          cout << endl << " Blad zapisu liczby zespolonej. Sprobuj jescze raz." << endl << endl;
          }
        }

        if(Odpowiedz == Wynik && Bledy_czytania != 3){
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

    cout << endl;
    cout << " Koniec testu" << endl;
    cout << endl;
    cout << Statystyka_stat;
  }
}