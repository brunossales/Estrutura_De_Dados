#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
  stringstream ss(str);
  int number{0};
  vector<int> vectorial;
  while (ss >> number)
  {
    char coma{0};
    vectorial.push_back(number);
    ss >> coma;
  }
  return vectorial;
}

int main()
{
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for (int i = 0; i < integers.size(); i++)
  {
    cout << integers[i] << "\n";
  }

  return 0;
}