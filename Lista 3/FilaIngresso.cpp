#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void view(vector<int> idPessoa)
{
  for (int i = 0; i < idPessoa.size(); i++)
    cout << idPessoa[i] << " ";
  cout << "\n";
};

void fila(vector<int> &idPessoa, vector<int> &idSaindo)
{
  for (int i = 0; i < idSaindo.size(); i++)
    for (int j = 0; j < idPessoa.size(); j++)
      if (idSaindo[i] == idPessoa[j])
        idPessoa.erase(idPessoa.begin() + j);
  view(idPessoa);
};

int main()
{
  int N, M;
  vector<int> idPessoa, idSaindo;
  cin >> N;
  idPessoa.resize(N);
  for (int i = 0; i < N; i++)
    cin >> idPessoa[i];
  cin >> M;
  idSaindo.resize(M);
  for (int i = 0; i < M; i++)
    cin >> idSaindo[i];
  fila(idPessoa, idSaindo);
}