#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"

TEST_CASE("Wyswietlanie wyrazenia zespolonego"){
    LZespolona x, y;
    WyrazenieZesp z;

    x.re = 2;
    x.im = 2;

    y.re = 3;
    y.im = -2;

    z.Arg1 = x;
    z.Arg2 = y;
    z.Op = Op_Dodaj;

    std::cout << z << std::endl;

    CHECK(std::cout.fail() == 0);
}



TEST_CASE("Czytanie wyrazenia zespolonego"){
    WyrazenieZesp x;

    std::cout << "Prosze wpisac powyzsze wyrazenie. Jest to test czytania wyrazenia" << std::endl;
    std::cin >> x;

    CHECK(std::cin.fail() == 0);    
}