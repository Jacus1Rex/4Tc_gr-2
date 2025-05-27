#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int rozmiar;

class Liczby {
private:
    int liczbaElementow;
    int *tablicaLiczb; //tablica dynamiczna

public:
    Liczby(int n) { //n to jest rozmiar ktory jest na dole w mainie
        liczbaElementow = n;
        tablicaLiczb = new int[liczbaElementow];

        for (int i = 0; i < liczbaElementow; i++) {
            tablicaLiczb[i] = rand() % 1000 + 1;
        }
    }

    /***********************************************
        nazwa metody : wyswietl
        opis metody : metoda wyswietla elementy tablicy
        parametry : brak

        zwracany typ i opis : brak
        autor : julia mleczko
        ************************************************/

    void wyswietl() {
        for (int i = 0; i < liczbaElementow; i++) {
            cout << i << ": " << tablicaLiczb[i] << endl;
        }
    }

    /***********************************************
        nazwa metody : find
        opis metody : metoda zwraca index poszukiwanego elementu
        parametry : szukana, liczba ktorej index jest szukany

        zwracany typ i opis : int, index szukanej liczby lub -1
        autor : julia mleczko
        ************************************************/

    int find(int szukana) {
        for (int i = 0; i < liczbaElementow; i++) {
            if (tablicaLiczb[i] == szukana) {
                return i;
            }
        }

        return -1;
    }

    /***********************************************
        nazwa metody : wyswietlNieparzyste
        opis metody : metoda wyswietla liczby nieparzyste i zwraca ich ilosc
        parametry : brak

        zwracany typ i opis : int, zwraca ilosc liczb nieparzystych
        autor : julia mleczko
        ************************************************/

    int wyswietlNieparzyste() {
        int a = 0;
        cout << "Liczby nieparzyste:\n";
        for (int i = 0; i < liczbaElementow; i++) {
            if (tablicaLiczb[i] % 2 != 0) {
                cout << tablicaLiczb[i] << endl;
                a++;
            }
        }
        return a;
    }

    /***********************************************
        nazwa metody : srednia
        opis metody : metoda oblicza srednia arytmetyczna liczb wygenerowanych
        parametry : brak

        zwracany typ i opis : double, zwraca srednia
        autor : julia mleczko
        ************************************************/

    double srednia() {
        int s = 0;
        double k = 0;
        for (int i = 0; i < liczbaElementow; i++) {
            s += tablicaLiczb[i];
        }

        k = s / liczbaElementow;
        return k;
    }
};


int main()
{
    srand(time(NULL));

    cout << "Podaj rozmiar tablicy wiekszy od 20.\n";
    cin >> rozmiar;

    if(rozmiar>20){
        Liczby liczby{ rozmiar };
        liczby.wyswietl();
        int index = liczby.find(69);
        if (index != -1) {
            cout << "\nZnaleziono element na indeksie: " << index;
        }
        int b = liczby.wyswietlNieparzyste();
        cout << "Liczba liczb nieparzystych: " << b << endl;
        int c = liczby.srednia();
        cout << "Srednia wszystkich elementow: " << c;
    }
    else {
        cout << "Uruchom program ponownie i podaj liczbe wieksza od 20.";
    }

}