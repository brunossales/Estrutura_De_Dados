#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &vec, int pri, int ult)
{
  if (pri <= ult)
  {
    int x = vec[pri];
    int i = pri - 1;
    while (i >= 0 && vec[i] >= x)
    {
      vec[i + 1] = vec[i];
      i--;
    }
    assert(i < 0 || vec[i] <= x);
    vec[i + 1] = x;
    insertionSort(vec, pri + 1, ult);
  }
};
int main()
{
  int tam, op, op2;
  cin >> tam;
  vector<int> vec;
  for (int i = 0; i < tam; i++)
  {
    cin >> op >> op2;
    if (op == 1)
      vec.push_back(op2);
    else
    {
      insertionSort(vec, 0, vec.size() - 1);
      int i = vec[op2];
      cout << i << endl;
    }
  }
}
