#ifndef RaiosHpp
#define RaiosHpp

#include <iostream>
#include <vector>
using namespace std;

class Raios
{
private:
  int width;
  int length;
  // tentei usando matriz, mas deu problema
  vector<int> x, y;

public:
  Raios(int n, int m)
  {
    this->width = n;
    this->length = m;
  }
  void add(int x, int y)
  {
    this->x.push_back(x);
    this->y.push_back(y);
  }
  int mesmoLugar()
  {
    for (int i = 0; i < x.size(); i++)
      for (int j = i + 1; j < x.size(); j++)
        if (x[i] == x[j] && y[i] == y[j])
          return 1;
    return 0;
  }
};
#endif
