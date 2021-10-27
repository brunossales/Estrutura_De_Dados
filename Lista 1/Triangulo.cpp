#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
vector<vector<int>> aux;
int calc(int i, int j, int n)
{
  if (i == n - 1)
    return aux[i][j];
  else
  {
    aux[i][j] = calc(i + 1, j, n) + calc(i + 1, j + 1, n);
    return aux[i][j];
  }
};
int main()
{
  string line;
  getline(cin, line);
  stringstream ss(line);
  vector<int> v;
  int valores;
  while (ss >> valores)
    v.push_back(valores);

  aux.resize(v.size());
  for (int i = 0; i < v.size(); i++)
  {
    aux[i].resize(v.size());
  }
  for (int i = 0; i < v.size(); i++)
    aux[v.size() - 1][i] = v[i];

  calc(0, 0, v.size());
  for (int i = 0; i < v.size(); i++)
  {
    cout << "[ ";
    for (int j = 0; j <= i; j++)
    {
      cout << aux[i][j] << " ";
    }
    cout << "]\n";
  }
}