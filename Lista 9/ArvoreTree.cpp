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
  Node *root;
  BTree()
  {
    this->root = nullptr;
  }

  void clone(stringstream &ss, Node **elo)
  {
    string value;
    ss >> value;
    if (value == "#")
      return;
    int num;
    stringstream(value) >> num;
    *elo = new Node(num);
    clone(ss, &(*elo)->left);
    clone(ss, &(*elo)->right);
  }

  BTree(string serial)
  {
    stringstream ss(serial);
    clone(ss, &root);
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

  string find_path(Node *node, int value)
  {
    if (node == nullptr)
    {
      return "!";
    }
    else if (node->value == value)
    {
      return "x";
    }
    else
    {
      string procurandoNaEsquerda = find_path(node->left, value);
      if (procurandoNaEsquerda.back() == 'x')
        return "l" + procurandoNaEsquerda;
      string procurandoNaDireita = find_path(node->right, value);
      if (procurandoNaDireita.back() == 'x')
        return "r" + procurandoNaDireita;
      return "!"
    }
  }
};

int main()
{
  string line;
  getline(cin, line);
  BTree bt(line);
  int value;
  cin >> value;
  string path = bt.find_path(bt.root, value);
  cout << path << endl;
}