#include <iostream>

#define DIVIDEBY  1000000000
using namespace std;

int dp[202][202];

int main()
{
  long long n, k;

  cin >> n >> k;

  for (int i = 0; i <= n; i++)
  {
    dp[1][i] = 1;
  }

  for (int i = 1; i <= k; i++)
  {

    for (int j = 0; j <= n; j++)
    {

      for (int l = 0; l <= j; l++)
      {
        dp[i][j] += dp[i - 1][j - l];
        dp[i][j] %= DIVIDEBY;
      }
    }
  }
  cout << dp[k][n];

  return 0;
}