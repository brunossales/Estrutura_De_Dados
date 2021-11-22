#include <bits/stdc++.h>
using namespace std;
//insertionSort
void insertionSort(vector<int> &vec, int p, int ul)
{
  if (p <= ul)
  {
    int pri = vec[p];
    int ult = p - 1;
    while (ult >= 0 && vec[ult] > pri)
    {
      vec[ult + 1] = vec[ult];
      ult--;
    }
    assert(ult < 0 || vec[ult] <= pri);
    vec[ult + 1] = pri;
    insertionSort(vec, p + 1, ul);
  }
};

//buscaBinaria
// int cows_distance(vector<int> vec, int cows)
// {
//   int tam = vec.size();
//   int menorIndex = vec[0];
//   int maior = vec[tam - 1] - menorIndex;

// };

//buscaSelecão

// void monta(vector<int> &vec, int menor, int maior)
// {
//   int i = 0;
//   while (menor <= maior)
//   {
//     vec[i] = menor;
//     menor++;
//     i++;
//   }
// };

int cows_aux(vector<int> &vectorr, vector<int> &vec, int cows)
{
  int contador = 1;
  int i = vectorr.size() - 1;
  int aux;
  bool achou = false;
  int distance;
  while (achou != true)
  {
    aux = vectorr[i];
    int k = 0;
    for (int j = k + 1; j < vec.size(); j++)
    {
      // 1 2 4 8 9
      int div = (vec[j] - vec[k]);
      if (div >= vectorr[i])
      {
        k = j;
        contador++;
      }
    }
    if (contador >= cows)
    {
      distance = vectorr[i];
      achou = true;
    }
    contador = 1;
    i--;
  }
  return distance;
}
int cows_distance(vector<int> vec, int cows)
{
  vector<int> vet;
  insertionSort(vec, 0, vec.size() - 1);
  for (int j = vec[1] - vec[0]; j < vec[vec.size() - 1] - vec[0]; j++)
    vet.push_back(j);

  return cows_aux(vet, vec, cows);
}
int main()
{
  int sizeVec, cows;
  cin >> sizeVec >> cows;
  vector<int> vec(sizeVec);
  for (int i = 0; i < sizeVec; i++)
    cin >> vec[i];
  int saida = cows_distance(vec, cows);
  cout << saida << endl;
}