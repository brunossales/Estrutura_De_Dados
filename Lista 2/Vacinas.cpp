#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// InsertionSort
void insertionSort(vector<int> &vec, int pri, int ul)
{
  if (pri <= ul)
  {
    // 2 5 6 1
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
bool testaSeNaoMorre(vector<int> vac, vector<int> pac)
{
  for (int i = 0; i < vac.size(); i++)
    if (pac[i] > vac[i])
      return false;
  return true;
};
int main()
{
  int tam;
  cin >> tam;
  vector<int> vacinas(tam);
  vector<int> pacientes(tam);
  for (int i = 0; i < tam; i++)
    cin >> vacinas[i];
  for (int i = 0; i < tam; i++)
    cin >> pacientes[i];
  insertionSort(vacinas, 0, tam - 1);
  insertionSort(pacientes, 0, tam - 1);
  string saida = testaSeNaoMorre(vacinas, pacientes) == true ? "Yes" : "No";
  cout << saida << endl;
}