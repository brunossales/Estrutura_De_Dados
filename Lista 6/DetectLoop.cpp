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
  int n, x;
  cin >> n >> x;
  ListNode *head;
  ListNode *tmp = nullptr;

  ListNode *ptr;

  for (int i = 1; i <= n; i++)
  {
    int v;
    cin >> v;
    if (i == 1)
    {
      head = new ListNode(v);
      ptr = head;
    }
    else
    {
      ptr->next = new ListNode(v, nullptr);
      ptr = ptr->next;
    }

    if (i == x)
    {
      tmp = ptr;
    }
  }

  ptr->next = tmp;
  return head;
}

bool detectLoop(ListNode *head)
{
  ListNode *fast = head;
  ListNode *slow = head;
  while (fast != nullptr && fast->next)
  {
    fast = fast->next->next;
    slow = slow->next;
    if (fast->val == slow->val)
      return 1;
  }
  return 0;
}

int main()
{

  ListNode *head = readList();

  cout << detectLoop(head) << endl;

  return 0;
}