#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long long dp[10002];
int main()
{
  int n;
  int podo[10002];

  cin>>n;
  for (int i = 1; i <= n; i++)
  {
    cin>>podo[i];
  }
  dp[0] = 0;
  dp[1] = podo[1];
  dp[2] = podo[2] + podo[1];

  for (int i = 3; i <= n; i++)
  {
    dp[i] = max(dp[i-3] + podo[i-1] + podo[i], dp[i-2] + podo[i]);
    dp[i] = max(dp[i], dp[i-1]);
  }

  cout<<dp[n];
  return 0;
}