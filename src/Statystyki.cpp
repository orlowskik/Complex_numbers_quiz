#include "Statystyki.hh"
#include <iostream>


/*!
 *  Inicjuje statystyke odpowiedzi
 *  Argumenty:
 *    IloscPytan - ilosc pytan w arkuszu
 *  Zwraca:
 *    Statystyke z iloscia pytan i iloscia odpowiedzi ustawiona na 0. 
 */
void stat::inicjuj(int IloscPytan){
    this->prawda = 0;
    this->falsz = 0;
    this->max = IloscPytan;
}


/*!
 *  Wyswietla statystyke
 *  Argumenty:
 *    Ostream - strumien wyjsciowy, na ktory nalezy wypisac statystyke
 *    Statystyka - statystyka odpowiedzi uzytkownika.
 *  Wynik:
 *     Wyswietlenie na podanym wyjsciu statystyki odpowiedzi.
 *  Zwraca :
 *    Podany strumien wyjsciowy.
 */
std::ostream& operator << (std::ostream &StrWyj, const stat Statystyka){
    
    if(Statystyka.prawda < 0 || Statystyka.max < 0 || Statystyka.falsz < 0 || Statystyka.prawda + Statystyka.falsz != Statystyka.max ){ /* Wykluczenie bledow statystyki */
        std::cerr << " Bledna statystyka odpowiedzi !!! " << std::endl;
        StrWyj.setstate(std::ios::failbit);
        return StrWyj;
    }


    StrWyj << " Ilosc dobrych odpowiedzi: " << Statystyka.prawda << std::endl;
    StrWyj << " Ilosc blednych odpowiedz: " << Statystyka.falsz << std::endl;
    StrWyj << " Wynik procentowy poprawnych odpowiedzi: " << Statystyka.prawda * 100 / Statystyka.max << '%' << std::endl;

    return StrWyj;
}
