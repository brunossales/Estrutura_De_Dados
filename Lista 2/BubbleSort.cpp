#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int bubblesortCont(int vet[], int size)
{
  int count = 0;
  bool swapped = true;
  while (swapped != false)
  {
    swapped = false;
    count++;
    for (int i = 0; i < size - 1; i++)
    {
      if (vet[i] > vet[i + 1])
      {
        swap(vet[i], vet[i + 1]);
        swapped = true;
      }
    }
  }
  return count;
}
int main()
{
  int size;
  string entrada;
  int valores;
  cin >> size;
  int vec[size];
  for (int i = 0; i < size; i++)
    cin >> vec[i];

  cout << bubblesortCont(vec, size) << endl;
}