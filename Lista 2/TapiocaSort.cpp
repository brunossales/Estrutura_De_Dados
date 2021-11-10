#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// maior
int aux = 0;
int maior(vector<int> vec, int tam)
{
  int maior = 0;
  for (int i = 1; i < tam; i++)
    if (vec[i] > vec[maior])
      maior = i;
  return maior;
};
//esta ordenado
bool ordenado(vector<int> vec)
{
  for (int i = 0; i < vec.size() - 1; i++)
    if (vec[i] > vec[i + 1])
      return false;
  return true;
};
//virada
void virada(vector<int> &vec, int &con)
{
  if (ordenado(vec))
    return;
  int tam = vec.size() - 1 - aux;
  int index = maior(vec, tam);
  aux++;
  //virar uma parte, do maior pra esquerda
  for (int i = index; i >= 0; i--)
  {
    // 1 2 3 5 6
    if (index % 2 != 0 && i == index / 2)
      continue;
    else
      swap(vec[i], vec[index - i]);
  }
  con++;
  if (ordenado(vec))
    return;
  //virar todo
  for (int i = tam; i >= 0; i--)
  {
    // 1 2 3 5 6
    if (tam % 2 != 0 && i == tam / 2)
      continue;
    else
      swap(vec[i], vec[tam - i]);
  }
  con++;
  if (ordenado(vec))
    return;
  virada(vec, con);
};

int main()
{
  int tam;
  int con = 0;
  cin >> tam;
  vector<int> tapiocas(tam);
  for (int i = 0; i < tam; i++)
    cin >> tapiocas[i];
  virada(tapiocas, con);
  for (int i = con; i >= 0; i++)
    cout << i << " ";
  cout << "\n";
}