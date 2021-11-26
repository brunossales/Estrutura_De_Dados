#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
  string name;
  int price;
  Product(string nome, int preco)
  {
    name = nome;
    price = preco;
  }
  bool operator<(const Product &a)
  {
    if (price != a.price)
      return price < a.price;
    else
      return name < a.name;
  }
  friend ostream &operator<<(ostream &, const Product &p);
};
ostream &operator<<(ostream &os, const Product &p)
{
  os << "(" << p.name << "," << p.price << ")";
  return os;
}
//ordenandoVector
void insertionSort(vector<Product> &vec, int pri, int ult)
{
  if (pri <= ult)
  {
    Product x = vec[pri];
    int i = pri - 1;
    while (i >= 0 && vec[i].price >= x.price)
    {
      vec[i + 1] = vec[i];
      i--;
    }
    assert(i < 0 || vec[i].price <= x.price);
    vec[i + 1] = x;
    insertionSort(vec, pri + 1, ult);
  }
};

void shercOne(vector<Product> &one, vector<Product> &exit, int p)
{
  int tam = one.size();
  insertionSort(one, 0, tam - 1);
  for (int i = 0; i < p; i++)
  {
    if (one[0].price != one[1].price)
    {
      exit.push_back(one[0]);
      one.erase(one.begin() + 0);
    }
    else
    {
      if (one[0] < one[1] == true)
      {
        exit.push_back(one[0]);
        one.erase(one.begin() + 0);
      }
      else
      {
        exit.push_back(one[1]);
        one.erase(one.begin() + 1);
      }
    }
  }
};
void shercTwo(vector<Product> &two, vector<Product> &exit, int q)
{
  int tam = two.size();
  insertionSort(two, 0, tam - 1);
  for (int i = 0; i < q; i++)
  {
    if (two[0].price != two[1].price)
    {
      exit.push_back(two[0]);
      two.erase(two.begin() + 0);
    }
    else
    {
      if (two[0] < two[1] == true)
      {
        exit.push_back(two[0]);
        two.erase(two.begin() + 0);
      }
      else
      {
        exit.push_back(two[1]);
        two.erase(two.begin() + 1);
      }
    }
  }
};
int main()
{
  int n, m, p, q;
  cin >> n >> m >> p >> q;
  vector<Product> oneSesion;
  vector<Product> twoSesion;
  vector<Product> exit;
  for (int i = 0; i < n; i++)
  {
    string value;
    int valuee;
    cin >> value >> valuee;
    Product c(value, valuee);
    oneSesion.push_back(c);
  }
  for (int i = 0; i < m; i++)
  {
    string value;
    int valuee;
    cin >> value >> valuee;
    Product c(value, valuee);
    twoSesion.push_back(c);
  }
  shercOne(oneSesion, exit, p);
  shercTwo(twoSesion, exit, q);
  insertionSort(exit, 0, exit.size() - 1);
  for (int i = 0; i < exit.size(); i++)
    if (exit[i] < exit[i + 1] == false && exit[i + 1].price == exit[i].price)
      swap(exit[i], exit[i + 1]);
  for (int i = 0; i < exit.size(); i++)
  {
    if (i == exit.size() - 1)
    {
      cout << exit[i].name << endl;
      break;
    }
    cout << exit[i].name << " ";
  }
}