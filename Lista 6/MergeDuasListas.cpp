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
  int menor;
  // 1 2
  // 2 1
  while (l1 != nullptr || l2 != nullptr)
  {
    ListNode *ptr;
    int menor = l1->valor <= l2->valor ? l1->valor : l2->valor;
    int maior = l1->valor >= l2->valor ? l1->valor : l2->valor;
    if (aux == nullptr)
    {
      aux = new ListNode(menor);
      ptr = aux;
      ptr->proximo = new ListNode(maior, nullptr);
      ptr = ptr->proximo;
    }
    else if (l1 == nullptr && l2 != nullptr)
    {
      ptr->proximo = new ListNode(l2->valor, nullptr);
      ptr = ptr->proximo;
    }
    else if (l1 != nullptr && l2 == nullptr)
    {
      ptr->proximo = new ListNode(l1->valor, nullptr);
      ptr = ptr->proximo;
    }
    else
    {
      ptr->proximo = new ListNode(menor, nullptr);
      ptr = ptr->proximo;
      ptr->proximo = new ListNode(maior, nullptr);
      ptr = ptr->proximo;
    }

    l1 = l1->proximo;
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
