#include <iostream>
using namespace std;
// Implementar um programa que utilize sobrecarda dos operadores
class Caixa
{
private:
    double comprimento;
    double largura;
    double altura;

public:
    Caixa();
    Caixa(double c, double l, double a)
    {
        comprimento = c;
        largura = l;
        altura = a;
    }
    double volume()
    {
        double v = comprimento * largura * altura;
        return v;
    }

    bool operator>(Caixa &obj)
    {
        if (this->volume() >= obj.volume())
        {
            return true;
        }
        else
            return false;
    }
    void operator=(Caixa &obj)
    {
        if (this->volume() == obj.volume())
        {
            cout << "As caixas tem o mesmo volume" << endl;
        }
        else
            cout << "As caixas tem volumes diferentes" << endl;
    }
};

int main()
{
    double a, b;
    Caixa c1(1, 2, 3); // Criando o objeto
    Caixa c2(1, 1, 3);
    a = c1.volume();
    b = c2.volume(); //como ainda não podemos comparar o c1 com c2 porque são objetos, temos que armazenar o valor de volume em "a" e em "b"
    // if(c1>c2){
    //     ...              O nosso programa não sabe comparar dois objetos,
    // }                    para ele conseguir temos que fazer uma sobrecarga do operador

    // Agora que fizemos o operator lá em cima, o nosso programa reconhece o operador ">" e vai comparar como pedimos

    if (c1 > c2)
        cout << "A caixa c1 e maior" << endl;

    if (a > b) //Como fariamos sem o operador
        cout << "A caixa c1 e maior" << endl;

    else
        cout << "A caixa c2 e maior" << endl;

    c1 = c2; //só isso já chama o nosso operador e faz o que pedimos
}