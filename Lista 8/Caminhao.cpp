#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int bomba, quilometros, mV, mI;
  for (int i = 0; i < n; i++)
  {
    cin >> bomba >> quilometros;
    if (bomba >= quilometros)
    {
      int aux = bomba - quilometros;
      if (i == 0 || aux < mV)
      {
        mI = i;
        mV = aux;
      }
    }
  }
  cout << mI << endl;
}