#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
  int n, value;
  vector<int> inteiros, printt;
  stack<int> indexs;
  cin >> n;
  printt.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> value;
    inteiros.push_back(value);
  }
  // 2 9 8
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
      indexs.push(i);
    else
    {
      if (inteiros[i] > inteiros[indexs.top()])
      {
        while (!indexs.empty())
        {
          if (inteiros[i] > inteiros[indexs.top()])
          {
            printt[indexs.top()] = i;
            indexs.pop();
          }
          else
            break;
        }
        indexs.push(i);
      }
      else
        indexs.push(i);
    }
  }
  while (!indexs.empty())
  {
    printt[indexs.top()] = -1;
    indexs.pop();
  }
  for (int i = 0; i < n; i++)
  {
    if (i == n - 1)
    {
      cout << printt[i] << endl;
      break;
    }
    cout << printt[i] << " ";
  }
}