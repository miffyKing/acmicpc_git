#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int s, k,h;
  cin>>s>>k>>h;

  if (s+k+h >= 100)
  {
    cout<<"OK\n";
    return 0;
  }
  else 
  {
    if (s <= k && s <= h)
    {
      cout<<"Soongsil\n";
      return 0;
    }
    else if (k <= s && k <= h)
    {
      cout<<"Korea\n";
      return 0;
    }
    else if (h <= s && h <= k)
    {
      cout<<"Hanyang\n";
      return 0;
    }
  }

  return 0;
}