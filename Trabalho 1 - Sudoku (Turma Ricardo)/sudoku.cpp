#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int pegaproximo(int possiveis[])
{
    int temApenaszeros = 1;
    for (int i = 0; i < 9; i++)
    {
        if (possiveis[i])
            temApenaszeros = 0;
    }
    if (temApenaszeros)
        return 0;
    srand(unsigned(time(0)));
    int valor = 0;
    while (true)
    {
        int i = rand() % 9;
        valor = possiveis[i];
        if (valor)
        {
            possiveis[i] = 0;
            break;
        }
    }
    return valor;
};
class sudokuu
{
private:
public:
    quadrado *celulas[3][3];
    sudokuu()
    {

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                this->celulas[i][j] = new quadrado();
    }
    ~sudokuu();
    bool valida()
    {
        bool achou = true;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                achou = achou && (this->celulas[i][j]->valida());
        return achou;
    }
};

class quadrado
{
private:
    int numbers[3][3];

public:
    quadrado()
    {
        int numeross[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                this->numbers[i][j] = pegaproximo(numeross);
    }
    ~quadrado();
    // verificar se o quadrado é valido
    bool valida()
    {
        for (int h = 1; h <= 9; h++)
        {
            bool achou = false;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                {
                    if (this->numbers[i][j] == h)
                        achou = true;
                }
            if (!achou)
                return false;
        }
        return true;
    }
};
int main(int argc, char *args[]) //argc é a contagem de nomes que vamos ter na nossa entrada
{                                // *args é o proprio valor que digitamos, lembrando que o ./sudoku.exe é a posição 0
    if (strcmp(args[1], "--criar") == 0)
    {
        int n;
        sscanf(args[2], "%d", &n);
        sudokuu *sud = new sudokuu();
        cout << *(sud->celulas);
    }

    return 0;
}