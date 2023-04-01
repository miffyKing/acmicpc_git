#include <iostream>

using namespace std;

int main()
{
  int a, b;
  int c;
  cin>>a>>b;
  cin>>c;

  if (a+b >= c*2)
  {
    cout<< (a+b) - (c*2);
  } else 
  {
    cout <<a +b;
  }
  return 0;
}