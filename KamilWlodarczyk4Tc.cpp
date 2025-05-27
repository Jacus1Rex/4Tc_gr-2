#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class IntArray {
private:
    vector<int> tablica;
    int liczbaElementow;

public:
    /**********************************************
    nazwa metody: IntArray (konstruktor)
    opis metody: Tworzy tablicę o zadanym rozmiarze i wypełnia ją losowymi liczbami z zakresu 1–1000
    parametry: rozmiar – liczba elementów do utworzenia w tablicy
    zwracany typ i opis: brak
    autor: Kamil Włodarczyk
    **********************************************/
    IntArray(int rozmiar) {
        liczbaElementow = rozmiar;
        srand(time(nullptr));
        for (int i = 0; i < liczbaElementow; ++i) {
            tablica.push_back(rand() % 1000 + 1);
        }
    }

    /**********************************************
    nazwa metody: wyswietl
    opis metody: Wyświetla wszystkie elementy tablicy wraz z ich indeksami
    parametry: brak
    zwracany typ i opis: brak
    autor: Kamil Włodarczyk 
    **********************************************/
    void wyswietl() {
        for (int i = 0; i < liczbaElementow; ++i) {
            cout << i << ": " << tablica[i] << endl;
        }
    }

    /**********************************************
    nazwa metody: znajdz
    opis metody: Wyszukuje pierwsze wystąpienie podanej wartości w tablicy
    parametry: wartosc – liczba całkowita do wyszukania w tablicy
    zwracany typ i opis: int – indeks pierwszego wystąpienia wartości lub -1, jeśli nie znaleziono
    autor: Kamil Włodarczyk
    **********************************************/
    int znajdz(int wartosc) {
        for (int i = 0; i < liczbaElementow; ++i) {
            if (tablica[i] == wartosc)
                return i;
        }
        return -1;
    }

    /**********************************************
    nazwa metody: wyswietlNieparzyste
    opis metody: Wyświetla wszystkie liczby nieparzyste znajdujące się w tablicy i ich liczbę
    parametry: brak
    zwracany typ i opis: brak
    autor: Kamil Włodarczyk
    **********************************************/
    void wyswietlNieparzyste() {
        int licznik = 0;
        for (int i = 0; i < liczbaElementow; ++i) {
            if (tablica[i] % 2 != 0) {
                cout << tablica[i] << endl;
                licznik++;
            }
        }
        cout << "Razem nieparzystych: " << licznik << endl;
    }

    /**********************************************
    nazwa metody: obliczSrednia
    opis metody: Oblicza średnią arytmetyczną wszystkich elementów w tablicy
    parametry: brak
    zwracany typ i opis: double – zwraca średnią wartość wszystkich elementów tablicy
    autor: Kamil Włodarczyk
    **********************************************/
    double obliczSrednia() {
        int suma = 0;
        for (int i = 0; i < liczbaElementow; ++i) {
            suma += tablica[i];
        }
        return static_cast<double>(suma) / liczbaElementow;
    }
};

// --- Funkcje główne ---

int main() {
    IntArray tablica(30); // > 20 elementów

    cout << "Wszystkie elementy tablicy:" << endl;
    tablica.wyswietl();

    int szukana;
    cout << "\nPodaj liczbe do wyszukania: ";
    cin >> szukana;

    int index = tablica.znajdz(szukana);
    if (index != -1)
        cout << "Znaleziono " << szukana << " na indeksie: " << index << endl;

    cout << "\nLiczby nieparzyste:" << endl;
    tablica.wyswietlNieparzyste();

    double srednia = tablica.obliczSrednia();
    cout << "Srednia wszystkich elementow: " << srednia << endl;

    return 0;
}