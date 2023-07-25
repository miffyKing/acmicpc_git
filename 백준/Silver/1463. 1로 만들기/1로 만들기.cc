#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int dp[1000002];

int min3(int a, int b, int c)
{
  if (a > b)
  {
    if (b > c)
      return c;
    return b;
  }
  else
  {
    if (a > c)
      return c;
    return a;
  }
}

int main()
{
  int n;
  cin>>n;

  int idx = 1;

  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;
  
  for (int i = 4; i <= n; i++)
  {
    if (i % 3 == 0 && i % 2 == 0)
    {
      dp[i] = min3(dp[i/3], dp[i/2], dp[i-1]) + 1;
    } else if (i % 3 == 0 && i % 2 != 0)
    {
      dp[i] = min(dp[i/3], dp[i-1]) + 1;
    } else if (i % 3 != 0 && i % 2 == 0)
    {
      dp[i] = min(dp[i/2], dp[i-1]) + 1;
    } else {
      dp[i] = dp[i-1] + 1;
    }
   // cout<<"dp " << i << " :  " << dp[i] <<"\n";
  }
  cout<<dp[n];

  return 0;
}