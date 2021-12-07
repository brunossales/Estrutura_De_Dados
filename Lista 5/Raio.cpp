#include <iostream>
#include "Raios.hpp"

using namespace std;

int main()
{
  int n;
  cin >> n;
  Raios r(500, 500);
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    r.add(x, y);
  }
  cout << r.mesmoLugar() << endl;
}