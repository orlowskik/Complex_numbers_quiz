#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.667;
    y.im = 0.667;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}


TEST_CASE("Test wyswietlania liczby zespolonej"){
    LZespolona x;

    x.re = 2;
    x.im = 2;

    std::cout << x << std::endl;

    CHECK(std::cout.fail() == 0 );
}


TEST_CASE("Test wczytywania liczby zespolonej"){
    LZespolona x;

    std::cout << "Prosze wpisac poprawna liczbe. Jest to test czytania liczby" << std::endl;
    std::cin >> x;

    CHECK(std::cin.fail() == 0 );
}