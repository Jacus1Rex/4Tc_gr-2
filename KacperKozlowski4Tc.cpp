#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class List {
  public:
    int len;
    int* nums;

    List(int len) {
      this->len = len;
      nums = new int[len];
      srand(time(0));
      for (int i = 0; i < len; i++) {
        nums[i] = rand() % 1000 + 1;
      }
    }

    ~List() {
      delete[] nums;
    }
    
    /*
    ************
    nazwa metody:         print
    opis metody:          metoda wypisuje wszystkie elementy tablicy
    parametry:            brak
    zwracany typ i opis:  brak 
    ***********    
    */
    void print() {
      for (int i = 0; i < len; i++) {
        cout << i << ": " << nums[i] << "\n";
      }
      cout << endl;
    }

    /*
    ************
    nazwa metody:         find
    opis metody:          metoda szuka podanej liczby w tablicy i zwraca jej index. jezeli nie znaleziono liczby zwracane jest -1
    parametry:            int number - szukana liczba
    zwracany typ i opis:  int, zwracany jest index szukanej liczby, jezeli jej nie znaleziono, zwracane jest -1
    ***********    
    */
    int find(int number) {
      for (int i = 0; i < len; i++)
      {
        if (number == nums[i]) return i;
      }

      return -1;
    }

    /*
    ************
    nazwa metody:         odds
    opis metody:          metoda zlicza ilosc liczb parzystych w tablicy i je wypisuje
    parametry:            brak
    zwracany typ i opis:  int, zwracana jest ilosc wystapien liczb parzystych w tablicy
    ***********    
    */
    int odds() {
      int count = 0;

      for (int i = 0; i < len; i++)
      {
        if (nums[i] % 2 != 0) {
          ++count;
          cout << nums[i] << "\n";
        } 
      }

      cout << "\n";
      return count;
    }


    /*
    ************
    nazwa metody:         avg
    opis metody:          metoda zlicza srednia arytmetyczna liczb z tablicy i ja zwraca
    parametry:            brak
    zwracany typ i opis:  float, zwracana jest srednia arytmetyczna liczb z tablicy
    ***********    
    */
    float avg() {
      float sum = 0;

      for (int i = 0; i < len; i++)
      {
        sum += nums[i];
      }

      return sum / len;
    }
};

int main() {
  List list = {25};
  
  list.print();

  int index = list.find(563);

  if (index != -1) cout << "Znaleziono wartosc. Index: " << index;


  cout << "Liczby nieparzyste: \n";
  int count = list.odds();
  cout << "\nRazem nieparzystych: " << count;

  cout << "\nSrednia wszystkich elementow: " << list.avg();
  
  return 0;
}