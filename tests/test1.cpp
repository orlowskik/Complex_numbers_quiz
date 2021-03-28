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

TEST_CASE("test LZespolona Suma dla zer(int)"){
    LZespolona x, y, z;

    x.re = 0;
    x.im = 0;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;
    
    CHECK(x+y == z);
}


TEST_CASE("test LZespolona Suma dla zer(double)"){
    LZespolona x, y, z;

    x.re = 0.0;
    x.im = 0.0;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 0.0;
    z.im = 0.0;
    
    CHECK(x+y == z);
}



TEST_CASE("test LZespolona Suma dla zakresu 0.00001"){
    LZespolona x, y, z;

    x.re = 0.00001;
    x.im = 0.00001;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0.00002;
    z.im = 0.00002;
    
    CHECK(x+y == z);
}


TEST_CASE("test LZespolona Suma dla zakresu 0.0001 ( sprawdzanie bledu )"){
    LZespolona x, y, z;

    x.re = 0.00001;
    x.im = 0.00001;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0.00003;
    z.im = 0.00003;
    
    CHECK( !(x+y == z));
}


TEST_CASE("test LZespolona Suma na granicach"){
    LZespolona x, y, z;

    x.re = 0.00001;
    x.im = 0.00001;

    y.re = 0.00009;
    y.im = 0.00009;

    z.re = 0.0001;
    z.im = 0.0001;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma na granicach ( bledna) "){
    LZespolona x, y, z;

    x.re = 0.00001;
    x.im = 0.00001;

    y.re = 0.00009;
    y.im = 0.00009;

    z.re = 0.0002;
    z.im = 0.0002;
    
    CHECK( !(x+y == z) );
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

TEST_CASE("test LZespolona Roznica dla zer(int)"){
    LZespolona x, y, z;

    x.re = 0;
    x.im = 0;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;
    
    CHECK(x-y == z);
}


TEST_CASE("test LZespolona Roznica dla zer(double)"){
    LZespolona x, y, z;

    x.re = 0.0;
    x.im = 0.0;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 0.0;
    z.im = 0.0;
    
    CHECK(x-y == z);
}


TEST_CASE("test LZespolona Roznica dla zakresu 0.00001"){
    LZespolona x, y, z;

    x.re = 0.00002;
    x.im = 0.00002;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0.00001;
    z.im = 0.00001;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona Roznica dla zakresu 0.00001 (bledna) "){
    LZespolona x, y, z;

    x.re = 0.00002;
    x.im = 0.00002;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0.00003;
    z.im = 0.00003;
    
    CHECK( !(x-y == z) );
}

TEST_CASE("test LZespolona Roznica na granicy zakresu (bledna) "){
    LZespolona x, y, z;

    x.re = 0.00002;
    x.im = 0.00002;

    y.re = 0.000005;
    y.im = 0.000005;

    z.re = 0.000017;
    z.im = 0.000014;
    
    CHECK( !(x-y == z) );
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

TEST_CASE("Porownywanie bardzo malych liczb"){
    LZespolona x,y;


    x.re = 0.01;
    x.im = 0.02;

    y.re = 0.01;
    y.im = 0.02;

    CHECK( x == y );
}


TEST_CASE("Porownywanie bardzo malych liczb"){
    LZespolona x,y;


    x.re = 0.0001;
    x.im = 0.0002;

    y.re = 0.0001;
    y.im = 0.0002;

    CHECK( x == y );
}


TEST_CASE("Porownywanie bardzo malych liczb"){
    LZespolona x,y;
    

    x.re = 0.000001;
    x.im = 0.000002;

    y.re = 0.000001;
    y.im = 0.000005;

    CHECK( !(x == y) );
}



TEST_CASE("Porownywanie malej roznicy"){
    LZespolona x,y;
    

    x.re = 153.11;
    x.im = 3.00;

    y.re = 153.13;
    y.im = 3.00;

    CHECK( !(x == y) );
}


