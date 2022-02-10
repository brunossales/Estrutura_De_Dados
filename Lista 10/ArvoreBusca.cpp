#include <iostream>
#include <vector>
#include <iomanip> // std::setw
#include <climits>

using namespace std;

template <typename T>
class NodeTree
{
public:
  T key;
  int size;
  NodeTree<T> *left;
  NodeTree<T> *right;
  NodeTree(T key) : key(key), left(nullptr), right(nullptr){};
  NodeTree(T key, NodeTree *l, NodeTree *r) : key(key), left(l), right(r){};
};

template <typename T>
NodeTree<T> *createTree(vector<T> keys, vector<int> parent)
{

  NodeTree<T> *tree[keys.size()];
  NodeTree<T> *root;

  for (int i = 0; i < keys.size(); i++)
  {
    tree[i] = new NodeTree<T>(keys[i]);
  }

  for (int i = 0; i < keys.size(); i++)
  {

    if (parent[i] == -1)
      root = tree[i];
    else
    {
      NodeTree<T> *ptr = tree[parent[i]];

      if (ptr->left)
      {
        ptr->right = tree[i];
      }
      else
      {
        ptr->left = tree[i];
      }
    }
  }

  return root;
}

// Menor da esquerda
template <typename T>
T getMin(NodeTree<T> *root)
{
  auto aux = root;
  while (aux->left != nullptr)
    aux = aux->left;
  return aux->key;
}

// Maior, que ta na direta
template <typename T>
T getMax(NodeTree<T> *root)
{
  auto aux = root;
  while (aux->right != nullptr)
    aux = aux->right;
  return aux->key;
}

// Utilize essa função auxiliar
template <typename T>
bool isBSTAux(NodeTree<T> *root)
{
  if (root == nullptr)
    return true;

  int minEsquerda = getMin(root);
  int maxDireta = getMax(root);

  if (minEsquerda > root->key || maxDireta < root->key)
    return false;

  if (isBSTAux(root->left) && isBSTAux(root->right))
    return true;

  return false;
}

template <typename T>
bool isBST(NodeTree<T> *root)
{
  return isBSTAux(root);
}

int main()
{
  int n;
  vector<int> keys;
  vector<int> parent;

  cin >> n;

  keys.resize(n);
  parent.resize(n);

  for (int i = 0; i < n; i++)
    cin >> keys[i];

  for (int i = 0; i < n; i++)
    cin >> parent[i];

  NodeTree<int> *root = createTree(keys, parent);

  string res = isBST(root) ? "Yes" : "No";

  cout << res << endl;
}