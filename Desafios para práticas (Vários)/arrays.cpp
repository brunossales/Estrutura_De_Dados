#include <iostream>
using std::cin;
using std::cout;

int main()
{
  int size;
  cin >> size;
  int vector[size];
  for (int i = 0; i < size; i++)
    cin >> vector[i];
  for (int i = size - 1; i >= 0; i--)
    cout << vector[i] << " ";
}