// Sort = Ordenar, Merge = Juntar, unir
// Separar a nossa lista em varios dados menores, e depois unir eles ordenando-os.
#include <iostream>
using namespace std;

const int MAX = 100;
template <class var>
void merge(var lista[], var inicio, var meio, var fim)
{
    var aux[MAX];
    var esquerda = inicio;
    var direita = meio + 1;
    int index = inicio;
    while (esquerda <= meio && direita <= fim)
    {
        if (lista[esquerda] < lista[direita])
        {
            aux[index] = lista[esquerda];
            esquerda++;
            index++;
        }
        else
        {
            aux[index] = lista[direita];
            index++;
            direita++;
        }
    }
    while (esquerda <= meio)
    {
        aux[index] = lista[esquerda];
        index++;
        esquerda++;
    }
    while (direita <= fim)
    {
        aux[index] = lista[direita];
        direita++;
        index++;
    }
    for (int i = inicio; i < index; i++)
        lista[i] = aux[i];
};

template <class var>
void mergesort(var lista[], var inicio, var fim)
{
    int meio = (fim + inicio) / 2;
    if (inicio >= fim)
        return;
    mergesort(lista, inicio, meio);
    mergesort(lista, meio + 1, fim);
    merge(lista, inicio, meio, fim);
};

int main()
{
    int lista[MAX];
    int tamanho;
    cout << "Vamos implementar o Merge Sort" << endl
         << "Digite a quantidade de numeros que quer inserir: ";
    cin >> tamanho;
    if (tamanho < 0)
        throw "Digita um numero positivo bicho burro";

    cout << "Agora digite os valores em qualquer ordem: " << endl;
    for (int i = 0; i < tamanho; i++)
        cin >> lista[i];
    cout << endl
         << "Vetor nao ordenado: " << endl;
    for (int i = 0; i < tamanho; i++)
        cout << lista[i] << " ";
    cout << endl
         << "Vetor ordenado: " << endl;
    mergesort(lista, 0, tamanho - 1);
    for (int i = 0; i < tamanho; i++)
        cout << lista[i] << " ";
}
