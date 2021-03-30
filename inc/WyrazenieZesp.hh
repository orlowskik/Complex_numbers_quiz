#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego

  LZespolona Oblicz() const; /*! Oblicza wyrazenie zespolone */
};


/*!
*  Wyswietla wyrazenie zespolone.
*/
std::ostream& operator << ( std::ostream &StrWyj, const WyrazenieZesp &WyrZ);

/*!
*  Wczytuje wyrazenie zespolone.
*/
std::istream& operator >> ( std::istream &StrWej, WyrazenieZesp &WyrZ);


/*!
*  Wczytuje operator wyrazenia zespolonego.
*/
std::istream& operator >> ( std::istream &StrWej, Operator * WczytSym);



#endif
