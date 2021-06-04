#include <iostream>
using namespace std;

template <class t>
class mat
{
    t *data;
    int nc, nl;

public:
    mat(int nl, int nc)
    {
        this->nc = nc;
        this->nl = nl;
        data = new t[nc * nl];
    }
    t &operator()(int l, int c)
    {
        return data[l * c + c];
        // m é o numero de linhas
        // n é numero de colunas
        // Int p é a posição real dentro de data, que corresponde a posição ij dentro da matriz abstrata
    }
    int getData(int l, int c)
    {
        int p = l * c + c;
        return *(data + p);
    }
    ~mat()
    {
        delete[] data;
    }
};

int main()
{
    mat<int> x(2, 2);
    x(0, 0) = 50;
    x(0, 1) = 40;
    x(1, 0) = 4;
    x(1, 1) = 5;

    cout << x.getData(0, 0) << endl;
    cout << x.getData(1, 1) << endl;
    cout << x.getData(1, 0) << endl;
    cout << x.getData(1, 1) << endl;
}