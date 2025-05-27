#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Tablica
{
private:
    int *tablica;
    int liczbaElementow;

public:
    //**********************************************
    // nazwa metody: Tablica (konstruktor)
    // opis metody: Tworzy tablicę i wypełnia ją losowymi liczbami od 1 do 1000
    // parametry: size – liczba elementów tablicy
    // zwracany typ i opis: brak
    // autor: Stanislav Mamrenko
    //***********************************************
    Tablica(int size)
    {
        liczbaElementow = size;
        tablica = new int[liczbaElementow];
        srand(time(0));
        for (int i = 0; i < liczbaElementow; i++)
        {
            tablica[i] = rand() % 1000 + 1;
        }
    }

    //**********************************************
    // nazwa metody: wyswietlTablice
    // opis metody: Wyświetla wszystkie elementy tablicy z ich indeksami
    // parametry: brak
    // zwracany typ i opis: brak
    // autor: Stanislav Mamrenko
    //***********************************************
    void wyswietlTablice()
    {
        for (int i = 0; i < liczbaElementow; i++)
        {
            cout << i << ": " << tablica[i] << endl;
        }
    }

    //**********************************************
    // nazwa metody: znajdzPierwszy
    // opis metody: Zwraca indeks pierwszego wystąpienia wartości
    // parametry: value – wartość do wyszukania
    // zwracany typ i opis: int – indeks lub -1 jeśli nie znaleziono
    // autor: Stanislav Mamrenko
    //***********************************************
    int znajdzPierwszy(int value)
    {
        for (int i = 0; i < liczbaElementow; i++)
        {
            if (tablica[i] == value)
            {
                return i;
            }
        }
        return -1;
    }

    //**********************************************
    // nazwa metody: wypiszNieparzyste
    // opis metody: Wypisuje wszystkie liczby nieparzyste z tablicy
    // parametry: brak
    // zwracany typ i opis: int – liczba elementów nieparzystych
    // autor: Stanislav Mamrenko
    //***********************************************
    int wypiszNieparzyste()
    {
        int licznik = 0;
        cout << "Nieparzyste liczby:" << endl;
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

    //**********************************************
    // nazwa metody: obliczSrednia
    // opis metody: Oblicza średnią arytmetyczną wszystkich wartości w tablicy
    // parametry: brak
    // zwracany typ i opis: double – wartość średniej arytmetycznej
    // autor: Stanislav Mamrenko
    //***********************************************
    double obliczSrednia()
    {
        int suma = 0;
        for (int i = 0; i < liczbaElementow; i++)
        {
            suma += tablica[i];
        }
        return static_cast<double>(suma) / liczbaElementow;
    }

    ~Tablica()
    {
        delete[] tablica;
    }
};

int main()
{
    int szukanaWartosc;
    int dlugoscTablicy;
    cout << "Podaj dlugosc tablicy: ";
    cin >> dlugoscTablicy;
    if (dlugoscTablicy <= 0)
    {
        cout << "Dlugosc tablicy musi byc wieksza od 0." << endl;
        return 1;
    }

    Tablica mojaTablica(dlugoscTablicy);

    cout << "Zawartosc tablicy:" << endl;
    mojaTablica.wyswietlTablice();

    cout << "\nPodaj wartosc do wyszukania: ";
    cin >> szukanaWartosc;
    int indeks = mojaTablica.znajdzPierwszy(szukanaWartosc);
    if (indeks != -1)
    {
        cout << "Wartosc " << szukanaWartosc << " znaleziona na indeksie: " << indeks << endl;
    }

    int ileNieparzystych = mojaTablica.wypiszNieparzyste();
    cout << "Liczba nieparzystych elementow: " << ileNieparzystych << endl;

    double srednia = mojaTablica.obliczSrednia();
    cout << "Srednia arytmetyczna elementow tablicy: " << srednia << endl;

    return 0;
}