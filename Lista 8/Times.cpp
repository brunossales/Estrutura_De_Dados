#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Estudante
{
public:
  string nome;
  int h;
  Estudante() {}
  Estudante(string nome, int h) : nome(nome), h(h) {}
};

void view(int n, int t, vector<Estudante> v)
{
  // Quantidade de times
  for (int i = 1; i <= t; i++)
  {
    cout << "Time " << i << endl;
    // Armazer o time i
    vector<string> time;
    // começa de 0, pega o jogador 0 e pula o número de times
    // Se for t = 3, o proximo k será 3
    // porque o index 1 vai para o time 2 e o index 2 vai para o time 3
    for (int k = i - 1; k < n; k += t)
    {
      time.push_back(v[k].nome);
    }
    // Ordenar por alfabetica
    sort(time.begin(), time.end());
    // printar os times
    for (int j = 0; j < time.size(); j++)
      cout << time[j] << endl;
    cout << endl;
  }
  cout << endl;
}

bool comp(const Estudante e1, const Estudante e2)
{
  return e1.h > e2.h;
}

int main()
{
  int n, t;

  cin >> n >> t;

  vector<Estudante> v;

  v.resize(n);

  for (int i = 0; i < n; i++)
  {
    cin >> v[i].nome >> v[i].h;
  }

  // Ordena os estudantes em ordem decrescente
  sort(v.begin(), v.end(), comp);
  view(n, t, v);
}