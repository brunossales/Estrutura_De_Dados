#include <iostream>
#include <vector>
using namespace std;
// Selection_sort
// Pegar o index das menores posições

void selectionSort(vector<int> &vec, int pri, int ul)
{
  if (pri <= ul)
  {
    int menorIndex = pri;
    for (int i = pri + 1; i <= ul; i++)
      if (vec[i] < vec[menorIndex])
        menorIndex = i;

    swap(vec[pri], vec[menorIndex]); //ordenando
    selectionSort(vec, pri + 1, ul);
  }
};
void procuraIndex(vector<int> vec1, vector<int> vec2, vector<int> &vec3, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    for (int k = 0; k < tam; k++)
    {
      if (vec1[i] == vec2[k])
      {
        vec3.push_back(k);
        break;
      }
    }
  }
}
//bubbleSort
// void bubbleSort(int vec[], int pri, int ul)
// {
//   if (pri < ul)
//   {
//     int index;
//     int numTrocas = 0;
//     for (int k = pri; k < ul - 1; k++)
//     {
//       if (vec[k] > vec[k + 1])
//       {
//         numTrocas++;
//         swap();
//       }
//     }

//     if (numTrocas > 0)
//     {
//       bubbleSort(vec, pri, ul - 1);
//     }
//   }
// }
int main()
{
  int tam;
  cin >> tam;
  vector<int> vec;
  vector<int> vetor;
  vector<int> saida;
  vec.resize(tam);
  vetor.resize(tam);
  for (int i = 0; i < tam; i++)
    cin >> vec[i];
  for (int i = 0; i < tam; i++)
    vetor[i] = vec[i];

  selectionSort(vec, 0, tam - 1);
  procuraIndex(vec, vetor, saida, tam);
  // bubbleSort(vec, 0, tam - 1);
  for (int i = 0; i < tam; i++)
  {
    if (i == tam - 1)
    {
      cout << saida[i];
      break;
    }
    cout << saida[i] << " ";
  }
}