#include <iostream>

using namespace std;

long long dp[100002];

int main()
{
  int n;
  cin>>n;

  dp[1] = 3;
  dp[2] = 7;
  dp[3] = 17;
  dp[4] = 41;

  for (int i = 5; i <= 100000; i++)
  {
    dp[i] = (dp[i-1]*2 + dp[i-2])%9901;
  }
  cout<<dp[n];
  return 0;
}