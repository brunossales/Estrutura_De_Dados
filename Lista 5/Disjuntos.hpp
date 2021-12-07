#ifndef DisjuntosHpp // se não incluiu, inclui, as vezes acontece de incluir o istream aqui e la...

#define DisjuntosHpp

#include <iostream>
#include <vector>
using namespace std;

class Disjuntos
{
private:
  vector<int> x, y, mesmos;

public:
  Disjuntos(int n)
  {
    int aux = n - 1;
    for (int i = 0; i < n; i < i++)
    {
      x.push_back(i);
      y.push_back(aux);
      aux--;
    }
  }
  void une(int a, int b)
  {
    bool n1, n2 = false;
    for (int i = 0; i < mesmos.size(); i++)
    {
      if (mesmos[i] == a)
        n1 = true;
      else if (mesmos[i] == b)
        n2 = true;
    }
    if (n1 == false)
      mesmos.push_back(a);
    if (n2 == false)
      mesmos.push_back(b);
  }
  int mesmo(int x, int y)
  {
    int cont = 0;
    for (int i : mesmos)
    {
      if (i == x)
        cont++;
      else if (i == y)
        cont++;
    }
    if (cont >= 2)
      return 1;
    return 0;
  }
};

#endif