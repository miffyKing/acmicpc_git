#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  if (a+b+c != 180)
  {
    cout<<"Error\n";
    return 0;
  }
  if (a == 60 && b == 60 && c == 60)
  {
    cout<<"Equilateral\n";
    return 0;
  }
  if (a != b && b != c && a != c)
  {
    cout<<"Scalene\n";
    return 0;
  }
  cout<<"Isosceles\n";
  return 0;

}