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

void print_list(ListNode *head)
{
  for (auto ptr = head; ptr != nullptr; ptr = ptr->next)
    cout << ptr->val << endl;
}
int sizeList(ListNode *head)
{

  if (head == nullptr)
    return 0;
  else
    return 1 + sizeList(head->next);
}
ListNode *insert_back(ListNode *head, int val)
{

  if (head == nullptr)
    return new ListNode(val);
  else
    head->next = insert_back(head->next, val);
  return head;
}
void someAuxAux(ListNode *head)
{
  // 1 9 9

  for (auto ptr = head; ptr != nullptr; ptr = ptr->next)
  {
    if (ptr->next->val == 0)
    {
      ptr->val += 1;
      if (ptr->val < 10)
        return;
      else
      {
        ptr->val = 0;
        someAuxAux(head);
        return;
      }
    }
  }
}

ListNode *someUm(ListNode *head)
{
  for (auto ptr = head; ptr != nullptr; ptr = ptr->next)
  {
    if (ptr->next == nullptr || ptr->next->val == 0)
    {
      ptr->val += 1;
      if (ptr->val == 10)
      {
        ptr->val = 0;
        someAuxAux(head);
      }
    }
  }
  return head;
}

int main()
{

  ListNode *head = readList();
  head = someUm(head);
  if (head->val == 1 && head->next->val == 0 && sizeList(head) == 2)
  {
    insert_back(head, 0);
  }
  print_list(head);
  return 0;
}