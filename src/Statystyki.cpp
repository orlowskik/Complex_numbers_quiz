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
void stat::inicjuj(int IloscPytan){
    this->prawda = 0;
    this->falsz = 0;
    this->max = IloscPytan;
}


/*!
 *  Wyswietla statystyke
 *  Argumenty:
 *    statystyka - statystyka odpowiedzi uzytkownika.
 *  Wynik:
 *     Wyswietlenie  na standardowym wyjsciu statystyki odpowiedzi.
 */
void stat::wyswietl() const{
    cout << endl << "Ilosc dobrych odpowiedzi: " << noshowpos <<this->prawda << endl;
    cout << "Ilosc blednych odpowiedz: " << noshowpos <<this->falsz << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: "<< noshowpos << this->prawda * 100 / this->max << '%' << endl;
}
