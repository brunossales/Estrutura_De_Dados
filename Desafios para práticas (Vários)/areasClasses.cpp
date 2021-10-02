#include <iostream>
using std::cin;
using std::cout;

class Rectangle
{
public:
  void display()
  {
    cout << width << " " << height << "\n";
  }

protected:
  int height;
  int width;
};

class RectangleArea : public Rectangle
{
public:
  void read_input()
  {
    cin >> width >> height;
  }
  void display()
  {
    cout << width * height << "\n";
  }
};

int main()
{
  RectangleArea area;
  area.read_input();
  area.Rectangle ::display();
  area.display();
}
