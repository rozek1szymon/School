#ifndef CRAMER_H
#define CRAMER_H


using namespace std;
double f_det(int n, int w, int *WK, double **M); //funkcja obliczajaca wyznacznik macierzy
void f_rozwiazUklad(double *tabWyznacznikow, double *&tabWynikow, int liczbaNiewiadomych, bool &ukladOznaczony); //procedura przedstawiajaca rozwiazanie ukladu
void f_stworzUkladRownan(double **&M, int n);//procedura stwarza macierz kwadratowa o wymiarze n x n
void f_obliczWyznaczniki(double **M, double **W, double *&tabWyznacznikow, int *WK, int n); //procedura obliczajaca wyznaczniki ukladu Cramera
double f_obliczBlad(double **M, double *tabWynikow, int liczbaNiewiadomych); //funkcja zwracajaca blad
void f_stworzMacierzKwadratowa(double **&M, int n); //procedura tworzaca macierz kwadratowa
void f_usunMacierz(double **&M, int n); //procedura zwalniajaca pamiec

#endif
