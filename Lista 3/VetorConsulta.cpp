#include <iostream>
#include <vector>
using namespace std;
void view(vector<int> vec)
{
  for (int i = 0; i < vec.size(); i++)
    cout << vec[i] << " ";
  cout << "\n";
}
void contaBusca(vector<string> &con, vector<string> &busc, vector<int> &saida)
{
  for (int i = 0; i < busc.size(); i++)
    for (int j = 0; j < con.size(); j++)
      if (busc[i] == con[j])
        saida[i]++;
  view(saida);
};

int main()
{
  int tamConsulta, tamBusca;
  vector<int> saida;
  vector<string> consulta, busca;
  cin >> tamConsulta;
  consulta.resize(tamConsulta);
  for (int i = 0; i < tamConsulta; i++)
    cin >> consulta[i];
  cin >> tamBusca;
  busca.resize(tamBusca);
  for (int i = 0; i < tamBusca; i++)
    cin >> busca[i];
  saida.resize(tamBusca);
  contaBusca(consulta, busca, saida);
}