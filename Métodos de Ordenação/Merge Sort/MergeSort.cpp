// Sort = Ordenar, Merge = Juntar, unir
// Separar a nossa lista em varios dados menores, e depois unir eles ordenando-os.
#include <iostream>
using namespace std;

template <class var>
void merge(var inicio, var meio, var fim){

};

template <class var>
void mergesort(var lista[], var inicio, var fim)
{
    if (fim - inicio > 1)
    {
        int meio = (fim + inicio) / 2;
        mergesort(lista, inicio, meio);
        mergesort(lista, meio, final);
        merge(lista, inicio, meio, fim);
    }
};
