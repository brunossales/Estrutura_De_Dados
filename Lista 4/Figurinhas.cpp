#include <iostream>
#include <vector>
using namespace std;

//Marge
void merge(vector<int> &a, int start, int mid, int end)
{
  vector<int> w;
  w.resize(end - start + 1);
  int i = start;
  int j = mid + 1;
  int k = 0;
  while (i <= mid && j <= end)
  {
    if (a[i] < a[j])
      w[k] = a[i], k++, i++;
    else
      w[k] = a[j], k++, j++;
  }
  while (i <= mid)
    w[k] = a[i], k++, i++;
  while (j <= end)
    w[k] = a[j], k++, j++;
  for (int i = start; i <= end; i++)
    a[i] = w[i - start];
};
//Merge Sort
void mergeSort(vector<int> &a, int start, int end)
{
  if (end > start)
  {
    int mid = (start + end) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);
    merge(a, start, mid, end);
  }
};

bool saoIguais(vector<int> bruno, vector<int> getulio)
{
  for (int i = 0; i < bruno.size() - 1; i++)
    if (bruno[i] != getulio[i])
      return false;
  return true;
};
int main()
{
  int tam;
  cin >> tam;
  vector<int> bruno(tam), getulio(tam);
  for (int i = 0; i < tam; i++)
    cin >> bruno[i];
  for (int i = 0; i < tam; i++)
    cin >> getulio[i];
  mergeSort(bruno, 0, tam - 1);
  mergeSort(getulio, 0, tam - 1);
  int saida = saoIguais(bruno, getulio) ? 1 : 0;
  cout << saida << endl;
}