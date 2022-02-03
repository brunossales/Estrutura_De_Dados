#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void setQueue(queue<char> *q)
{
  // usando tabela ASCII a meu favor
  int n = 65;
  while (n <= 80)
  {
    q->push(n);
    n++;
  }
  // q->push('A');
  // q->push('B');
  // q->push('C');
  // q->push('D');
  // q->push('E');
  // q->push('F');
  // q->push('G');
  // q->push('H');
  // q->push('I');
  // q->push('J');
  // q->push('K');
  // q->push('L');
  // q->push('M');
  // q->push('N');
  // q->push('O');
  // q->push('P');
}

char campeonato(queue<char> fila, vector<int> time1, vector<int> time2)
{
  int n = 0;
  while (fila.size() != 1)
  {
    if (n == 17)
      n == 0;
    if (time1[n] < time2[n])
    {
      fila.pop();
      char aux = fila.front();
      fila.pop();
      fila.push(aux);
    }
    else
    {
      char aux = fila.front();
      fila.pop();
      fila.pop();
      fila.push(aux);
    }

    n++;
  }
  return fila.front();
}
int main()
{
  queue<char> q;
  vector<int> time1(16), time2(16);
  setQueue(&q);
  for (int i = 0; i < 16; i++)
    cin >> time1[i] >> time2[i];
  char aux = campeonato(q, time1, time2);
  cout << aux << endl;
}