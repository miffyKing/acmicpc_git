#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  string a;
  cin>>a;
  if (a.length() == 2)
  {
    cout<< a[0]-'0' + a[1]-'0';
  } 
  else if (a.length() == 3)
  {
    if (a[1] == '0')
    {
      cout<< 10 + (a[2] - '0');
    }
    else 
    {
      cout<<10 + (a[0] - '0');
    }
  }
  else 
  {
    cout<<20;

  }
  return 0;
}