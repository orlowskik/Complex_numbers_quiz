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
};


/*!
*  Wyswietla wyrazenie zespolone.
*/
std::ostream& operator << ( std::ostream &StrWyj, WyrazenieZesp &WyrZ);

/*!
*  Wczytuje wyrazenie zespolone.
*/
std::istream& operator >> ( std::istream &StrWej, WyrazenieZesp &WyrZ);


/*!
*  Wczytuje operator wyrazenia zespolonego.
*/
std::istream& operator >> ( std::istream &StrWej, Operator * WczytSym);


/*!
*  Oblicza wyrazenie zespolone.
*/
LZespolona Oblicz(WyrazenieZesp  WyrZ);

#endif
