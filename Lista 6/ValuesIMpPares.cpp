#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head)
{
  int contador = 1;
  ListNode *aux = nullptr;
  ListNode *auxptr;

  // Lado impar
  for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
  {
    if (contador == 1)
    {
      aux = new ListNode(ptr->val);
      auxptr = aux;
    }
    else if (contador % 2 != 0)
    {
      auxptr->next = new ListNode(ptr->val, nullptr);
      auxptr = auxptr->next;
    }
    contador++;
  }
  contador = 1;
  // Lado Par
  for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
  {
    if (contador % 2 == 0)
    {
      auxptr->next = new ListNode(ptr->val, nullptr);
      auxptr = auxptr->next;
    }
    contador++;
  }
  return aux;
}

int main()
{
  int n;
  ListNode *head = nullptr;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    ListNode *ptr;
    int x;
    cin >> x;
    if (i == 0)
    {
      head = new ListNode(x);
      ptr = head;
    }
    else
    {
      ptr->next = new ListNode(x, nullptr);
      ptr = ptr->next;
    }
  }

  head = oddEvenList(head);

  for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
    cout << ptr->val << endl;

  return 0;
}