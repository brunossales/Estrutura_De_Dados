#include <iostream>
using std::cin;
using std::cout;

void update(int *a, int *b)
{
  int aux = (*b) - (*a);
  (*a) = (*a) + (*b);
  (*b) = (aux < 0 ? aux * -1 : aux);
}

int main()
{
  int a, b;
  int *pa = &a, *pb = &b;
  scanf("%d %d", &a, &b);
  update(pa, pb);
  printf("%d\n%d", a, b);

  return 0;
}