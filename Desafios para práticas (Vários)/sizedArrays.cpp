#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int sizeMatriz;
  int sizePesquisa;
  cin >> sizeMatriz >> sizePesquisa;
  vector<vector<int>> matriz(sizeMatriz);
  for (int i = 0; i < sizeMatriz; i++)
  {
    int larguda;
    cin >> larguda;
    matriz[i].resize(larguda);
    for (int j = 0; j < larguda; j++)
      cin >> matriz[i][j];
  }
  for (int k = 0; k < sizePesquisa; k++)
  {
    int j, i;
    cin >> i >> j;
    cout << matriz[i][j] << "\n";
  }
  return 0;
}