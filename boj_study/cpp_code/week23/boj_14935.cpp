#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

int main()
{

  int x;
  cin>>x;

  int idx = 0;
  while(idx<100000)
  {
    int prev = x;
    string len = to_string(x);
    x = len.length() * (x/pow(10,len.length()));
    if (prev == x)
    {
      cout<<"FA\n";
      return 0;
    }
    idx++;
  }
  cout<<"NFA\n";
  return 0;
}