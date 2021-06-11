#include <iostream>
using namespace std;

// Outra forma de fazer o insertion sort
template <class t>
void insertionsort(t v[], int n)
{
    for (int i = 1; i < n; i++)
    {
        t card = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > card)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = card;
    }
};

int main()
{
    int vector[10] = {2, 5, 7, 1, 7, 6, 8, 10, 2, 300};
    insertionsort(vector, 10);
    for (int i = 0; i < 10; i++)
        cout << vector[i] << endl;
}