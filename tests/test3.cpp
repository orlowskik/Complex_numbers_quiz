#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"





TEST_CASE("Obliczanie wyrazenia zespolonego - dodawanie"){
    LZespolona x, y, w;
    WyrazenieZesp z;

    x.re = 2;
    x.im = 2;

    y.re = 3;
    y.im = -2;

    z.Arg1 = x;
    z.Arg2 = y;
    z.Op = Op_Dodaj;

    w = Oblicz(z);

    CHECK( (w.re == 5 && w.im == 0) );
}


TEST_CASE("Obliczanie wyrazenia zespolonego - odejmowanie"){
    LZespolona x, y, w;
    WyrazenieZesp z;

    x.re = 2;
    x.im = 2;

    y.re = 3;
    y.im = -2;

    z.Arg1 = x;
    z.Arg2 = y;
    z.Op = Op_Odejmij;

    w = Oblicz(z);

    CHECK( (w.re == -1 && w.im == 4) );
}


TEST_CASE("Obliczanie wyrazenia zespolonego - mnozenie"){
    LZespolona x, y, w;
    WyrazenieZesp z;

    x.re = 2;
    x.im = 2;

    y.re = 3;
    y.im = -2;

    z.Arg1 = x;
    z.Arg2 = y;
    z.Op = Op_Mnoz;

    w = Oblicz(z);

    CHECK( (w.re == 10 && w.im == 2) );
}


TEST_CASE("Obliczanie wyrazenia zespolonego - dzielenie"){
    LZespolona x, y, w;
    WyrazenieZesp z;

    x.re = 5;
    x.im = 4;

    y.re = 2;
    y.im = -2;

    z.Arg1 = x;
    z.Arg2 = y;
    z.Op = Op_Dziel;

    w = Oblicz(z);

    CHECK( (w.re == 0.25 && w.im == 2.25) );
}


TEST_CASE("Obliczanie wyrazenia zespolonego - dzielenie przez 0"){
    LZespolona x, y, w;
    WyrazenieZesp z;

    x.re = 5;
    x.im = 4;

    y.re = 0;
    y.im = 0;

    z.Arg1 = x;
    z.Arg2 = y;
    z.Op = Op_Dziel;
    
    WARN_THROWS( w = Oblicz(z)  );
}



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

    std::cout << "Prosze wpisac poprawne wyrazenie. Jest to test czytania wyrazenia" << std::endl;
    std::cin >> x;

    CHECK(std::cin.fail() == 0);    
}