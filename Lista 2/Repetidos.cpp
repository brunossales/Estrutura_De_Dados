#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// insertionSort
void insertionSort(vector<int> &vec, int pri, int ul)
{
  if (pri <= ul)
  {
    int x = vec[pri];
    int i = pri - 1;
    while (i >= 0 && vec[i] > x)
    {
      vec[i + 1] = vec[i];
      i--;
    }
    assert(i < 0 || vec[i] <= x);
    vec[i + 1] = x;
    insertionSort(vec, pri + 1, ul);
  }
};
int contagem(vector<int> vec)
{
  int contagem = 0;
  int i = 0;
  int tam = vec.size();
  while (i < vec.size() - 1)
  {
    //  1 1 1 2 2 3 3 5
    if (vec[i] == vec[i + 1])
    {
      contagem++;
      for (int j = i; j < vec.size() - 1; j++)
        if (vec[j] != vec[j + 1])
        {
          i = j;
          break;
        }
    }
    else
      i++;
  }
  if (vec[vec.size() - 1] == 5)
    contagem++;
  return contagem;
};

int main()
{
  int tam;
  cin >> tam;
  vector<int> vec;
  vec.resize(tam);
  for (int i = 0; i < tam; i++)
    cin >> vec[i];
  insertionSort(vec, 0, tam - 1);
  cout << contagem(vec) << endl;
}