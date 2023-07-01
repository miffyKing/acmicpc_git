#include <iostream>
#include <vector>
#include <string.h>
#include <memory.h>
using namespace std;

int arr[101][101];
long long dp[101][101];
int n;



int main()
{

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> arr[i][j];
    }
  }
  //memset(dp, 0, sizeof(int) * (n + 1) * (n + 1));
  dp[1][1] = 1;

  for (int col = 1; col <= n; col++)
  {
    for (int row = 1; row <=n; row++ )
    {
      if (arr[col][row] == 0) continue;
      if (dp[col][row] != 0)
      {
        int nxt_row = row + arr[col][row];
        int nxt_col = col + arr[col][row];
        
        if (nxt_col <= n) dp[nxt_col][row] += dp[col][row];
        if (nxt_row <= n) dp[col][nxt_row] += dp[col][row];
      }
    }
  }

  cout << dp[n][n] << "\n";
  return 0;
}