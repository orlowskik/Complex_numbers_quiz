#include "WyrazenieZesp.hh"
#include <iostream>
#include <cstring>




/*!
 * Wyswietla wyrazenie zespolone
 * Argumenty:
 *    StrWyj - podany strumien wyjsciowy
 *    WyrZ - wyrazenie zespolone do wyswietlenia
 * Wynik:
 *    Wyswietlenie wyrazenia zespolonego na standardowym wyjsciu.
 */
std::ostream& operator << ( std::ostream &StrWyj, WyrazenieZesp &WyrZ){
    char znak[]={'+','-','*','/'};      /* Tablica zawierajaca mozliwe znaki dzialan arytmetycznych */
    StrWyj << WyrZ.Arg1;
    StrWyj << znak[WyrZ.Op]; /* Wyswietlenie znaku dzialania arytmetycznego */
    StrWyj << WyrZ.Arg2;

    return StrWyj;
}


/*!
 *  Wczytuje operator wyrazenia zespolonego z podanego strumienia. Przeciazenie pomocnicze.
 *  Argumenty:
 *    StrWej - Strumien wejsciowy, z ktorego czytany jest operator
 *    WczytSym - Operator stosowany w wyrazeniu zespolonym
 *  Zwraca:
 *    StrWej - Strumien wejsciowy, z ktorego czytano operator.
 */
std::istream& operator >> ( std::istream &StrWej, Operator &WczytSym ){
    Operator TabTypOp[] = { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel }; /* Mozliwe operatory w tablicy numerowanej */
    const char TabSymOp[] = "+-*/", *wSymOp;        /* Tablica mozliwych opcji i wskaznik na wczytany symbol*/
    char CzytSym = ' ';     /* Wczytany symbol */

    StrWej >> CzytSym;

    if( (wSymOp = strchr(TabSymOp,CzytSym)) == nullptr )    /* Sprawdzenie, czy wczytany znak jest mozliwym operatorem i ustawienie wskaznika na miejsce jego wystepowania */
        StrWej.setstate(std::ios::failbit);
    else
        WczytSym = TabTypOp[wSymOp - TabSymOp]; /* W wypadku podania prawidlowej opcji ustawienie operatora */

    return StrWej;
}





/*!
 *  Wczytuje wyrazenie zespolone z podanego strumienia.
 *  Argumenty:
 *    StrWej - Strumien wejsciowy, z ktorego czytane jest wyrazenie
 *    WyrZ - Wyrazenie zespolone, do ktorego wpisujemy wartosci.
 *  Zwraca:
 *    StrWej - Strumien wejsciowy, z ktorego czytano wyrazenie.
 */
std::istream& operator >> (std::istream &StrWej, WyrazenieZesp &WyrZ){
    StrWej >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2 ;    
    return StrWej;
}




/*!
 * Oblicza wyrazenia zespolone
 * Argumenty:
 *    WyrZ - wyrazenie zespolone do obliczenia.
 * Zwraca:
 *    Wynik dzialan arytmetycznych na liczbach zespolonych.
 */
LZespolona Oblicz(WyrazenieZesp  WyrZ){
    LZespolona Blad;
    Blad.re = 0;
    Blad.im = 0;

    switch(WyrZ.Op){        /* Wybor dzialania do wykonania */
        
        case 0 :
            return WyrZ.Arg1 + WyrZ.Arg2;
        case 1 :
            return WyrZ.Arg1 - WyrZ.Arg2;
        case 2 :
            return WyrZ.Arg1 * WyrZ.Arg2;
        case 3 :
            try{                                            /* Obsluga wyjatkow. Dzielenie przez 0 */ 
                return WyrZ.Arg1 / WyrZ.Arg2;
            }
            catch (const char *msg){
                std::cerr << msg << std::endl;
                throw " Blad obliczen. Przyklad pominiety.";
            }
            return WyrZ.Arg1 / WyrZ.Arg2;
        default:
            std::cerr << " Bledny operator.";
            break;
    }

    return Blad;
}