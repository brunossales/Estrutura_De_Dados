#include <iostream>
using std::cin;
using std::cout;

int main()
{
  int sizeMatriz;
  int sizePesquisa;
  int result1, result2;
  cin >> sizeMatriz >> sizePesquisa;
  int matriz[99][99];
  int matrizPesquisa[99][99];
  for (int i = 0; i < sizeMatriz; i++)
  {
    int j = 0;
    do
    {
      cin >> matriz[i][j];
      j++;
    } while (j < matriz[i][0]);
  }
  for (int i = 0; i < sizePesquisa; i++)
  {
    int j = 0;
    do
    {
      cin >> matrizPesquisa[i][j];
      j++;
    } while (j < matrizPesquisa[i][0]);
  }
  int aux1 = matrizPesquisa[0][0];
  int aux2 = matrizPesquisa[0][1];
  int aux3 = matrizPesquisa[1][0];
  int aux4 = matrizPesquisa[1][1];

  result1 = matriz[aux1][aux2];
  result2 = matriz[aux3][aux4];
  cout << result1 << "\n";
  cout << result2 << "\n";
}