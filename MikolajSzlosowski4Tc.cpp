#include <iostream>
#include <random>
#include <ctime>
using namespace std;

class Liczbunie {
    private:
        int length;
        int *tab;

    public:
        Liczbunie(int len){
            length = len;
            tab = new int[len];

            for (int i = 0; i < length; i++)
            {
                tab[i] = rand() % 1000 + 1;
            }
        }

        // **********************************************
        // nazwa metody: displayAll
        // opis metody: Wyświetla wszystkie elementy zainicjalizowanej tablicy
        // parametry: brak
        // zwracany typ i opis: brak
        // autor: Mikolaj
        // ***********************************************
        void displayAll(){
            for (int i = 0; i < length; i++)
            {
                cout<<i<<": "<<tab[i]<<endl;
            }
        }

        // **********************************************
        // nazwa metody: find
        // opis metody: Zwraca indeks szukanego elementu
        // parametry: num - Wyszukiwana liczba calkowita

        // zwracany typ i opis: int - indeks elemntu lub -1 gdy nie odnaleziono
        // autor: Mikolaj
        // ***********************************************
        int find(int num){
            for (int i = 0; i < length; i++)
            {
                if (tab[i]==num) {
                    return i;
                }
            }
            return -1;
        }

        // **********************************************
        // nazwa metody: odd
        // opis metody: Wypisuje i zwraca ilosc nieparzystych elementow
        // parametry: brak
        // zwracany typ i opis: int - ilosc nieparzystych elementow
        // autor: Mikolaj
        // ***********************************************
        int odd(){
            cout<<"Nieparzyste: "<<endl;
            int sum = 0;
            for (int i = 0; i < length; i++)
            {
                if (tab[i]%2==1) {
                    sum++;
                    cout<<tab[i]<<endl;
                }
            }
            return sum;
        }

        // **********************************************
        // nazwa metody: avg
        // opis metody: Zwraca srednia arytmetyczna elementow
        // parametry: brak
        // zwracany typ i opis: double - srednia arytmetyczna elementow
        // autor: Mikolaj
        // ***********************************************
        double avg(){
            int sum = 0;
            for (int i = 0; i < length; i++)
            {
                sum += tab[i];
            }
            
            return static_cast<double>(sum/length);
        }
        
};

int main(){
    srand(time(0));
    Liczbunie l {21};
    l.displayAll();

    int index = l.find(100);
    if (index != -1){
        cout<<"Znaleziono 100 na "<<index<<" indeksie"<<endl;
    }
    
    cout<<l.odd()<<" liczb nieparzystych"<<endl;
    
    cout<<"Srednia: "<<l.avg()<<endl;
    return 0;
}