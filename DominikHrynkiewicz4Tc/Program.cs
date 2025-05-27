public class Tablica
{
    protected int tabLenght;
    protected int[] liczby;

    public Tablica(int lenght)
    {
        Random random = new Random();
        this.tabLenght = lenght;
        this.liczby = new int[tabLenght];
        for (int i = 0; i < this.tabLenght; i++)
        {
            this.liczby[i] = random.Next(0, 1001);
        }
    }
    /**********************************************
    nazwa metody: Tablica (konstruktor)
    opis metody: Inicjalizuje tablicę o zadanej długości i wypełnia ją losowymi liczbami z zakresu 0-1000
    parametry: lenght - długość tworzonej tablicy
    zwracany typ i opis: brak (konstruktor)
    ***********************************************/

    public void Show()
    {
        for (int i = 0; i < tabLenght; i++)
        {
            Console.WriteLine($"{i}: {liczby[i]}");
        }
    }
    /**********************************************
    nazwa metody: Show
    opis metody: Wyświetla wszystkie elementy tablicy wraz z ich indeksami
    parametry: brak
    zwracany typ i opis: void - metoda nic nie zwraca
    ***********************************************/

    public int Find(int wariable)
    {
        for (int i = 0; i < tabLenght; i++)
        {
            if (wariable == liczby[i]) return i;
        }
        return -1;
    }
    /**********************************************
    nazwa metody: Find
    opis metody: Szuka podanej wartości w tablicy i zwraca indeks pierwszego jej wystąpienia, jeśli nie znaleziono zwraca -1
    parametry: wariable - wartość do wyszukania w tablicy
    zwracany typ i opis: int - indeks znalezionej wartości lub -1 jeśli brak
    ***********************************************/

    public int Odd()
    {
        int sum = 0;
        Console.WriteLine("Liczny nieparzyste: ");
        foreach (int i in liczby) { if (i % 2 == 1) { sum += 1; Console.WriteLine(i); } }
        return sum;

    }
    /**********************************************
    nazwa metody: Odd
    opis metody: Wyświetla liczby nieparzyste z tablicy oraz zwraca ich ilość
    parametry: brak
    zwracany typ i opis: int - liczba nieparzystych elementów w tablicy
    ***********************************************/

    public double Average()
    {
        double sum = 0;
        foreach (int i in liczby) { sum += i; }
        sum /= tabLenght;
        return sum;
    }
    /**********************************************
    nazwa metody: Average
    opis metody: Oblicza i zwraca średnią arytmetyczną wszystkich elementów tablicy
    parametry: brak
    zwracany typ i opis: double - średnia wartość elementów w tablicy
    ***********************************************/
}

public class Program
{
    public static void Main(string[] args)
    {
        Tablica tablica = new Tablica(21);
        tablica.Show();
        int odd = tablica.Find(0);
        if (odd > 0) Console.WriteLine("Wartość indeksu wyszukanej: " + odd);
        Console.WriteLine("Razem liczb nieparzystych: " + tablica.Odd());
        Console.WriteLine("Średnia wszystkich elementów: " + Math.Round(tablica.Average(), 2));
    }
    /**********************************************
    nazwa metody: Main
    opis metody: Tworzy instancję klasy Tablica, wyświetla jej zawartość, szuka wartości 0, wyświetla liczbę nieparzystych oraz średnią elementów
    parametry: args - argumenty wiersza poleceń
    zwracany typ i opis: void - metoda nie zwraca wartości
    ***********************************************/
}
