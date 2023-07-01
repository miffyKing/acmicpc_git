#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int n, s, m;
int v[52];
int dp[1010][1010];

int main()
{

  cin >> n >> s >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> v[i];
  }

  dp[0][s] = 1;

  if (s + v[1] <= m)
    dp[1][s + v[1]] = 1;
  if (s - v[1] >= 0)
    dp[1][s - v[1]] = 1;

  for (int i = 2; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      if (dp[i - 1][j] != 1)
      {
        continue;
      }
      if (j - v[i] >= 0)
      {
        dp[i][j - v[i]] = 1;
      }
      if (j + v[i] <= m)
      {
        dp[i][j + v[i]] = 1;
      }
    }
  }

  for (int i = m; i >= 0; i--)
  {
    if (dp[n][i] == 1)
    {
      cout << i << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}