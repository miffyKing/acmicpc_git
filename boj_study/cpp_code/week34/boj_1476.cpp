#include <iostream>

using namespace std;

int main()
{
  int e,s,m;
  int a,b,c;

  cin>>a>>b>>c;

  e = 1; s = 1; m = 1;
  int cnt = 1;
  while (1)
  {
    if(e == a && s == b && m == c)
    {
      cout<<cnt<<"\n";
      return 0;
    }
    e++;
    s++;
    m++;
    if (e > 15)
      e = 1;
    if (s >28)
      s = 1;
    if (m > 19)
      m = 1;
    cnt++;
  }
  return 0;
}