#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>
using namespace std;

string expr;
int pos = 0;

string get_token()
{
  string token = "";
  if (pos == expr.size())
  {
    token = "$";
    return token;
  }

  while (expr[pos] == ' ')
    pos++;

  if (expr[pos] == '+' ||
      expr[pos] == '-' ||
      expr[pos] == '*' ||
      expr[pos] == '/')
  {

    token += expr[pos];
    pos++;
    return token;
  }
  else if (isdigit(expr[pos]))
  {
    while (isdigit(expr[pos]))
    {
      token += expr[pos];
      pos++;
    }
    return token;
  }
  return token;
}

int main()
{
  getline(cin, expr);
  stack<int> s;
  string token = get_token();
  while (token != "$")
  {
    auto val1, val2, op;
    if (token == "+")
    {
      val1 = s.top();
      s.pop();
      val2 = s.top();
      s.pop();
      op = val1 + val2;
      s.push(op);
    }
    else if (token == "-")
    {
      val1 = s.top();
      s.pop();
      val2 = s.top();
      s.pop();
      op = val1 - val2;
      s.push(op);
    }
    else if (token == "*")
    {
      val1 = s.top();
      s.pop();
      val2 = s.top();
      s.pop();
      op = val1 * val2;
      s.push(op);
    }
    else if (token == "/")
    {
      val1 = s.top();
      s.pop();
      val2 = s.top();
      s.pop();
      op = val1 / val2;
      s.push(op);
    }
    else
    {
      s.push(atoi(token.c_str()));
    }
    token = get_token();
  }
}