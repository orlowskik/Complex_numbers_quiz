#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"

using namespace std;




int main(int argc, char **argv)
{
  
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


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
  stat            Statystyka;
  int             Bledy_czytania, Odczytano, Bledy_obliczen ;



  Statystyka = inicjuj(BazaT.IloscPytan);

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_Testowe)) {
    Bledy_czytania = 0;
    Odczytano = 0;
    Bledy_obliczen = 0;

    try{
    Wynik = Oblicz(WyrZ_Testowe);
    }
    catch ( const char* blad){
      cerr << blad << endl << endl;
      Statystyka.max--;
      Bledy_obliczen++;
    }

    if(!Bledy_obliczen){
      Wynik = Oblicz(WyrZ_Testowe);
      cout << " Podaj wynik operacji: " << WyrZ_Testowe << "=" << endl;
      cout << " Twoja odpowiedz: ";
      while(Bledy_czytania < 3 && Odczytano == 0){ 

        cin >> Odpowiedz;
        if(cin.fail())
          Bledy_czytania++;
        else
          Odczytano++;

        cin.clear();
        cin.ignore(1024,'\n');
        if(Bledy_czytania > 0 && Odczytano == 0){
        cout << " Bledne wprowadzenie. Sprobuj ponownie" << endl;
        cout << " Twoja odpowiedz: ";
        }
      }
      cout << endl;


      if(Odpowiedz == Wynik){
        Statystyka.prawda += 1;
        cout << " Poprawna odpowiedz!" << endl;
        cout << endl;
      }
      else{
        Statystyka.falsz += 1;
        cout << " Bledna odpowiedz! Poprawna odpowiedz to: " << Wynik; 
        cout << endl << endl;
      }
    }
  }

  

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

  wyswietl(Statystyka);

}