#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int numeroAleatorio(int menor, int maior)
{
    return rand() % (maior - menor + 1) + menor;
};
void ajuda()
{
    cout << "O jogo acontece conforme o numero de chaves que voce escolheu no comeco" << endl;
    cout << "voce deve digitar jogar, para escolher uma chave aleatoria" << endl;
    cout << "Se a chave ligar voce ganha" << endl;
    cout << "Se nao ligar voce perde essa rodada, voce pode no maximo errar 3 vezes" << endl;
}
class Jogo
{
    int cha;

public:
    Jogo();
    Jogo(int a)
    {
        cha = a;
    }
};

int main()
{
    int chaves = 0;
    while (chaves < 5)
    {
        cout << "Digite o numero de chaves" << endl;
        cin >> chaves;
        if (chaves < 5)
            cout << "Tem que ser maior ou igual a 5";
    }
}