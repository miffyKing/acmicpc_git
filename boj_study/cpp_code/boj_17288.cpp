#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
  string a;
  cin>>a;
  int cnt = 0;
  for (int i = 0; i < a.length(); i++)
  {
    if(a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2])
    {
      if(a[i+2] +1 == a[i+3])
      {
        i+=1;
        continue;
      }
      else
      {
        cnt++;
      }
    }
  }
  cout<<cnt;
  return 0;
}