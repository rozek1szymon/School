#include <iostream>
#include "Cramer.h"
#include "OdwrotnaMacierz.h"
using namespace std;

/*
@param M - macierz przedstawiajaca uklad rownan
@param W - macierz robocza w ktorej beda przechowywane wyznaczniki
@param WK - wiersz kolumn uzyty w funkcji f_det
@param n - stopien macierzy, ktora jest ukladem (przedstawia ilosc kolumn ukladu)
@param tabWyznacznikow - tablica wyznacznikow
@param tabWynikow - tablica wynikow
@param liczbaNiewiadomych - liczba niewiadomych
@param ukladOznaczony - daje informacje czy liczyc blad ukladu oznaczonego
@param MacierzWyrazowWolnych - Macierz wyrazow wolnych
@param MacierzWspolczynnikow - Macierz wspolczynnikow
*/

int main()
{
    int wyborMetody;
    double **M; // uklad rownan
    double **W; // macierz z ktorej bedzie liczony wyznacznik
    double **MacierzWyrazowWolnych;
    double **MacierzWspolczynnikow;
    int *WK; // wiersz kolumn

    double *tabWyznacznikow;
    double *tabWynikow;
    int liczbaNiewiadomych = 4;
    int n = 5; // stopien macierzy, ktora jest ukladem
    bool ukladOznaczony = true;

    cout << "Wybierz metode rozwiazywania ukladu rownan (Cramer - 1, Odwrotna Macierz - 2)" << endl;
    while( !(cin >> wyborMetody) || wyborMetody > 2 || wyborMetody < 1 )
    {
        cout << "Bledne dane, wprowadz numer metody ponownie:" << endl;
        cin.clear(); //kasowanie flagi b³êdu strumienia
        cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    if( wyborMetody == 1)
    {
    cout << "UKLAD ROWNAN ROZWIAZYWANY METODA CRAMERA" << endl << "Wprowadz liczbe niewiadomych: ";
    while( !(cin >> liczbaNiewiadomych) )
    {
        cout << "Bledne dane, wprowadz liczbe niewiadomych ponownie:" << endl;
        cin.clear(); //kasowanie flagi b³êdu strumienia
        cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    n = liczbaNiewiadomych + 1;

    tabWyznacznikow = new double[liczbaNiewiadomych];
    tabWynikow = new double[liczbaNiewiadomych];

    WK = new int[n];                              // tworzymy wiersz kolumn
    for(int i = 0; i < n; i++) WK[i] = i;             // wypelniamy go numerami kolumn

    f_stworzMacierzKwadratowa(W, liczbaNiewiadomych);
    f_stworzUkladRownan(M,n);
    f_obliczWyznaczniki(M,W,tabWyznacznikow,WK,n);
    f_rozwiazUklad(tabWyznacznikow, tabWynikow, liczbaNiewiadomych, ukladOznaczony);
    if(ukladOznaczony) cout << "BLAD JEST ROWNY " << f_obliczBlad(M,tabWynikow,liczbaNiewiadomych) << endl;

    f_usunMacierz(M,n);
    f_usunMacierz(W,n-1);
    delete []tabWynikow;
    delete []WK;
    delete []tabWyznacznikow;
    }
    else
    {
        cout << "UKLAD ROWNAN ROZWIAZYWANY METODA MACIERZY ODWROTNEJ" << endl;
        MacierzWyrazowWolnych = new double *[liczbaNiewiadomych];
        for (int j = 0; j < liczbaNiewiadomych; j++) MacierzWyrazowWolnych[j] = new double[1];

        f_stworzMacierzKwadratowa(MacierzWspolczynnikow, liczbaNiewiadomych);
        f_stworzUkladRownan(M, n);
        f_wypelnijMacierzWspolczynnikow(M, MacierzWspolczynnikow, liczbaNiewiadomych);
        f_wypelnijMacierzWyrazowWolnych(M, MacierzWyrazowWolnych, liczbaNiewiadomych);

        if(f_odwracanieMacierzy(liczbaNiewiadomych, MacierzWspolczynnikow))
        {
            tabWynikow = new double[liczbaNiewiadomych];
            f_mnozMacierze(MacierzWyrazowWolnych, MacierzWspolczynnikow, tabWynikow);
            cout << "BLAD JEST ROWNY " << f_obliczBlad(M,tabWynikow,liczbaNiewiadomych) << endl;
        }
        delete []tabWynikow;
        f_usunMacierz(M,n);
        f_usunMacierz(MacierzWspolczynnikow,n-1);
        f_usunMacierz(MacierzWyrazowWolnych,n-1);
        delete []tabWynikow;
    }


    return 0;
}
