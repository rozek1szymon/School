#include <iostream>
#include "OdwrotnaMacierz.h"
#include "Cramer.h"
using namespace std;

/*
@param W - stopien macierzy wspolczynnikow
@param MacierzWspolczynnikow - macierz wspolczynnikow
*/
bool f_odwracanieMacierzy(int W, double **&MacierzWspolczynnikow)
{
    int *WK; // wiersz kolumn
    WK = new int[W];                              // tworzymy wiersz kolumn
    for(int i = 0; i < W; i++) WK[i] = i;             // wypelniamy go numerami kolumn
    cout << f_det(W,0,WK, MacierzWspolczynnikow) << endl;
    if( f_det(W,0,WK, MacierzWspolczynnikow) == 0 )
    {
        cout << "Ten uklad rownan nie moze byc rozwiazany ta metoda, " << endl << "poniewaz macierz jest nieodwracalna" << endl;
        return false;
    }

    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < W; j++)
        {

            cout << MacierzWspolczynnikow[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < W; i++)
    {
        MacierzWspolczynnikow[i][i] = 1 / MacierzWspolczynnikow[i][i];
        for (int j = 0; j < W; j++) if (j != i)
            {
                MacierzWspolczynnikow[j][i] = MacierzWspolczynnikow[j][i] * MacierzWspolczynnikow[i][i];
                for (int k = 0; k < W; k++) if (k != i)
                    {
                        MacierzWspolczynnikow[j][k] -= MacierzWspolczynnikow[j][i] * MacierzWspolczynnikow[i][k];
                        if (j == (W - 1))
                            MacierzWspolczynnikow[i][k] = -(MacierzWspolczynnikow[i][k] * MacierzWspolczynnikow[i][i]);
                    }
            }
    }

    cout << "\nmacierz odwrotna\n\n";
    int w = W - 1;

    for (int j = 0; j < w; j++) MacierzWspolczynnikow[w][j] = -(MacierzWspolczynnikow[w][j] * MacierzWspolczynnikow[w][w]);

    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout.width(10);
            cout << MacierzWspolczynnikow[i][j] << " ";
        }
        cout << endl << endl;
    }
    return true;
}
//funkcja stricte przystosowana do mnozenia macierzy 4x4 z 4x1 ofc do zmienienia w razie potrzeby
void f_mnozMacierze(double **MacierzWyrazowWolnych, double **MacierzWspolczynnikow, double *&tabWynikow)
{
    double macierz_rozwiazan[4][1] = {{0},{0},{0},{0}};

    for (int row = 0; row < 4; row++)
        {
        for (int col = 0; col < 1; col++)
        {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 4; inner++)
            {
                macierz_rozwiazan[row][col] += MacierzWspolczynnikow[row][inner] * MacierzWyrazowWolnych[inner][col];
            }
            tabWynikow[row] = macierz_rozwiazan[row][col];
            cout << "x" << row << ": " << macierz_rozwiazan[row][col] << "  ";
        }
        cout << "\n";
    }
}

void f_wypelnijMacierzWspolczynnikow(double **M, double **&MacierzWspolczynnikow, int liczbaNiewiadomych)
{
    for(int i = 0; i < liczbaNiewiadomych; i++)
        for(int j = 0; j < liczbaNiewiadomych; j++)
        {
            //cout << M[i][j] << endl;
            MacierzWspolczynnikow[i][j] = M[i][j];
        }

}

void f_wypelnijMacierzWyrazowWolnych(double **M, double **&MacierzWyrazowWolnych, int liczbaNiewiadomych)
{
    for(int i = 0; i < liczbaNiewiadomych; i++) MacierzWyrazowWolnych[i][0] = M[i][liczbaNiewiadomych];
}
