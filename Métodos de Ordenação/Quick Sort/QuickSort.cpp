// Escolher um elemento, o pivô, e passar para a direita todos que sao maiores do que ele
// A esquerda todos que são menores do que ele
// Até ter essa propriedade para todos

#include <iostream>
using namespace std;

const int MAX = 10000;
int partition(int lista[], int inicio, int fim)
{
    int pivo = lista[fim];
    int index = inicio;
    for (int j = inicio; j < fim; j++)
    {
        if (lista[j] <= pivo)
        {
            int aux = lista[j];
            lista[j] = lista[index];
            lista[index] = aux;
            index++;
        }
    }
    int aux = lista[index];
    lista[index] = lista[fim];
    lista[fim] = aux;
    return index;
};

void quickSort(int lista[], int inicio, int fim)
{
    int pivo;
    if (inicio < fim)
    {
        pivo = partition(lista, inicio, fim);
        quickSort(lista, inicio, pivo - 1);
        quickSort(lista, pivo + 1, fim);
    }
};

int main()
{
    int vetor[MAX];
    int numbers;
    cout << "Vamos implementar o Quick-Sort" << endl
         << "Digite a quantidade de numeros que quer inserir: " << endl;
    cin >> numbers;
    cout << "Agora digite eles em forma aleatoria" << endl
         << endl;
    for (int i = 0; i < numbers; i++)
        cin >> vetor[i];
    cout << endl
         << "Vetor nao ordenado: " << endl;
    for (int i = 0; i < numbers; i++)
        cout << vetor[i] << " ";

    quickSort(vetor, 0, numbers - 1);
    cout << endl
         << "Vetor ordenado" << endl;
    for (int i = 0; i < numbers; i++)
        cout << vetor[i] << " ";

    return 0;
}