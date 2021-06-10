#include <iostream>
#include <string.h>
using namespace std;

class puzzle
{
private:
    quadrado *celulas[3][3];

public:
    puzzle()
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                this->celulas[i][j] = new quadrado();
    }
    ~puzzle();
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
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                this->numbers[i][j] = 0;
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
    if (strcmp(argc[1], "--criar") == 0)
    {
        int n;
        sscanf(args[2], "%d", &n);
    }

    return 0;
}