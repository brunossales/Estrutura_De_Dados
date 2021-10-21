#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
// using std::string;
// using std::cout;
// using std::cin;
void printar(vector<int> vet)
{
  cout << vet.at(0) << " ";
  if (vet.size() == 1)
    return;
  vet.erase(vet.begin());
  printar(vet);
};
void printarAoInverso(vector<int> vet)
{
  cout << vet.at(vet.size() - 1) << " ";
  if (vet.size() == 1)
    return;
  vet.pop_back();
  printarAoInverso(vet);
}

int main()
{
  string line;
  getline(cin, line);
  stringstream ss(line);
  vector<int> vet;
  int valores;
  while (ss >> valores)
    vet.push_back(valores);
  vector<int> aux1 = vet;
  vector<int> aux2 = vet;
  printar(aux1);
  cout << endl;
  printarAoInverso(aux2);
}