#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

void dp_func(int from, int to, char str[])
{
  //cout<<"len is    " << to - from<< "from : " << from << "   to : " << to<<  "\n";
  if (to - from == 1 )
    return;
  for (int i = from + (to-from)/3; i < from + ((to-from)/3)*2; i++)
  {
    str[i] = ' ';
  }
  dp_func(from, from + (to-from)/3 , str);
  dp_func( from + 2*((to-from)/3)  , to, str);
}

int main()
{
  int n;

  while(scanf("%d", &n) != EOF)
  {
    

    int len = pow(3,n);
    char str[600000];
    for(int i = 0; i < len; i++)
    {
      str[i] = '-';
    }
    dp_func(0, len, str);
    for(int i = 0; i <len ;i++)
    {
      cout<<str[i];
    }
    cout<<"\n";

  }
  return 0;
}