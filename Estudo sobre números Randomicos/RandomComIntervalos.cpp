#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template <class num>
num numeroAleatorio(num menor, num maior)
{ // O intervalor do aleatorio: do minimo ao maximo
    return rand() % (maior - menor + 1) + menor;
}
int main()
{
    srand((unsigned)time(0));
    //posso gerar o unsigned assim, sem precisar igualar com uma varialvem como antes
    // unsigned são inteiros não assinados, ou seja, inteiros de 0 a +infinito, positivos.
    int aleatorio = numeroAleatorio(40, 100); //Criando um random do tipo int
    cout << aleatorio << endl;
    cout << "Agora vamos criar numeros aleatorios de 10 a 40 em 30 casos de testes" << endl
         << endl;
    for (int i = 0; i < 30; i++)
    {
        cout << numeroAleatorio(10, 40) << endl;
    }
    // todos deram certo
}