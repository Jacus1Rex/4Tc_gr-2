#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class App {
private:
    int* array;   
    int amount;   

public:

    App(int size) {
        amount = size;
        array = new int[amount];
        for (int i = 0; i < amount; ++i) {
            array[i] = rand() % 1000 + 1;
        }
    }

    void Display() {
        for (int i = 0; i < amount; ++i) {
            cout << i << ": " << array[i] << endl;
        }
    }


    int Find(int value) {
        for (int i = 0; i < amount; ++i) {
            if (array[i] == value) {
                return i;
            }
        }
        return -1;
    }


    int NoPair() {
        int count = 0;
        for (int i = 0; i < amount; ++i) {
            if (array[i] % 2 != 0) {
                cout << array[i] << endl;
                ++count;
            }
        }
        return count;
    }


    float AVG() {
        float sum = 0;
        for (int i = 0; i < amount; ++i) {
            sum += array[i];
        }
        return sum / amount;
    }
};


int main() {
    srand(time(NULL));


    App obiekt1(25);


    obiekt1.Display();


    int a;
    cout << "Podaj szukana: ";
    cin >> a;

    int index = obiekt1.Find(a);
    if (index != -1) {
        cout << "\nIndex: " << index << endl;
    }


    cout << "Liczby nieparzyste:" << endl;
    int licznik = obiekt1.NoPair();
    cout << "Liczba nieparzystych: " << licznik << endl;


    float srednia = obiekt1.AVG();
    cout << "Srednia elementow: " << srednia << endl;


}

/**********************************************
nazwa metody : Display
opis metody : Metoda wyświetla wszystkie wartości elementów tablicy wygenerowanej przez program
parametry : BRAK
zwracany BRAK
autor : Tymoteusz Derda
***********************************************
**********************************************
nazwa metody : Find
opis metody : Metoda wyszukuje w tablicy wartości podanej przez użytkownika i wyświetla indeks jej pierwszego wystąpienia.
parametry : int value - wartość całkowita podana przez użykownika z klawiatury
zwracany typ i opis : zwraca typ int, jeśli program znalazł wartość zwraca indeks tego elementu, jeżeli nie to zwraca -1.
***********************************************
**********************************************
nazwa metody : NoPair
opis metody : Metoda wypisuje wszystkie liczby w tablicy które są nieparzyste oraz ich ilość
parametry : BRAK
zwracany typ i opis : zwraca typ int, zwraca ilość liczb nieparzystych
autor : <numer zdającego>
***********************************************
**********************************************
nazwa metody : AVG
opis metody : Zwraca średnią arytmetyczną wszystkich elementów tablicy
parametry : BRAK
zwracany typ i opis : zwraca float, czyli średnią arytmetyczną elementów tablicy.
************************************************/
