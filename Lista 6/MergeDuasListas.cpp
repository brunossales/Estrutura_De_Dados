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
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
  //  if (l1 == nullptr && l2 == nullptr)
  //    return nullptr;
  //  if (l1 == nullptr && l2 != nullptr)
  //    return mergeTwoLists(l1, l2->proximo);
  //  if (l2 == nullptr && l1 != nullptr)
  //    return mergeTwoLists(l1->proximo, l2);
  //  else {
  //    if(l1->valor <= l2->valor){
  //     auto aux =
  //    }
  //  }

  ListNode *aux = nullptr;
  aux = new ListNode(2);
  ListNode *auxptr = aux;
  int menor;
  for (ListNode *i = l1; i != nullptr; i = l1->proximo)
  {
    menor = i->valor;
    for (ListNode *j = l2; j != nullptr; j = l2->proximo)
    {
      if (menor > j->valor)
        menor = j->valor;
    }
    auxptr->proximo = new ListNode(menor, nullptr);
    auxptr = auxptr->proximo;
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
  for (ListNode *pont = head; pont != nullptr; pont->proximo)
    cout << pont->valor << endl;

  return 0;
}
