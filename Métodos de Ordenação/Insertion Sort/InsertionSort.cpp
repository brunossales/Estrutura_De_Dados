#include <iostream>
using namespace std;

const int MAX = 100000;
void insertion(int vetor[], int size)
{

    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j > 0; j--)
        {
            if (vetor[j] < vetor[j - 1])
            {
                int aux = vetor[j];
                vetor[j] = vetor[j - 1];
                vetor[j - 1] = aux;
            }
            else
                break;
        }
};

int main()
{
    int v[MAX];
    int size;
    cout << "Digite o tamanho do vetor" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Digite o valor da posicao - " << i << endl;
        cin >> v[i];
    }
    insertion(v, size);
    cout << endl
         << endl;
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << endl;
    }
}