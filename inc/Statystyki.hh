#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH



#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

/*!
 *  Modeluje pojecie statystyki
 */
struct stat{
    double prawda;  /* Ilosc poprawnych odpowiedzi */
    double falsz;   /* Ilosc blednych odpowiedzi   */ 
    double max;     /* Ilosc pytan w arkuszu       */
};

/*!
 *  Wyswietla statystyke odpowiedzi
 */
void wyswietl(stat statystyka);

/*!
 *  Inicjuje statystyke
 */
stat inicjuj(int IloscPytan);
#endif
