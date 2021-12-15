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
bool hasElement(ListNode *head, int x)
{
  if (head == nullptr)
    return false;
  else if (head->val == x)
    return true;
  else
    return hasElement(head->next, x);
}

ListNode *intersectionList(ListNode *head1, ListNode *head2)
{
  ListNode *aux = nullptr;
  for (ListNode *ptr = head1; ptr != nullptr; ptr = ptr->next)
  {
    ListNode *ponteiro;
    for (ListNode *j = head2; j != nullptr; j = j->next)
    {
      if (hasElement(head2, ptr->val))
      {
        if (aux == nullptr)
        {
          aux = new ListNode(ptr->val);
          ponteiro = aux;
        }
        else
        {
          if (!hasElement(aux, ptr->val))
          {
            ponteiro->next = new ListNode(ptr->val, nullptr);
            ponteiro = ponteiro->next;
          }
        }
      }
    }
  }
  return aux;
}

void printList(ListNode *head)
{
  for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
    cout << ptr->val << endl;
}

int main()
{

  ListNode *head1 = readList();
  ListNode *head2 = readList();

  ListNode *res = intersectionList(head1, head2);

  printList(res);

  return 0;
}
