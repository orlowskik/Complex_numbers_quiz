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
    void wyswietl() const; /*! Wyswietla statystyke odpowiedzi */
    void inicjuj(int IloscPytan);   /*! Inicjuje statystyke */
};

#endif
