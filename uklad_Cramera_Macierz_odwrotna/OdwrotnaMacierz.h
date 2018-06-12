#ifndef ODWROTNAMACIERZ_H
#define ODWROTNAMACIERZ_H


using namespace std;
bool f_odwracanieMacierzy(int W, double **&MacierzWspolczynnikow);//procedura odwracajaca macierz
void f_mnozMacierze(double **MacierzWyrazowWolnych, double **MacierzWspolczynnikow, double *&tabWynikow); //funkcja mnozaca macierze (macierz odwrocana wspolczynnikow z macierza wyrazow wolnych) i pokazujaca wynik
void f_wypelnijMacierzWspolczynnikow(double **M, double **&MacierzWspolczynnikow, int liczbaNiewiadomych);
void f_wypelnijMacierzWyrazowWolnych(double **M, double **&MacierzWyrazowWolnych, int liczbaNiewiadomych);
#endif
