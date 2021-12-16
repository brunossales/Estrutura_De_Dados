#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode
{
public:
  int valor;
  ListNode *proximo;

  ListNode() : valor(0), proximo(nullptr) {}
  ListNode(int x) : valor(x), proximo(nullptr) {}
  ListNode(int x, ListNode *next) : valor(x), proximo(next) {}
};
ListNode *insert_back(ListNode *head, int val)
{

  if (head == nullptr)
    return new ListNode(val);
  else
    head->proximo = insert_back(head->proximo, val);
  return head;
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{

  ListNode *aux = nullptr;
  ListNode *ptr;
  if (l1->valor > l2->valor || l1->valor == nullptr)
  {
    aux = new ListNode(l2->valor);
    ptr = aux;
    l2 = l2->proximo;
  }
  else
  {
    aux = new ListNode(l1->valor);
    ptr = aux;
    l1 = l1->proximo;
  }
  while (l1 != nullptr && l2 != nullptr)
  {
    if (l2->valor < l1->valor)
    {
      insert_back(aux, l2->valor);
      l2 = l2->proximo;
    }
    else
    {
      insert_back(aux, l1->valor);
      l1 = l1->proximo;
    }
  }
  while (l1 != nullptr)
  {
    insert_back(aux, l1->valor);
    l1 = l1->proximo;
  }
  while (l2 != nullptr)
  {
    insert_back(aux, l2->valor);
    l2 = l2->proximo;
  }
  return aux;
}
ListNode *readList()
{
  int n;
  cin >> n;
  ListNode *cabeca = nullptr;
  for (int i = 0; i < n; i++)
  {
    ListNode *ponteiro;
    int x;
    cin >> x;
    if (i == 0)
    {
      cabeca = new ListNode(x);
      ponteiro = cabeca;
    }
    else
    {
      ponteiro->proximo = new ListNode(x, nullptr);
      ponteiro = ponteiro->proximo;
    }
  }
  return cabeca;
}

int main()
{
  ListNode *lista1 = readList();
  ListNode *lista2 = readList();
  ListNode *head = mergeTwoLists(lista1, lista2);
  for (auto *pont = head; pont != nullptr; pont = pont->proximo)
    cout << pont->valor << endl;

  return 0;
}
