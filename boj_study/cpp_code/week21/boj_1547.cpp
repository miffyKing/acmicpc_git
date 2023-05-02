#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int ans = 1;
  for (int i = 0; i <n; i++)
  {
    int a,b;
    cin>>a>>b;
    if (ans == a)
    {
      ans = b;
    }  else if (ans == b)
    {
      ans  = a;
    } 

  }
  cout << ans;
  return 0;
}