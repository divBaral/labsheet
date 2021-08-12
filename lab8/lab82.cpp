/*Write a program to create a user-defined manipulator that will format the output by setting the width, precision, and fill character at the same time by passing arguments.*/

#include <iostream>
#include <iomanip>
 using namespace std;

class Formater
{

 public:
  Formater(int w, int p , char f)
  :width(w),precision(p),fill(f){}

  friend ostream& operator<<(ostream&, Formater);
private:
  int width; 
  int precision;
  char fill;
};

ostream& operator<<(ostream& s, Formater p)
{
  s << setw(p.width) << setfill(p.fill) << setprecision(p.precision);
  return s;
}

Formater format(int w, int p, char f)
{
  return Formater(w, p, f);
}

int main()
{

  cout << format(7, 5, '-') << 14.0010 ;
  cout << endl;
  return 0;
}