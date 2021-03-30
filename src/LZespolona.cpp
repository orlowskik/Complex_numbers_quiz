#include "LZespolona.hh"
#include <cmath>
#include <iostream>


#define MIN_DIFF 0.1 /* Dopuszczalny blad odpowiedzi */

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */
bool  LZespolona::operator == (LZespolona  Skl2) const{
  double roznica1 = MIN_DIFF , roznica2 = MIN_DIFF;
  

  if(Skl2.re != 0 ){
    while(  fabs( Skl2.re ) < roznica1){   /* Dostosowanie roznicy dla czesci rzeczywistej */
        roznica1 /= 10;
    }
  }

  if(Skl2.im != 0 ){                       /* Dostosowanie roznicy dla czesci urojonej */
    while(  fabs( Skl2.im ) < roznica2 ){
        roznica2 /= 10;
    }
  }
  
  /* Minimalna roznica 0.01 / Ustawienie roznic dal dwoch liczb znaczacych */
  roznica1 /= 10; 
  roznica2 /= 10;


  if( fabs(this->re - Skl2.re) <= roznica1 && fabs(this->im - Skl2.im) <= roznica2 ) /* Porownywanie liczb zespolonych*/
    return true;
  else
    return false;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (LZespolona  Skl2) const{
  Skl2.re += this->re;
  Skl2.im += this->im;

  return Skl2;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator - (LZespolona Skl2) const{
   Skl2.re = this->re - Skl2.re;
   Skl2.im = this->im - Skl2.im;

  return Skl2;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Ilczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator * (LZespolona Skl2) const{
  LZespolona Wynik;

  Wynik.re = this->re * Skl2.re - this->im * Skl2.im;
  Wynik.im = this->re * Skl2.im + this->im * Skl2.re;
  return Wynik;
}


/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia ( Modul rozny od 0).
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator / (LZespolona Skl2) const{
  LZespolona Wynik;
  double modul;

  Wynik.re = 0;
  Wynik.im = 0;
  modul = Skl2.modul();

  if( !modul )
    throw " Nie dziel przez 0";

  Skl2.sprz();

  return Wynik = (*this * Skl2) / modul;
}



/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator / (double  Skl2) const{
  LZespolona  Wynik;
  Wynik.re = 0;
  Wynik.im = 0;



  if(Skl2){
    Wynik.re = this->re / Skl2;
    Wynik.im = this->im / Skl2;
  }
  else
    throw "Nie dziel przez 0";

  return Wynik;
}



/*!
 *  Realizuje modul z liczby zespolonej
 *  Argumenty:
 *    Skl1 - Liczba zespolona.
 *  Zwraca:
 *    Liczba nieujemna calkowita ( modul z liczby ). 
 */
double  LZespolona::modul (){
  return fabs(pow(this->re,2) + pow(this->im,2));
}




/*!
 *  Realizuje sprzezenie liczby zespolonej ( zmiana znaku czesci urojonej)
 *  Argumenty:
 *    Skl1 - Liczba zespolona sprzegana.
 *  Zwraca:
 *    Wynik - Liczba po sprzezeniu.
 */
void LZespolona::sprz(){

  this->im = this->im * (-1) ;
}

/*!
 *  Wyswietla liczbe zespolona na podanym wyjsciu.
 *  Argumenty:
 *    StrWyj - Strumien wyjsciowy, na ktory ma zostac wyswietlona liczba,
 *    Skl1 - Liczba zespolona sprzegana.
 *  Zwraca:
 *    StrWyj - Strumien wyjsciowy, na ktory wypisano liczbe.
 */
std::ostream&  operator << (std::ostream &StrWyj, const LZespolona &Skl1){
  int n1 = 0, n2 = 0; /* Parametry okreslajace ilosc miejsc po przecinku */

  /* Dla liczb mniejszych od 1 ustawienie ilosci miejsc po przecinku na dwie cyfry znaczace */
  if(Skl1.re !=0 ){
    while(  fabs(Skl1.re) < pow(10,- n1) ){ /* Ustawienia dla czesci rzeczywistej */
      n1++;                                 
    }
    if(fabs(Skl1.re) < 1)
      n1++;
  }

  if(Skl1.im !=0 ){
    while(  fabs(Skl1.im) < pow(10,- n2) ){ /* Ustawienia dla czesci urojonej */
      n2++;
    }
    if(fabs(Skl1.im) < 1)
      n2++;
  }
  /* W przypadku liczb wiekszych od 1 ustawia ilosc miejsc po przecinku na 2 */
  if(!n1) 
    n1 = 2;
  if(!n2)
    n2 = 2;

  StrWyj.precision(n1);     /* Precyzja pierwszej liczby */
  StrWyj << std::noshowpos << '(' << std::fixed << Skl1.re ;
  StrWyj.precision(n2);     /* Precyzja drugiej liczby */
  StrWyj << std::showpos << Skl1.im << "i)" << std::noshowpos ;
  return StrWyj;

}

/*!
 *  Funkcja pomocnicza do wczytywania liczby zespolonej. Sprawdza wprowadzany znak.
 *  Argumenty:
 *    StrWej - Strumien wejsciowy, z ktorego czytany jest znak
 *    Znak - znak, ktorego oczekujemy.
 *  Wynik:
 *     Ustawia flage niepowodzenia na strumieniu jezeli wczytany znak jest inny niz oczekiwany.
 */
void CzytajZnak(std::istream &StrWej, const char Znak){
  char CzytanyZnak = ' ';
  StrWej >> CzytanyZnak;

  if (CzytanyZnak != Znak)
    StrWej.setstate(std::ios::failbit);
  
}


/*!
 *  Wczytuje liczbe zespolona z podanego strumienia.
 *  Argumenty:
 *    StrWej - Strumien wejsciowy, z ktorego czytana jest liczba
 *    Skl1 - Liczba zespolona, do ktorej wpisujemy wartosci.
 *  Zwraca:
 *    StrWej - Strumien wejsciowy, z ktorego czytano liczbe.
 */
std::istream& operator >> (std::istream &StrWej, LZespolona &Skl){
  double x,y;           /* Lioczby mozliwe do wczytania*/
  char znak1, znak2;    /* Zmienne sluzace do przechowania znaku liczby */

  CzytajZnak(StrWej,'('); /* Sprawdzenie, czy wpisana liczba zaczyna sie od nawiasu */
  if(StrWej.fail())
    return StrWej;

  StrWej >> znak1;  /* Wczytanie znaku znajdujacego sie po nawiasie */
                      
  switch(znak1){
    case 'i' :
      CzytajZnak(StrWej,')'); /* Rozpatrzenie sytuacji podania samego i w nawiasach */
      if(StrWej.good()){
        Skl.re = 0;
        Skl.im = 1;
      }
      return StrWej;
    case '-' :                   /* Rozpatrzenie sytuacji pojawienia sie znaku '-' */
      StrWej >> znak2;        /* Sprawdzenie znaku znajdujacego sie po '-' */
      if(znak2 == 'i'){         
        CzytajZnak(StrWej,')');
        if(StrWej.good()){      /* Gdy podano znak '-i' */
           Skl.re = 0;
           Skl.im = -1;
         }
         return StrWej;
       }
       StrWej.putback(znak2);   /* Jezeli podano inny znak po '-' odkladamy pobrane znaki w celu czytania liczby */
       StrWej.putback(znak1);
       break;

     default :
       StrWej.putback(znak1); /* Domyslnie czytamy cala liczbe */
       break;
  }

  StrWej >> x;        /* Wczytanie pierwszej liczby*/
  if(StrWej.good()){  /* Rozpatrujemy tylko mozliwosci sukcesu czytania, inne warianty zostaly juz sprawdzone*/
    StrWej >> znak1 ;
    switch(znak1){    /* Ponowanie sprawdzamy znak po liczbie w celu rozpatrzenia szczegolnych przypadkow */

        case '-' :
          StrWej >> znak2;
          if(znak2 == 'i'){           /* Przypadek podania liczby -1 jako czesci urojonej*/
            CzytajZnak(StrWej,')');
            if(StrWej.good()){
              Skl.re = x;
              Skl.im = -1;
            }
          return StrWej;
          }
          StrWej.putback(znak2);    /* W przypadku znaku innego niz 'i' odkladamy znaki aby czytac cala liczbe */
          StrWej.putback(znak1);
          break;
        case '+' :
          StrWej >> znak2 ;        /* Przypadek podania liczby +1 jako czesci urojonej */
          if(znak2 == 'i'){
            CzytajZnak(StrWej,')');
            if(StrWej.good()){
              Skl.re = x;
              Skl.im = 1;
            }
          return StrWej;
          }
          StrWej.putback(znak2);  /* W przypadku znaku innego niz 'i' odkladamy znaki aby czytac cala liczbe */
          StrWej.putback(znak1);
          break;
        default :
          StrWej.putback(znak1);  /* Domyslnie realizujemy czytanie calej liczby */
          break;
    }

    StrWej >> y;        /* Wczytanie drugiej liczby */
    if(StrWej.fail()){  /* Rozpatrywanie szczegolnych przypadkow, gdy wczytano tylko 1 liczbe*/
      StrWej.clear();
      StrWej >> znak1 ;
      if(znak1 != 'i' && znak1 != ')'){     /* Sprawdzenie znaku w celu wykluczenia nieprawidlowych konfiguracji */
        StrWej.setstate(std::ios::failbit);
        return StrWej;
      }
      else{
        if(znak1 == 'i' ){          /* Przypadek podania pierwszej liczby jako czesci urojonej (czesc rzeczywista rowna 0 )*/
          CzytajZnak(StrWej,')');
          if(StrWej.good()){
            Skl.re = 0;
            Skl.im = x;
          }
          return StrWej;
        }
        else if(znak1 == ')'){    /* Przypadek podania pierwszej liczby jako czesci rzeczywistej (czesc urojona rowna 0) */
          Skl.re = x;
          Skl.im = 0;
          return StrWej;
        }
      }
    }
    CzytajZnak(StrWej,'i');   /* Przypadek podania liczby w domyslnej konfiguracji */
    CzytajZnak(StrWej,')');
    if(StrWej.good()){
      Skl.re = x;
      Skl.im = y;
    }
  }

  return StrWej;
}


