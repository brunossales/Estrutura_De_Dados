#include <iostream>
#include <sstream>
using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;
  Node(int value = 0, Node *left = nullptr, Node *right = nullptr)
  {
    this->value = value;
    this->left = left;
    this->right = right;
  }
};

struct BTree
{
  Node *root{nullptr};
  BTree()
  {
  }

  void monta(stringstream &ss, Node *raiz[])
  {
    string value;
    ss >> value;
    if (value == "#")
      return;
    int num;
    stringstream(value) >> num;
    *raiz = new Node(num);
    monta(ss, &(*raiz)->left);
    monta(ss, &(*raiz)->right);
  }

  BTree(string serial)
  {
    stringstream ss(serial);
    monta(ss, &root);
  }

  Node *findAux(Node *node, int valur)
  {
    if (node == nullptr)
      return nullptr;
    if (node->value == valur)
      return node;
    // Vamos começar percorrendo pela esquerda a procura
    Node *valueEsquerda = findAux(node->left, valur);
    // quando a arvore da esquerda acabar, a variavel sera nullptr e não entrará no if
    // aqui é o break para passar para a arvore da direita
    if (valueEsquerda != nullptr)
      return valueEsquerda;

    return findAux(node->right, valur);
  }

  int altura(Node *node)
  {
    // Quando chegar no final de cada arvore vai começar com 0
    // Depois vai incrementando até chegar no topo da arvore
    // E pega o máximo entre os valores incrementos da arvore da esquerda e da direita
    // O que tiver o valor mais alto é a altura
    if (node == nullptr)
      return 0;
    int alturaMaxima = max(altura(node->left), altura(node->right));
    return alturaMaxima + 1;
  }

  int getProfundidade(Node *node, int nivel, int value)
  {
    // mesma logica do find
    if (node == nullptr)
      return 0;
    if (node->value == value)
      return nivel;
    int nivelEsquerda = getProfundidade(node->left, nivel + 1, value);
    // quando a arvore da esquerda acabar, a variavel sera 0 e não entrará no if
    // aqui é o break para passar para a arvore da direita
    if (nivelEsquerda != 0)
      return nivelEsquerda;
    return getProfundidade(node->right, nivel + 1, value);
  }

  int profundidade(int value)
  {
    return getProfundidade(this->root, 1, value);
  }

  Node *find(int value)
  {
    return findAux(this->root, value);
  }
};

int main()
{
  string line;
  getline(cin, line);
  BTree bt(line);
  getline(cin, line);
  stringstream ss(line);
  int value;
  while (ss >> value)
  { // enquanto houver elementos no buffer
    Node *node = bt.find(value);
    if (node != nullptr)
      cout << bt.altura(node) << " " << bt.profundidade(value) << "\n";
    else
      cout << "-1\n";
  }
}