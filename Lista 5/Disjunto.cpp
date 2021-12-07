#include <iostream>
#include "Disjuntos.hpp"
using namespace std;

int main()
{
  Disjuntos D(5);
  cout << D.mesmo(0, 1) << endl; // 0
  cout << D.mesmo(1, 2) << endl; // 0
  cout << D.mesmo(2, 3) << endl; // 0
  cout << D.mesmo(3, 4) << endl; // 0
  cout << D.mesmo(4, 0) << endl; // 0

  D.une(0, 4);
  D.une(0, 1);

  cout << D.mesmo(0, 1) << endl; // 1
  cout << D.mesmo(1, 2) << endl; // 0
  cout << D.mesmo(2, 3) << endl; // 0
  cout << D.mesmo(3, 4) << endl; // 0
  cout << D.mesmo(4, 0) << endl; // 1

  D.une(1, 3);

  cout << D.mesmo(0, 1) << endl; // 1
  cout << D.mesmo(1, 2) << endl; // 0
  cout << D.mesmo(2, 3) << endl; // 0
  cout << D.mesmo(3, 4) << endl; // 1
  cout << D.mesmo(4, 0) << endl; // 1
}