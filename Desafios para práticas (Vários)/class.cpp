#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Student
{
private:
  int age;
  string first_name;
  string last_name;
  int standard;

public:
  int get_age() { return age; }
  int get_standard() { return standard; }
  string get_first_name() { return first_name; }
  string get_last_name() { return last_name; }
  void set_age(int a) { this->age = a; }
  void set_first_name(string f) { this->first_name = f; }
  void set_last_name(string l) { this->last_name = l; }
  void set_standard(int a) { this->standard = a; }
  string to_string()
  {
    stringstream ss;
    ss << age << "," << first_name << "," << last_name << "," << standard;
    string newString;
    ss >> newString;
    return newString;
  }
};
int main()
{
  int age, standard;
  string first_name, last_name;

  cin >> age >> first_name >> last_name >> standard;

  Student st;
  st.set_age(age);
  st.set_standard(standard);
  st.set_first_name(first_name);
  st.set_last_name(last_name);

  cout << st.get_age() << "\n";
  cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
  cout << st.get_standard() << "\n";
  cout << "\n";
  cout << st.to_string();

  return 0;
}