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

    w = z.Oblicz();

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

    w = z.Oblicz();

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

    w = z.Oblicz();

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

    w = z.Oblicz();

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
    
    WARN_THROWS( w = z.Oblicz()  );
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

    std::ostringstream out;

    out << z;
    std::cout << out.str() << std::endl;

    CHECK( out.str() == "(2.00+2.00i)+(3.00-2.00i)");
}



TEST_CASE("Czytanie wyrazenia zespolonego"){
    WyrazenieZesp x;

    std::istringstream in("(5.00+3.00i)-(3.12-4.00i)");
    in >> x;
    std::ostringstream out;
    out << x;
    std::cout << out.str() << std::endl;

    CHECK("(5.00+3.00i)-(3.12-4.00i)" == out.str() );    
}