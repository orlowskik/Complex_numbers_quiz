#include "LZespolona.hh"
#include <cmath>
#include <iostream>


#define MIN_DIFF 0.1 /* Dopuszczalny blad odpowiedzi */

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  LZespolona::operator == (LZespolona  Skl2) const{
  double roznica1 = MIN_DIFF , roznica2 = MIN_DIFF;
  

  if(Skl2.re != 0 ){
    while(  fabs( Skl2.re ) < roznica1){
        roznica1 /= 10;
    }
  }

  if(Skl2.im != 0 ){
    while(  fabs( Skl2.im ) < roznica2 ){
        roznica2 /= 10;
    }
  }
  
  roznica1 /= 10;
  roznica2 /= 10;


  if( fabs(this->re - Skl2.re) <= roznica1 && fabs(this->im - Skl2.im) <= roznica2 )
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
LZespolona  LZespolona::operator + (LZespolona  Skl2) const{
  Skl2.re += this->re;
  Skl2.im += this->im;

  return Skl2;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator - (LZespolona Skl2) const{
   Skl2.re = this->re - Skl2.re;
   Skl2.im = this->im - Skl2.im;

  return Skl2;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Ilczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator * (LZespolona Skl2) const{
  LZespolona Wynik;

  Wynik.re = this->re * Skl2.re - this->im * Skl2.im;
  Wynik.im = this->re * Skl2.im + this->im * Skl2.re;
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
LZespolona LZespolona::operator / (LZespolona Skl2) const{
  LZespolona Wynik;
  double modul;

  Wynik.re = 0;
  Wynik.im = 0;
  modul = Skl2.modul();

  if( !modul )
    throw " Nie dziel przez 0";

  Skl2.sprz();

  return Wynik = (*this * Skl2) / modul;
}



/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator / (double  Skl2) const{
  LZespolona  Wynik;
  Wynik.re = 0;
  Wynik.im = 0;



  if(Skl2){
    Wynik.re = this->re / Skl2;
    Wynik.im = this->im / Skl2;
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
double  LZespolona::modul (){
  return fabs(pow(this->re,2) + pow(this->im,2));
}




/*!
 *  Realizuje sprzezenie liczby zespolonej ( zmiana znaku czesci urojonej)
 *  Argumenty:
 *    Skl1 - Liczba zespolona sprzegana.
 *  Zwraca:
 *    Wynik - Liczba po sprzezeniu.
 */
void LZespolona::sprz(){

  this->im = this->im * (-1) ;
}

/*!
 *  Wyswietla liczbe zespolona na podanym wyjsciu.
 *  Argumenty:
 *    StrWyj - Strumien wyjsciowy, na ktory ma zostac wyswietlona liczba,
 *    Skl1 - Liczba zespolona sprzegana.
 *  Zwraca:
 *    StrWyj - Strumien wyjsciowy, na ktory wypisano liczbe.
 */
std::ostream&  operator << (std::ostream &StrWyj, const LZespolona &Skl1){
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


