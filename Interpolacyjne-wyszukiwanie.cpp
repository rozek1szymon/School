#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 100;

int main()
{
  int Z[N],i,ip,ik,isr,k,L,p;

  srand((unsigned)time(NULL));

  // wype³niamy tablicê Z[]

  Z[0] = rand() % 5;
  for(i = 1; i < N; i++) Z[i] = Z[i - 1] + (rand() % 5);

  // generujemy klucz k

  k = Z[0] + (rand() % (Z[N - 1] - Z[0] + 1));

  // poszukujemy interpolacyjnie elementu k

  p = -1; L = ip = 0; ik = N - 1;
  while((Z[ip] <= k) && (k <= Z[ik]))
  {
    L++;
    isr = ip + (k-Z[ip])*(ik-ip) / (Z[ik]-Z[ip]);
    if(Z[isr] == k)
    {
      p = isr; break;
    }
    else if(k < Z[isr])
      ik = isr - 1;
    else
      ip = isr + 1;
  }

  // wyœwietlamy wyniki

  cout << k << " : ";
  if(p >= 0) cout << p; else cout << "BRAK";
  cout << " : obiegi = " << L << endl << endl;
  for(i = 0; i < N; i++)
  {
    cout << setw(3) << Z[i];
    if(p == i) cout << "<"; else cout << " ";
  }
  cout << endl << endl;
  return 0;
}
