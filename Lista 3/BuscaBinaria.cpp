#include <iostream>
#include <vector>
using namespace std;

void view(vector<int> saida)
{
  for (int i = 0; i < saida.size(); i++)
    cout << saida[i] << " ";
  cout << "\n";
}
//busca binario, vou chamar agora de busca inteligente. Gostei muito da ideia agora que entendi
int busca_binaria(vector<int> vec, int tam, int item)
{
  int inicio = 0;
  int fim = tam - 1;
  int contador = 0;
  while (inicio <= fim)
  {
    int meio = (inicio + fim) / 2;
    contador++;
    if (vec[meio] == item)
      break;
    else
    {
      if (vec[meio] > item)
        fim = meio - 1;
      else
        inicio = meio + 1;
    }
  }
  return contador;
};

void cria_busca(vector<int> vec, vector<int> busca)
{
  int tamVec = vec.size();
  int tamBusca = busca.size();
  vector<int> saida(tamBusca);
  for (int i = 0; i < tamBusca; i++)
    saida[i] = busca_binaria(vec, tamVec, busca[i]);
  view(saida);
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> vector(n), busca(m);
  for (int i = 0; i < n; i++)
    cin >> vector[i];
  for (int i = 0; i < m; i++)
    cin >> busca[i];
  cria_busca(vector, busca);
}