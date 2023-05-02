#include <iostream>

using namespace std;

int main()
{
  int first = 120 - (9+12+8);
  int a,b,c;
  cin>>a>>b>>c;
  cout<< "The 1-3-sum is " << first + (a*1 + b*3 + c*1);
  return 0;
}