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

  void __destroy(Node *node)
  {
    if (node == nullptr)
      return;
    __destroy(node->left);
    __destroy(node->right);
    delete node;
  }

  ~BTree()
  {
    __destroy(this->root);
  }

  void view(Node *node, int nivel)
  {
    if (node == nullptr)
    {
      for (int i = 0; i < nivel; i++)
        cout << "....";
      cout << "#\n";
      return;
    }

    // percorendo a arvore esquerda e subindo os niveis
    if (node->left != nullptr || node->right != nullptr)
      view(node->left, nivel + 1);

    // Printando
    for (int i = 0; i < nivel; i++)
      cout << "....";
    cout << node->value << "\n";

    // percorendo a arvore direita e subindo os niveis
    if (node->left != nullptr || node->right != nullptr)
      view(node->right, nivel + 1);
  }

  void vieww()
  {
    view(root, 0);
  }
};

int main()
{
  string line;
  getline(cin, line);
  BTree bt(line);
  bt.vieww();
}