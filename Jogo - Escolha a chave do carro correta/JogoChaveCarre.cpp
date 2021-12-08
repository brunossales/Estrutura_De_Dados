#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int numeroAleatorio(int menor, int maior)
{
    return rand() % (maior - menor + 1) + menor;
};

class Jogo
{
    int cha;

public:
    int vezes = 0;
    Jogo();
    Jogo(int a)
    {
        cha = a;
    }

    void ajuda()
    {
        cout << "# O jogo acontece conforme o numero de chaves que voce escolheu no comeco" << endl;
        cout << "# voce deve digitar 1, para escolher uma chave aleatoria" << endl;
        cout << "# Se a chave ligar voce ganha" << endl;
        cout << "# Se nao ligar voce perde essa rodada, voce pode no maximo errar 3 vezes" << endl
             << endl;
    };

    bool jogar()
    {
        srand((unsigned)time(0));
        int chaveCerta = numeroAleatorio(1, this->cha);
        if (numeroAleatorio(1, this->cha) == chaveCerta)
        {
            cout << "Ganhouuu!!!!! " << endl;
            cout << "---------------" << endl
                 << "Um carro zero!!!!!";
            return true;
        }
        else
        {
            this->vezes += 1;
            if (this->vezes > 3)
            {
                cout << "Ja perdeu as 3 vezes que podia " << endl;
                cout << "------------------------------" << endl;
                cout << "Perdeu no jogo, volte amanha" << endl;
                return false;
            }
            cout << "Perdeu, ja e a " << this->vezes << " Vez que perde, lembre que so pode 3 vezes" << endl;
            return false;
        }
    };
};

int main()
{
    int chaves = 0;

    while (chaves < 5)
    {
        cout << "Digite o numero de chaves" << endl;
        cin >> chaves;
        if (chaves < 5)
            cout << "Tem que ser maior ou igual a 5!\n";
    }
    Jogo *jogo = new Jogo(chaves);
    while (true)
    {
        int op;
        cout << "Digite alguma opcao que deseja" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1 -- para jogar o jogo das chaves " << endl;
        cout << "2 -- para ver como acontece o jogo" << endl;
        cin >> op;
        if (op == 1)
        {
            bool jogoo = jogo->jogar();
            if (jogoo == true)
                break;

            if (jogo->vezes > 3)
            {
                cout << endl
                     << "Encerrando...";
                break;
            }
        }
        else
        {
            jogo->ajuda();
        }
    }
}