#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
  int a,b;
  int c,d;
  cin>>a>>b;
  cin>>c>>d;
  if (a+d > b+c)
  {
    cout<<b+c;
  } else 
  {
    cout<<a+d;
  }

  return 0;
}