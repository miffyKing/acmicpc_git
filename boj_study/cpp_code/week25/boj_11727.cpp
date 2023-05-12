#include <iostream>
#include <vector>

using namespace std;

int main()
{
  long long dp[1002];

  dp[1] = 1;
  dp[2] = 3;
  dp[3] = 5;

  for (int i = 4; i <= 1000; i++)
  {
    dp[i] =( dp[i-1] + (dp[i -2]*2))%10007;
  }
  int n;
  cin>>n;
  cout<<dp[n];

  return 0;
}