# Projekt 2 - Arytmetyka liczb zespolonych

Program domyslnie wyswietla liczby zespolone z dwoma miejscami po przecinku. W przypadku bardzo malych liczb
automatycznie dostosowuje ilosc cyfr po przecinku do dwoch liczb znaczacych (t.j pierwsza liczba niezerowa i nastepna).
Jednoczesne operacje na liczbach bardzo duzych i bardzo malych sa niezalecane, poniewaz beda brane pod uwage tylko czesci setne.

Porownywanie liczb typu double jest oparte na wyznaczaniu minimalnej roznicy pomiedzy nimi. Roznica ta jest automatycznie wyliczana
dla czesci rzeczywistej i czesci urojonej z osobna. Maksymalna roznica wynosi 0.01 i jest to wartosc domyslna. W przypadku
porownywania liczb mniejszych od danej roznicy ( wartosc bezwzgledna ) roznica jest zmniejszana dziesieciokrotnie az bedzie
mniejsza od liczby zadanej. Zawsze dopuszczalny blad w przypadku liczb ulamkowych (mniejszych od 1 ) bedzie wynosil jedna
pozycje drugiej liczby znaczacej. Dzieki temu operacje na krancach i granicach wykonuja sie prawidlowo.

# Czytanie z pliku

Program posiada dwa tryby pracy - czytania z bazy w pliku objektowym i czytania wyrazen z pliku tekstowego. Wybory trybow
dokonuje sie poprzez podanie odpowiednich nazw w parametrach wywolania programu.

# Wczytywanie liczb zespolonych

Mozliwe jest wykorzystywanie domyslnej oraz skroconej formy zapisu liczb zespolonych. W plikach tekstowych znajduja sie 
przykladowe realizacje wczytywania oraz pomijania bledow. W pliku trudne.dat znajduje sie skrocona forma zapisu.
Ze skroconego zapisu mozna kozrystac zarowno w plikach jak i korzystajac ze standardowego wejscia jako uzytkownik.

# Informacje dodatkowe
Statystyka znajduje sie w odrebnym module. Testy doctest zostaly dostosowane do charakterystyki programu. Operacje
wczytywania liczb zostaly zrealizowane na metodach strumienia i przeciazeniach operatorow. Do wykluczenia operacji
zabronionych matematycznie zostala wprowadzona obsluga wyjatkow.




