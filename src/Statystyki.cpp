#include "Statystyki.hh"
#include <iostream>

using namespace std;

/*!
 *  Inicjuje statystyke odpowiedzi
 *  Argumenty:
 *    IloscPytan - ilosc pytan w arkuszu
 *  Zwraca:
 *    Statystyke z iloscia pytan i iloscia odpowiedzi ustawiona na 0. 
 */
stat inicjuj(int IloscPytan){
    stat statystyka;
    statystyka.prawda = 0;
    statystyka.falsz = 0;
    statystyka.max = IloscPytan;

    return statystyka;
}


/*!
 *  Wyswietla statystyke
 *  Argumenty:
 *    statystyka - statystyka odpowiedzi uzytkownika.
 *  Wynik:
 *     Wyswietlenie  na standardowym wyjsciu statystyki odpowiedzi.
 */
void wyswietl(stat statystyka){
    cout << endl << "Ilosc dobrych odpowiedzi: " << noshowpos <<statystyka.prawda << endl;
    cout << "Ilosc blednych odpowiedz: " << noshowpos <<statystyka.falsz << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: "<< noshowpos << statystyka.prawda * 100 / statystyka.max << '%' << endl;
}
