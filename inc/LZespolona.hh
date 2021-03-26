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

  LZespolona  operator + (LZespolona  Skl2) const;  /*! Dodaje dwie liczby zespolone. */
  LZespolona  operator - (LZespolona  Skl2) const;  /*! Odejmuje dwie liczby zespolone */
  LZespolona  operator * (LZespolona  Skl2) const;  /*! Mnozy dwie liczby zespolone */
  LZespolona  operator / (LZespolona  Skl2) const;  /*! Dzieli dwie liczby zespolone */
  LZespolona  operator / (double  Skl2) const;      /*! Dzieli liczbe sepolona pzrez skalar */
  bool        operator == (LZespolona  Skl2) const; /*! Porownuje dwie liczby zespolone */
  double      modul();                              /*! Tworzy modul z liczby sepolonej */
  void        sprz();                               /*! Sprzega liczbe zespolona */
};

/*!
*  Wyswietla liczbe zespolona na podanym strumieniu.
*/
std::ostream&  operator << (std::ostream &StrWyj, const LZespolona &Skl1);


/*!
*  Wczytuje podana liczbe zespolona z podanego wejscia.
*/
std::istream&  operator >> (std::istream &StrWej , LZespolona &Skl1);


/*!
*   Funkcja pomocnicza uzywana przy wczytywaniu liczb zespolonych
*/
void CzytajZnak( std::istream &StrWej, char Znak);


#endif
