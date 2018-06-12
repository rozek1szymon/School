#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#include "Cramer.h"

double f_det(int n, int w, int *WK, double **M)
{
    int i, j, k, m;
    int *KK;
    double det;

    if(n == 1) return M[w][WK[0]];                // sprawdzamy warunek zakonczenia rekurencji, macierz 1 x 1, wyznacznik równy elementowi
    else
    {
        KK = new int[n - 1];                        // tworzymy dynamiczny wektor kolumn
        det = 0;                                      // zerujemy wartosc rozwiniecia
        m = 1;                                      // poczatkowy mnoznik

        for(i = 0; i < n; i++)                      // petla obliczajaca rozwiniecie
        {
            k = 0;                                    // tworzymy wektor kolumn dla rekurencji
            for(j = 0; j < n - 1; j++)                // ma on o 1 kolumne mniej niz WK
            {
                if(k == i) k++;                         // pomijamy biezaca kolumne
                KK[j] = WK[k++];                        // pozostale kolumny przenosimy do KK
            }
            det += m * M[w][WK[i]] * f_det(n - 1,w  + 1, KK, M);
            m = -m;                                   // kolejny mnoznik

        }
        delete [] KK;                               // usuwamy zbedna juz tablice dynamiczna
        return det;                                   // ustalamy wartosc funkcji
    }
}

void f_rozwiazUklad(double *tabWyznacznikow, double *&tabWynikow, int liczbaNiewiadomych, bool &ukladOznaczony)
{
    if(tabWyznacznikow[0] == 0)
    {
        for(int i = 1; i < liczbaNiewiadomych + 1; i++)
            if(tabWyznacznikow[i] != 0)
            {
                cout << "Uklad sprzeczny" << endl;
                ukladOznaczony = false;
                return;
            }
        cout << "Uklad nieoznaczony" << endl;
        ukladOznaczony = false;
        return;
    }

    for(int i = 0; i < liczbaNiewiadomych; i++)
    {
        tabWynikow[i] = tabWyznacznikow[i+1]/tabWyznacznikow[0];
        cout << "x" << i+1 << " = " << tabWynikow[i] << endl;
    }
}


void f_stworzUkladRownan(double **&M, int n)
{
    M = new double *[n-1];                         // tworzymy macierz wskazników
    for(int i = 0; i < n-1; i++)
    {
        cout << "Rownanie " << i+1 << endl;
        M[i] = new double[n];                       // tworzymy wiersz
        for(int j = 0; j < n; j++)
        {
            if(j == n-1)
            {
                cout << "wynik:";
                while( !(cin >> M[i][j]) )  // czytamy wiersz macierzy
                {
                    cout << "Bledne dane, wprowadz liczbe ponownie:" << endl;
                    cin.clear(); //kasowanie flagi błędu strumienia
                    cin.sync(); //kasowanie zbędnych znaków z bufora
                }

            }
            else
            {
                cout << "x" << j + 1 << ":";
                while( !(cin >> M[i][j]) )  // czytamy wiersz macierzy
                {
                    cout << "Bledne dane, wprowadz liczbe ponownie:" << endl;
                    cin.clear(); //kasowanie flagi błędu strumienia
                    cin.sync(); //kasowanie zbędnych znaków z bufora
                }

            }
        }
    }
}


void f_obliczWyznaczniki(double **M, double **W, double *&tabWyznacznikow, int *WK, int n)
{
    for(int nr_kolumny = -1; nr_kolumny < n-1; nr_kolumny++) // na poczatku liczymy wyznacznik glowny i nie zastepujemy niewiadomych macierza wynikow
    {
        for(int i = 0; i < n-1; i++)
        {
            for(int j = 0; j < n-1; j++)
            {
                if(j == nr_kolumny) W[i][j] = M[i][n-1];
                else W[i][j] = M[i][j];
            }
        }
       // cout << "Wyznacznik " << nr_kolumny + 1 << " " << f_det(n-1,0,WK,W) << endl;
        tabWyznacznikow[nr_kolumny+1] = f_det(n-1,0,WK,W);
    }
}

double f_obliczBlad(double **M, double *tabWynikow, int liczbaNiewiadomych)
{
    double suma = 0;
    double blad;
    for(int i = 0; i < liczbaNiewiadomych; i++) suma += M[0][i] * tabWynikow[i];
    blad = abs(suma - M[0][liczbaNiewiadomych]);
    return blad;
}

void f_stworzMacierzKwadratowa(double **&M, int n)
{
    M = new double *[n];
    for(int i = 0; i < n; i++) M[i] = new double[n];
}

void f_usunMacierz(double **&M, int n)
{
    for(int i = 0; i < n; i++) delete [] M[i];
    delete [] M;
}
