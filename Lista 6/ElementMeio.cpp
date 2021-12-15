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

ListNode *readList()
{
  int n;
  cin >> n;
  ListNode *head;
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

  return head;
}

int sizeList(ListNode *head)
{

  if (head == nullptr)
    return 0;
  else
    return 1 + sizeList(head->next);
}

int getMiddle(ListNode *head)
{
  int meio = sizeList(head) / 2;
  int contador = 0;
  for (auto i = head; i != nullptr; i = i->next)
  {
    if (contador == meio)
      return i->val;
    contador++;
  }
}

int main()
{

  ListNode *head = readList();

  cout << getMiddle(head) << endl;

  return 0;
}