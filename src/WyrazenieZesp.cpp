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
    std::cout << WyrZ.Arg1 << " ";
    std::cout << znak[WyrZ.Op] << "  "; /* Wyswietlenie znaku dzialania arytmetycznego */
    std::cout << WyrZ.Arg2;

    return StrWyj;
}


std::istream& operator >> ( std::istream &StrWej, Operator &WczytSym ){
    Operator TabTypOp[] = { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };
    const char TabSymOp[] = "+-*/", *wSymOp;
    char CzytSym = ' ';

    StrWej >> CzytSym;

    if( (wSymOp = strchr(TabSymOp,CzytSym)) == nullptr )
        StrWej.setstate(std::ios::failbit);
    else
        WczytSym = TabTypOp[wSymOp - TabSymOp]; 

    return StrWej;
}






std::istream& operator >> (std::istream &StrWej, WyrazenieZesp &WyrZ){
    std::cin >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2 ;    
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
            try{
                return WyrZ.Arg1 / WyrZ.Arg2;
            }
            catch (const char *msg){
                std::cerr << msg << std::endl;
                throw " Blad obliczen. Przyklad pominiety.";
            }
            return Blad;
        default:
            std::cerr << " Bledny operator.";
            break;
    }

    return Blad;
}