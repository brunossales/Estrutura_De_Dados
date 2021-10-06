#include <iostream>
#include <string>
using namespace std;

int main()
{
  string primeira;
  string segunda;
  cin >> primeira;
  cin >> segunda;
  int size1 = primeira.size();
  int size2 = segunda.size();
  string concat = primeira + segunda;
  swap(segunda[0], primeira[0]);
  cout << size1 << " " << size2 << endl;
  cout << concat << endl;
  cout << primeira << " " << segunda << endl;
}