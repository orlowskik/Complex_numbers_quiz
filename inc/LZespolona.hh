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


/*
 *  Zapowiedzi definicji przeciazen operatorow
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona operator  /  (LZespolona Skl1,  double   Skl2);

std::ostream&  operator << (std::ostream &StrWyj, LZespolona &Skl1);

std::istream&  operator >> (std::istream &StrWej , LZespolona &Skl1);


/*!
*   Funkcja pomocnicza uzywana przy wczytywaniu liczb zespolonych
*/
void CzytajZnak( std::istream &StrWej, char Znak);


/*
* Zapowiedz definicji modulu i sprzezenia
*/

double modul(LZespolona Skl);

LZespolona sprz(LZespolona Skl);

#endif
