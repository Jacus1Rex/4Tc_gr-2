#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class Tablica {
private:
    int* tablica;
    int rozmiar;

public:
    // Konstruktor – ustawia rozmiar tablicy i wypełnia losowymi liczbami z zakresu 1-1000
    Tablica(int r) {
        rozmiar = r;
        tablica = new int[rozmiar];
        srand(time(NULL));
        for (int i = 0; i < rozmiar; i++) {
            tablica[i] = rand() % 1000 + 1;
        }
    }

    // Destruktor
    ~Tablica() {
        delete[] tablica;
    }

    // Wyświetlanie wszystkich elementów tablicy
    // nazwa metody: wyswietl
// opis metody: Wyświetla wszystkie elementy tablicy
// parametry: brak
// zwracany typ i opis: void – metoda nic nie zwraca
    void wyswietl() {
        cout << "Zawartosc tablicy:" << endl;
        for (int i = 0; i < rozmiar; i++) {
            cout << tablica[i] << " ";
        }
        cout << endl;
    }

    // Wyszukiwanie pierwszego wystąpienia wartości
    // nazwa metody: wyszukaj
// opis metody: Wyszukuje pierwsze wystąpienie podanej wartości w tablicy
// parametry: int wartosc – wartość do wyszukania
// zwracany typ i opis: int – indeks znalezionej wartości lub -1 jeśli nie znaleziono

    int wyszukaj(int wartosc) {
        for (int i = 0; i < rozmiar; i++) {
            if (tablica[i] == wartosc) {
                return i; // Zwracamy indeks
            }
        }
        return -1; // Nie znaleziono
    }

    // Obliczanie sumy wartości w tablicy
    // nazwa metody: suma
// opis metody: Zwraca sumę wszystkich elementów tablicy
// parametry: brak
// zwracany typ i opis: int – suma wartości w tablicy

    int suma() {
        int suma = 0;
        for (int i = 0; i < rozmiar; i++) {
            suma += tablica[i];
        }
        return suma;
    }

    // Liczenie elementów większych od wartości
    // nazwa metody: liczWieksze
// opis metody: Liczy elementy tablicy większe od zadanej wartości
// parametry: int wartosc – wartość progowa
// zwracany typ i opis: int – liczba elementów większych od wartosci
    int liczWieksze(int wartosc) {
        int licznik = 0;
        for (int i = 0; i < rozmiar; i++) {
            if (tablica[i] > wartosc) {
                licznik++;
            }
        }
        return licznik;
    }

    // Liczenie elementów w zakresie <a, b>
    // nazwa metody: liczWZakresie
// opis metody: Liczy elementy znajdujące się w podanym zakresie <a, b>
// parametry: int a, int b – zakres wartości
// zwracany typ i opis: int – liczba elementów w zakresie
    int liczWZakresie(int a, int b) {
        int licznik = 0;
        for (int i = 0; i < rozmiar; i++) {
            if (tablica[i] >= a && tablica[i] <= b) {
                licznik++;
            }
        }
        return licznik;
    }

    // Zwraca rozmiar tablicy
    int getRozmiar() {
        return rozmiar;
    }

    // Zwraca wartość danego elementu
    int getElement(int i) {
        if (i >= 0 && i < rozmiar)
            return tablica[i];
        return -1;
    }
};

int main() {
    int rozmiar, szukana;
    cout << "Podaj rozmiar tablicy: ";
    cin >> rozmiar;

    Tablica t(rozmiar);

    t.wyswietl();

    cout << "\nPodaj wartosc do wyszukania: ";
    cin >> szukana;

    int indeks = t.wyszukaj(szukana);
    if (indeks != -1)
        cout << "Wartosc " << szukana << " znaleziona na indeksie: " << indeks << endl;
    else
        cout << "Nie znaleziono wartosci " << szukana << endl;

    cout << "Suma wszystkich elementow: " << t.suma() << endl;

    int prog;
    cout << "Podaj wartosc progowa: ";
    cin >> prog;
    cout << "Liczba elementow wiekszych od " << prog << ": " << t.liczWieksze(prog) << endl;

    int a, b;
    cout << "Podaj zakres a i b: ";
    cin >> a >> b;
    cout << "Liczba elementow w zakresie <" << a << ", " << b << ">: " << t.liczWZakresie(a, b) << endl;

    return 0;
}
