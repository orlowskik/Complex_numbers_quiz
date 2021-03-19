#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}


TEST_CASE("test LZespolona Roznica"){
    LZespolona x, y, z;

    x.re = 4;
    x.im = 4;

    y.re = 7;
    y.im = -3;

    z.re = -3;
    z.im = 7;
    
    CHECK(x-y == z);
}


TEST_CASE("test LZespolona Iloczyn"){
    LZespolona x, y, z;

    x.re = 1.5;
    x.im = 3;

    y.re = 5;
    y.im = -2.5;

    z.re = 15;
    z.im = 11.25;
    
    CHECK(x*y == z);
}


TEST_CASE("test LZespolona Iloraz liczb zespolonych"){
    LZespolona x, y, z;

    x.re = -4;
    x.im = 8;

    y.re = 2;
    y.im = -1;

    z.re = -3.2;
    z.im = 2.4;
    
    CHECK(x/y == z);
}


TEST_CASE("test LZespolona Iloraz liczb zespolonych - dzielenie przez zero"){
    LZespolona x, y;

    x.re = 1;
    x.im = 2;

    y.re = 0;
    y.im = 0;
    
    WARN_THROWS(x/y);
}