#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int dp[100002];

  dp[0] = 0;
  dp[1] = 1;


  int n;
  cin>>n;
  for (int i = 0; i <= n; i++)
  {
    dp[i] = i;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j*j <= i; j++)
    {
      dp[i] = min(dp[i], dp[i- j*j] + 1);
    }
  }
  cout<<dp[n];

  return 0;
}