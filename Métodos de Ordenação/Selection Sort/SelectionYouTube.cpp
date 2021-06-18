#include <iostream>
#include <utility>
using namespace std;

void selecao(int vet[], int n)
{
    int menor;
    for (int i = 0; i < n - 1; i++)
    {
        menor = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vet[menor] > vet[j])
                menor = j;
        }
        if (i != menor)
        {
            swap(vet[i], vet[menor]);
        }
    }
};
int main()
{
    int n = 10;
    int v[n] = {3, 6, 5, 1, 2, 8, 7, 9, 4, 10};
    selecao(v, n);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << endl;
    }

    system("pause");
}