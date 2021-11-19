#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int> &vec, int rot)
{

  for (int i = 0; i < rot; i++)
  {
    int aux = vec[vec.size() - 1];
    for (int j = vec.size() - 1; j >= 0; j--)
    {
      if (j == 0)
      {
        vec[0] = aux;
        break;
      }
      vec[j] = vec[j - 1];
    }
  }
};
void view(vector<int> vec)
{
  cout << "[ ";
  for (int i = 0; i < vec.size(); i++)
    cout << vec[i] << " ";
  cout << "]";
}
int main()
{
  int tam, rot;
  cin >> tam >> rot;
  vector<int> vec;
  vec.resize(tam);
  for (int i = 0; i < tam; i++)
    cin >> vec[i];
  rot %= tam;
  rotate(vec, rot);
  view(vec);
}