#include <iostream>
#include <ctime>
#include <cstdlib> //Biblioteca para criar o rand

using namespace std;

int main()
{
    unsigned seed = time(0);     // Gera um número da contagrem de segundos desde o ano por volta de 1970
    cout << RAND_MAX;            // Para o número sempre ser um diferente, precisamos semear com algum número aleatorio sempre, por isso a linha de codigo a cima
    srand(seed);                 // Estamos semeando o rand com um valor que sempre será diferente, a contagem de segundos
    int aleatorio = rand() % 10; //Gerando esse aleatorio de 0 a 9
}