#include <iostream>
using namespace std;

class Student
{
private:
  int score[5];
  int sum{0};

public:
  int calculateTotalScore() { return sum; }
  void input()
  {
    for (int i = 0; i < 5; i++)
    {
      cin >> score[i];
      sum += score[i];
    }
  }
};

int main()
{
  int n, count{0};
  cin >> n;
  Student *stu = new Student[n];
  for (int i = 0; i < n; i++)
    stu[i].input();
  int pointKrintine = stu[0].calculateTotalScore();
  for (int i = 1; i < n; i++)
    if (stu[i].calculateTotalScore() > pointKrintine)
      count++;
  cout << count;
}