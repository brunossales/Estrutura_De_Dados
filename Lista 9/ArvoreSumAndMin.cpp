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
  int summ{0};
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

  int soma(Node *node)
  {
    if (node == nullptr)
      return 0;
    summ = node->value + soma(node->left) + soma(node->right);
    return summ;
  }

  int minimo(Node *node)
  {
    if (node == nullptr)
      return 0;
    int mini = node->value;
    if (node->left != nullptr)
    {
      mini = min(minimo(node->left), mini);
      // Assim não rodava
      // if (mini > minimo(node->left->value))
      //   mini = node->left->value;
    }
    if (node->right != nullptr)
    {
      mini = min(minimo(node->right), mini);
      //  Assim não rodava
      // if (mini > minimo(node->right->value))
      //   mini = node->right->value;
    }

    return mini;
  }
  int sum()
  {
    return soma(this->root);
  }

  int menor()
  {
    return minimo(this->root);
  }
};

int main()
{
  string line;
  getline(cin, line);
  BTree bt(line);
  getline(cin, line);
  cout << bt.sum() << " " << bt.menor() << "\n";
}