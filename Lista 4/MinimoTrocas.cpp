#include <iostream>
#include <vector>
using namespace std;

bool estaOrdenado(vector<int> vec)
{
  for (int i = 0; i < vec.size() - 1; i++)
    if (vec[i] > vec[i + 1])
      return false;
  return true;
}

//selection sort
int selectionSort(vector<int> &vec, int pri, int ult, int &contagem)
{
  // 2 8 5 4
  if (pri < ult)
  {
    int min_index = pri;
    for (int k = pri + 1; k <= ult; k++)
    {
      if (vec[k] < vec[min_index])
        min_index = k;
    }
    if (pri != min_index)
    {
      swap(vec[pri], vec[min_index]);
      contagem++;
    }
    if (estaOrdenado(vec))
      return contagem;
    selectionSort(vec, pri + 1, ult, contagem);
  }
}
int main()
{
  int tam, contagem{0};
  cin >> tam;
  vector<int> vec(tam);
  for (int i = 0; i < tam; i++)
    cin >> vec[i];
  int value = selectionSort(vec, 0, tam - 1, contagem);
  cout << value << endl;
}