#include <iostream>
#include <sstream>
using namespace std;

class NodeTree
{
public:
  int value;
  NodeTree *left;
  NodeTree *right;
  NodeTree(int valor)
  {
    value = valor;
    left = nullptr;
    right = nullptr;
  }
};

NodeTree *createNode(NodeTree *root, int key)
{
  if (root == nullptr)
    return new NodeTree(key);

  // Como é arvore binária, os menores ficam para a esquerda
  // E os maiores para a direita

  if (key < root->value)
    root->left = createNode(root->left, key);

  else if (key > root->value)
    root->right = createNode(root->right, key);

  return root;
}

NodeTree *kesimo(NodeTree *root, int &k)
{
  if (root == nullptr)
    return nullptr;

  NodeTree *rootEsquerda = kesimo(root->left, k);

  if (rootEsquerda != nullptr)
    return rootEsquerda;

  k--;

  if (k == 0)
    return root;

  return kesimo(root->right, k);
}

int main()
{
  NodeTree *root = nullptr;
  int tam, valor, k;
  string valores;
  cin >> tam >> k;
  for (int i = 0; i < tam; i++)
  {
    cin >> valor;
    valores.push_back(valor);
  }

  for (int i = 0; i < valores.size(); i++)
    root = createNode(root, valores[i]);

  NodeTree *kes = kesimo(root, k);
  int saida = kes->value;
  cout << saida << endl;
}