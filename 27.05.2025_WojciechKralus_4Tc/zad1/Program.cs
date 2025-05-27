using System;

/*nazwa metody: ShowItems
opis metody: Pokazuje index elementu tablicy i jego wartość
parametry: brak
zwracany typ i opis: void - metoda nic nie zwraca

nazwa metody: FirstShow
opis metody: Szuka podana liczbe w wartościach tablicy
parametry: szukana - parametr ten jest wartościa jaką szukamy w tablicy
zwracany typ i opis: int - zwraca index wartości jeśli znalazł wartość a jeśli nie znalazł to zwrata -1

nazwa metody: Odd
opis metody: wyświetlająca wartości nieparzyste z tablicy i podaje ich ilość
parametry: brak
zwracany typ i opis: void - metoda nic nie zwraca

nazwa metody: Odd
opis metody: wyświetlająca wartości nieparzyste z tablicy i podaje ich ilość
parametry: brak
zwracany typ i opis: void - metoda nic nie zwraca

nazwa metody: Avg
opis metody: liczy średnią artmetyczną wartości z tablicy i ja wyświetla
parametry: brak
zwracany typ i opis: void - metoda nic nie zwraca
autor: Wojciech Karalus 4Tc
*/

namespace Main
{
    class Tablica
    {
        private int[] liczby;
        private int n;

        public void ShowItems()
        {
            for (int i = 0; i < liczby.Length; i++)
            {
                Console.WriteLine($"{i}:{liczby[i]}");
            }
        }

        public int FirstShow(int szukana)
        {
            for (int i = 0; i < liczby.Length; i++)
            {
                if(liczby[i] == szukana)
                {
                    return i;
                }
            }
            return -1;
        }

        public void Odd()
        {
            Console.WriteLine("Liczby nieparzyste:");
            int a = 0;
            for (int i = 0; i < liczby.Length; i++)
            {
                if (liczby[i] % 2 != 0)
                {
                    Console.WriteLine($"{liczby[i]}");
                    a++;
                }
            }
            Console.WriteLine($"razem nieparzystych: {a}");
        }

        public void Avg()
        {
            int added = 0;
            for(int i =0;  i < liczby.Length; i++)
            {
                added += liczby[i];
            }
            double average = added / n;
            Console.WriteLine($"Srednia wszystkich elementow: {average}");
        }
        public Tablica(int dlugosc)
        {
            this.n = dlugosc;
            this.liczby = new int[dlugosc];
            Random rand = new Random();
            for(int i = 0; i < dlugosc; i++)
            {
                liczby[i] = rand.Next(1, 1001);
            }
        }
    }
    public class Program
    {
        static void Main(string[] args)
        {
            Tablica t = new Tablica(22);
            t.ShowItems();
            t.FirstShow(180);
            t.Odd();
            t.Avg();
        }
    }
}