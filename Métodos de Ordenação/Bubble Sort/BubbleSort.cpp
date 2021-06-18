#include <iostream>
#include <utility>

using namespace std;

const int Max = 100;

void bubblesort(int vet[], int size)
{
    for (int teto = size - 1; teto >= 1; teto--)
        for (int u = 1; u <= teto; u++)
        {
            if (vet[u] <= vet[u - 1])
            {
                swap(vet[u], vet[u - 1]);
            }
        }
};
int main()
{
    int vet[Max];
    int op;
    cout << "Digite O tamanho do vetor: ";
    cin >> op;
    for (int i = 0; i <= op - 1; i++)
    {
        cout << "Digite o vetor de posicao " << i << " : " << endl;
        cin >> vet[i];
    }
    cout << "Agora os valores ordenados" << endl;
    bubblesort(vet, op);
    for (int i = 0; i < op; i++)
    {
        cout << vet[i] << endl;
    }

    return 0;
}