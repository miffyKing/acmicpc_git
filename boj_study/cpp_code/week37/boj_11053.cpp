#include <iostream>
#include <math.h>

using namespace std;

int dp[1002];

int main()
{
  int n;
  int arr[1002];

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int ans = -1;
  dp[0] = 1;

  for (int i = 0; i < n; i++)
  {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
    {
      if (arr[j] < arr[i] && dp[i] <= dp[j])
      {
        dp[i] = dp[j] + 1;
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
  return 0;
}