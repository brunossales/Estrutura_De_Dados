#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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
  vector<string> exit;
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

  find_path(Node *node, int value)
  {
    if (node == nullptr)
    {
      return;
    }
    else if (node->value == value)
    {
      exit.push_back("x");
      return exit;
    }
    else
    {
      exit.push_back("l");
      return find_path(node->left, value);
      exit.pop_back();
      exit.push_back("r");
      return find_path(node->right, value);
      exit.pop_back();
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
  vector<string> path = bt.find_path(bt.root, value);
  for (int i = 0; i < path.size(); i++)
    cout << path[i];
}