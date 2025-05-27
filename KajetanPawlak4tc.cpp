#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class TablicaOperacje
{
private:
    int *tablica;
    int liczbaElementow;

public:
    /**********************************************
    nazwa metody: TablicaOperacje (konstruktor)
    opis metody: Tworzy tablicę o zadanym rozmiarze i wypełnia ją losowymi liczbami z zakresu 1–1000
    parametry: rozmiar – liczba elementów do utworzenia w tablicy
    zwracany typ i opis: brak
    autor: Kajetan Pawlak
    **********************************************/
    TablicaOperacje(int rozmiar)
    {
        liczbaElementow = rozmiar;
        tablica = new int[liczbaElementow];
        srand(time(nullptr));
        for (int i = 0; i < liczbaElementow; i++)
        {
            tablica[i] = rand() % 1000 + 1;
        }
    }

    /**********************************************
    nazwa metody: ~TablicaOperacje (destruktor)
    opis metody: Zwalnia pamięć zajmowaną przez tablicę
    parametry: brak
    zwracany typ i opis: brak
    autor: Kajetan Pawlak
    **********************************************/
    ~TablicaOperacje()
    {
        delete[] tablica;
    }

    /**********************************************
    nazwa metody: wyswietlTablice
    opis metody: Wyświetla wszystkie elementy tablicy wraz z ich indeksami
    parametry: brak
    zwracany typ i opis: brak
    autor: Kajetan Pawlak
    **********************************************/
    void wyswietlTablice()
    {
        cout << "Elementy tablicy:" << endl;
        for (int i = 0; i < liczbaElementow; i++)
        {
            cout << i << ": " << tablica[i] << endl;
        }
    }

    /**********************************************
    nazwa metody: wyszukajWartosc
    opis metody: Wyszukuje pierwsze wystąpienie podanej wartości w tablicy
    parametry: szukanaWartosc – liczba całkowita do wyszukania w tablicy
    zwracany typ i opis: int – indeks pierwszego wystąpienia wartości lub -1, jeśli nie znaleziono
    autor: Kajetan Pawlak
    **********************************************/
    int wyszukajWartosc(int szukanaWartosc)
    {
        for (int i = 0; i < liczbaElementow; i++)
        {
            if (tablica[i] == szukanaWartosc)
                return i;
        }
        return -1;
    }

    /**********************************************
    nazwa metody: wyswietlNieparzyste
    opis metody: Wyświetla wszystkie liczby nieparzyste znajdujące się w tablicy i zwraca ich liczbę
    parametry: brak
    zwracany typ i opis: int – liczba elementów nieparzystych w tablicy
    autor: Kajetan Pawlak
    **********************************************/
    int wyswietlNieparzyste()
    {
        cout << "Wartości nieparzyste w tablicy:" << endl;
        int licznik = 0;
        for (int i = 0; i < liczbaElementow; i++)
        {
            if (tablica[i] % 2 != 0)
            {
                cout << tablica[i] << " ";
                licznik++;
            }
        }
        cout << endl;
        return licznik;
    }

    /**********************************************
    nazwa metody: obliczSrednia
    opis metody: Oblicza średnią arytmetyczną wszystkich elementów w tablicy
    parametry: brak
    zwracany typ i opis: double – średnia wartość wszystkich elementów tablicy
    autor: Kajetan Pawlak
    **********************************************/
    double obliczSrednia()
    {
        if (liczbaElementow == 0)
            return 0.0;

        long suma = 0;
        for (int i = 0; i < liczbaElementow; i++)
        {
            suma += tablica[i];
        }
        return static_cast<double>(suma) / liczbaElementow;
    }
};

int main()
{
    cout << "=== APLIKACJA OPERACJI NA TABLICACH ===" << endl
         << endl;

    const int rozmiarTablicy = 25;
    TablicaOperacje obiektTablicy(rozmiarTablicy);

    cout << "1. Wyświetlanie wszystkich elementów tablicy:" << endl;
    obiektTablicy.wyswietlTablice();
    cout << endl;

    cout << "2. Wyszukiwanie wartości:" << endl;
    int szukanaWartosc = 500;
    cout << "Szukam wartości: " << szukanaWartosc << endl;

    int indeksZnalezionej = obiektTablicy.wyszukajWartosc(szukanaWartosc);
    if (indeksZnalezionej != -1)
    {
        cout << "Wartość " << szukanaWartosc << " znaleziona na indeksie: " << indeksZnalezionej << endl;
    }
    cout << endl;

    cout << "3. Liczby nieparzyste:" << endl;
    int iloscNieparzystych = obiektTablicy.wyswietlNieparzyste();
    cout << "Ilość liczb nieparzystych: " << iloscNieparzystych << endl
         << endl;

    cout << "4. Średnia arytmetyczna:" << endl;
    double srednia = obiektTablicy.obliczSrednia();
    cout << fixed << setprecision(2);
    cout << "Średnia arytmetyczna wartości w tablicy: " << srednia << endl;

    cout << endl
         << "=== KONIEC PROGRAMU ===" << endl;

    return 0;
}