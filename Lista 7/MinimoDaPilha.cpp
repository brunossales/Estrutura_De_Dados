#include <iostream>
#include <stack>
using namespace std;

template <class T>
class StackMin
{
private:
  stack<T> data;
  stack<T> min;

public:
  void push(T x)
  {
    if (data.empty())
    {
      data.push(x);
      min.push(x);
    }
    else
    {
      auto minTop = min.top();
      if (x < minTop)
      {
        data.push(x);
        min.push(x);
      }
      else
      {
        data.push(x);
        min.push(minTop);
      }
    }
  }

  bool empty()
  {
    if (data.empty())
      return true;
    else
      return false;
  }

  T top() { return data.top(); }

  void pop()
  {
    data.pop();
    min.pop();
  }

  T getmin() { return min.top(); }
};

int main()
{
  int n;
  StackMin<int> s;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int op, x;
    cin >> op;

    if (op == 1)
    {
      cin >> x;
      s.push(x);
    }
    else if (op == 2)
      s.pop();

    else
      cout << s.getmin() << endl;
  }
}