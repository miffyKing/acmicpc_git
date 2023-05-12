#include <iostream>
#include <vector>

using namespace std;

long long dp[1002][1002];
int main()
{
  int n,k;
  
  dp[0][0] =1;
  dp[1][0] = 1;
  dp[1][1] = 1;

  cin>>n>>k;
  for (int i =2; i<= n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (j == 0) 
        dp[i][0] = 1;
      else if (i == j)
        dp[i][j] = 1;
      else
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
    }
  }
  cout<<dp[n][k];

  return 0;
}