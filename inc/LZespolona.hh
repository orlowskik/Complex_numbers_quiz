#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include<iostream>


/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};



/*!
*  Porownuje dwie liczby zespolone.
*/
bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);


/*!
*  Dodaje dwie liczby zespolone.
*/
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

/*!
*  Odejmuje dwie liczby zespolone.
*/
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);


/*!
*  Mnozy dwie liczby zespolone.
*/
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);


/*!
*  Dzieli dwie liczby zespolone.
*/
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);


/*!
*  Dzieli liczbe zespolona przez liczbe rzeczywista.
*/
LZespolona operator  /  (LZespolona Skl1,  double   Skl2);


/*!
*  Wyswietla liczbe zespolona na podanym strumieniu.
*/
std::ostream&  operator << (std::ostream &StrWyj, LZespolona &Skl1);


/*!
*  Wczytuje podana liczbe zespolona z podanego wejscia.
*/
std::istream&  operator >> (std::istream &StrWej , LZespolona &Skl1);


/*!
*   Funkcja pomocnicza uzywana przy wczytywaniu liczb zespolonych
*/
void CzytajZnak( std::istream &StrWej, char Znak);


/*!
*  Tworzy modul podniesiony do kwadratu z liczby zespolonej. 
*/
double modul(LZespolona Skl);


/*!
*  Wykonuje sprzezenie liczby zespolonej.
*/
LZespolona sprz(LZespolona Skl);

#endif
