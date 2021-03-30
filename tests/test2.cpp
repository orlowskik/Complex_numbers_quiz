#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include <sstream>

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

    std::ostringstream out;

    out << x;
    std::cout << out.str() << std::endl;
    CHECK( out.str() == "(2.00+2.00i)" );
}


TEST_CASE("LZespolona - wyswietlanie zaokraglane") {
    LZespolona x;
   
    x.re = 2.0/3.0;
    x.im = 2.0/3.0;
    
    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(0.67+0.67i)" == out.str() );
}


TEST_CASE("LZespolona - wyswietlanie male liczby") {
    LZespolona x;
   
    x.re = 0.0001;
    x.im = -0.000001;
    
    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(0.00010-0.0000010i)" == out.str() );
}




TEST_CASE("LZespolona - wczytywanie standard 1") {
    LZespolona x;
    
    std::istringstream in("(10+10.10i)");
    in >> x;
    std::ostringstream out;
    out << x; 
    
    CHECK( "(10.00+10.10i)" == out.str() );
}


TEST_CASE("LZespolona - wczytywanie standard 2") {
    LZespolona x;
    
    std::istringstream in("(10.10-10i)");
    in >> x;
    std::ostringstream out;
    out << x; 
    
    CHECK( "(10.10-10.00i)" == out.str() );
}

TEST_CASE("LZespolona - wczytywanie standard 3" ) {
    LZespolona x;
    
    std::istringstream in("(-10.10-10i)");
    in >> x;
    std::ostringstream out;
    out << x; 
    
    CHECK( "(-10.10-10.00i)" == out.str() );
}


TEST_CASE("LZespolona - wczytywanie skroconej notacji 1") {
    LZespolona x;
    
    std::istringstream in("(10-i)");
    in >> x;
    std::ostringstream out;
    out << x; 
    
    CHECK( "(10.00-1.00i)" == out.str() );
}

TEST_CASE("LZespolona - wczytywanie skroconej notacji 2") {
    LZespolona x;
    
    std::istringstream in("(-i)");
    in >> x;
    std::ostringstream out;
    out << x; 
    
    CHECK( "(0.00-1.00i)" == out.str() );
}

TEST_CASE("LZespolona - wczytywanie skroconej notacji 3") {
    LZespolona x;
    
    std::istringstream in("(i)");
    in >> x;
    std::ostringstream out;
    out << x; 
    
    CHECK( "(0.00+1.00i)" == out.str() );
}

TEST_CASE("LZespolona - wczytywanie skroconej notacji 4" ) {
    LZespolona x;
    
    std::istringstream in("(10)");
    in >> x;
    std::ostringstream out;
    out << x; 
    
    CHECK( "(10.00+0.00i)" == out.str() );
}

TEST_CASE("LZespolona - wczytywanie skroconej notacji 5") {
    LZespolona x;
    
    std::istringstream in("(10i)");
    in >> x;
    std::ostringstream out;
    out << x; 
    
    CHECK( "(0.00+10.00i)" == out.str() );
}

TEST_CASE("LZespolona - wczytywanie skroconej notacji 6") {
    LZespolona x;
    
    std::istringstream in("(-10i)");
    in >> x;
    std::ostringstream out;
    out << x; 
    
    CHECK( "(0.00-10.00i)" == out.str() );
}


TEST_CASE("Test sprzezenia niezerowego") {
    LZespolona x,y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = -2;

    x.sprz();
 
   CHECK( x == y );
}

TEST_CASE("Test sprzezenia zerowego") {
    LZespolona x,y;
    
    x.re = 2;
    x.im = 0;

    y.re = 2;
    y.im = 0;

    x.sprz();
 
   CHECK( x == y );
}


TEST_CASE("Test modulu do kwadratu") {
    LZespolona x;
    double y, w;
    
    x.re = 2;
    x.im = 3;

    y = x.modul();
    w = 13.00;


   CHECK( y == w );
}