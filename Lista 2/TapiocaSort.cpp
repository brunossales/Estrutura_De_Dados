#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// maior
int aux = 0;
int maior(vector<int> vec, int tam)
{
  int maior = 0;
  for (int i = 1; i <= tam; i++)
    if (vec[i] > vec[maior])
      maior = i;
  return maior;
};
//esta ordenado
bool ordenado(vector<int> vec)
{
  int tam = vec.size() - 1;
  for (int i = 0; i < tam; i++)
    if (vec[i] > vec[i + 1])
      return false;
  return true;
};
void inverter(vector<int> &vec, int index)
{
  for (int i = 0, j = index; i < j; i++, j--)
    swap(vec[i], vec[j]);
};

void print(vector<int> &vec)
{
  int n = vec.size();
  for (int i = 0; i < n; i++)
  {
    cout << vec[i] << " ";
  }
  cout << "0" << endl;
};

void virada(vector<int> &vec, int &con)
{
  int n = vec.size();
  vector<int> res;
  for (int i = n - 1; i >= 0; i--)
  {
    int index = maior(vec, i);

    // cout << "index : " << index << endl;

    if (index == 0)
    {
      inverter(vec, i);
      res.push_back(n - i);
    }
    else if (index != i)
    {
      inverter(vec, index);
      inverter(vec, i);
      res.push_back(n - index);
      res.push_back(n - i);
    }
    if (ordenado(vec))
    {
      print(res);
      break;
    }
    // print(vec);
  }
};

int main()
{
  int tam;
  int con = 0;
  cin >> tam;
  vector<int> tapiocas;
  tapiocas.resize(tam);
  for (int i = 0; i < tam; i++)
    cin >> tapiocas[i];
  virada(tapiocas, con);
}