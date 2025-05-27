#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Tablica{
    private:
        int* arr;
        int size;

    public:
        /**********************************************
        nazwa metody: Tablica (konstruktor)
        opis metody:  Tworzy tablicę o podanym rozmiarze i wypełnia ją losowymi liczbami od 0 do 1000
        parametry:    size - rozmiar tablicy (liczba elementów)
        zwracany typ i opis:  brak
        autor:        Krzysztof
        **********************************************/
        Tablica(int size){
            srand(time(nullptr));
            this->size = size;
            arr = new int[size]; 
            for(int i = 0; i < size; i++){
                int randomNum = rand() % 1001;
                arr[i] = randomNum;
            }
        }

        /**********************************************
        nazwa metody: ShowElements
        opis metody:  Wyświetla na ekranie wszystkie elementy tablicy wraz z ich indeksami
        parametry:    brak
        zwracany typ i opis:  void - brak zwracanej wartości
        autor:        Krzysztof
        **********************************************/
        void ShowElements(){
            for(int i = 0; i < size; i++){
                cout << i << ": " << arr[i] << endl;
            }
        }

        /**********************************************
        nazwa metody: FindFirstValue
        opis metody:  Znajduje indeks pierwszego wystąpienia podanej wartości w tablicy, zwraca -1 jeśli nie znaleziono
        parametry:    x - wartość do wyszukania w tablicy
        zwracany typ i opis:  int - indeks pierwszego wystąpienia wartości lub -1, jeśli brak
        autor:        Krzysztof
        **********************************************/
        int FindFirstValue(int x){
            for(int i = 0; i < size; i++){
                if(x == arr[i]){
                    return i;
                }
            }
            return -1;
        }

        /**********************************************
        nazwa metody: AllOdd
        opis metody:  Zlicza ile elementów tablicy jest nieparzystych
        parametry:    brak
        zwracany typ i opis:  int - liczba nieparzystych elementów w tablicy
        autor:        Krzysztof
        **********************************************/
        int AllOdd(){
            int count = 0;
            for(int i = 0; i < size; i++){
                if(arr[i] % 2 != 0){
                    count++;
                }
            }
            return count;
        }

        /**********************************************
        nazwa metody: Avg
        opis metody:  Oblicza średnią arytmetyczną wszystkich elementów tablicy
        parametry:    brak
        zwracany typ i opis:  int - średnia arytmetyczna elementów (wynik zaokrąglony w dół)
        autor:        Krzysztof
        **********************************************/
        int Avg(){
            int sum = 0;
            for(int i = 0; i < size; i++){
                sum += arr[i];
            }
            return sum / size;
        }


        ~Tablica() {
            delete[] arr;
        }
};

int main(){
    Tablica arr {20};
    arr.ShowElements();
    cout << endl;
    cout << "Pierwsze wystapienie na indexie: " << arr.FindFirstValue(41);
    cout << endl;
    cout << "Nieparzystych: " << arr.AllOdd();
    cout << endl;
    cout << "srednia wszystkich elementow: " << arr.Avg();

    return 0;
}
