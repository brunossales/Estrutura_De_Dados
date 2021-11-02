#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//insertion sort
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
void contagem(vector<int> vet)
{
  vector<int> contagem(vet.size());
  int index = 0;
  int indexNum = 0;
  for (int i = 0; i < vet.size() - 1; i++)
  {
    if (vet[i] == vet[i + 1])
      contagem[index]++;
    else
    {
      contagem[index]++;
      index++;
    }
  }
  indexNum = vet[0];
  for (int i = 0; i < index; i++)
  {
    if (contagem[i] < contagem[i + 1])
    {
      contagem[0] = contagem[i + 1];
      indexNum = vet[i + 1];
    }
  }
  cout << indexNum << " " << contagem[0] << endl;
}
int main()
{
  int tam{0};
  cin >> tam;
  vector<int> vec;
  vec.resize(tam);
  for (int i = 0; i < tam; i++)
    cin >> vec[i];
  insertionSort(vec, 0, tam - 1);
  contagem(vec);
  // for (int i = 0; i < tam; i++)
  //   cout << vec[i] << " ";
}