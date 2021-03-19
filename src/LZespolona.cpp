#include "LZespolona.hh"
#include <cmath>
#include <iostream>


#define MIN_DIFF 0.00001

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
    std::cerr << "Nie dziel przez 0" << std::endl ;

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


std::ostream&  operator << (std::ostream &StrWyj, LZespolona &Skl1){
  std::cout << std::noshowpos << '(' << Skl1.re << std::showpos << Skl1.im << 'i' << ')' << "  ";
  return StrWyj;
}


void CzytajZnak(std::istream &StrWej, char Znak){
  char CzytanyZnak = ' ';
  StrWej >> CzytanyZnak;

  if (CzytanyZnak != Znak)
    StrWej.setstate(std::ios::failbit);
  
}


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


