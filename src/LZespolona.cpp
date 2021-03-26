#include "LZespolona.hh"
#include <cmath>
#include <iostream>


#define MIN_DIFF 0.01 /* Dopuszczalny blad odpowiedzi */

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
  if( abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF )
    return true;
  else
    return false;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator - (LZespolona Skl1, LZespolona Skl2){
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Ilczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator * (LZespolona Skl1, LZespolona Skl2){
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}


/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia ( Modul rozny od 0).
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator / (LZespolona Skl1, LZespolona Skl2){
  LZespolona Sprz;
  LZespolona Wynik;

  if(!modul(Skl2))
    throw " Nie dziel przez 0";

  Sprz = sprz(Skl2);

  return Wynik = (Skl1 * Sprz)/modul(Skl2);

}



/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2){
  LZespolona  Wynik;
  Wynik.re = 0;
  Wynik.im = 0;



  if(Skl2){
    Wynik.re = Skl1.re / Skl2;
    Wynik.im = Skl1.im / Skl2;
  }
  else
    throw "Nie dziel przez 0";

  return Wynik;
}



/*!
 *  Realizuje modul z liczby zespolonej
 *  Argumenty:
 *    Skl1 - Liczba zespolona.
 *  Zwraca:
 *    Liczba nieujemna calkowita ( modul z liczby ). 
 */
double modul (LZespolona Skl){
  return fabs(pow(Skl.re,2) + pow(Skl.im,2));
}




/*!
 *  Realizuje sprzezenie liczby zespolonej ( zmiana znaku czesci urojonej)
 *  Argumenty:
 *    Skl1 - Liczba zespolona sprzegana.
 *  Zwraca:
 *    Wynik - Liczba po sprzezeniu.
 */
LZespolona sprz(LZespolona Skl){
  LZespolona Wynik;

  Wynik.re = Skl.re;
  Wynik.im = Skl.im * (-1);

  return Wynik;
}

/*!
 *  Wyswietla liczbe zespolona na podanym wyjsciu.
 *  Argumenty:
 *    StrWyj - Strumien wyjsciowy, na ktory ma zostac wyswietlona liczba,
 *    Skl1 - Liczba zespolona sprzegana.
 *  Zwraca:
 *    StrWyj - Strumien wyjsciowy, na ktory wypisano liczbe.
 */
std::ostream&  operator << (std::ostream &StrWyj, LZespolona &Skl1){
  StrWyj.precision(2);
  StrWyj << std::noshowpos << '(' << std::fixed << Skl1.re << std::showpos << Skl1.im << "i)" << std::noshowpos ;
  return StrWyj;
}

/*!
 *  Funkcja pomocnicza do wczytywania liczby zespolonej. Sprawdza wprowadzany znak.
 *  Argumenty:
 *    StrWej - Strumien wejsciowy, z ktorego czytany jest znak
 *    Znak - znak, ktorego oczekujemy.
 *  Wynik:
 *     Ustawia flage niepowodzenia na strumieniu jezeli wczytany znak jest inny niz oczekiwany.
 */
void CzytajZnak(std::istream &StrWej, char Znak){
  char CzytanyZnak = ' ';
  StrWej >> CzytanyZnak;

  if (CzytanyZnak != Znak)
    StrWej.setstate(std::ios::failbit);
  
}


/*!
 *  Wczytuje liczbe zespolona z podanego strumienia.
 *  Argumenty:
 *    StrWej - Strumien wejsciowy, z ktorego czytana jest liczba
 *    Skl1 - Liczba zespolona, do ktorej wpisujemy wartosci.
 *  Zwraca:
 *    StrWej - Strumien wejsciowy, z ktorego czytano liczbe.
 */
std::istream& operator >> (std::istream &StrWej, LZespolona &Skl){
  CzytajZnak(StrWej, '(');
  StrWej >> Skl.re;
  if(StrWej.fail())
    return StrWej;
  StrWej >> Skl.im;
  if(StrWej.fail())
    return StrWej;
  CzytajZnak(StrWej, 'i');
  CzytajZnak(StrWej, ')');

  return StrWej;
}


