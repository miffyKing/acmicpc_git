#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;

int dp[1002];
int main()
{
  int n;
  cin>>n;

  int arr[1002];
  for (int i = 1; i <=n; i++)
  {
    cin>>arr[i];
  }

  int ans = 0;

  for (int i = 1; i <= n; i++)
  {
    dp[i] = arr[i];
    for (int j = 1; j < i; j++)
    {
      if(arr[j] < arr[i] && dp[i] < dp[j]+arr[i])
      {
        dp[i] = dp[j] + arr[i];
      }#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;

int dp[1002];
int main()
{
  int n;
  cin>>n;

  int arr[1002];
  for (int i = 1; i <=n; i++)
  {
    cin>>arr[i];
  }

  int ans = 0;

  for (int i = 1; i <= n; i++)
  {
    dp[i] = arr[i];
    for (int j = 1; j < i; j++)
    {
      if(arr[j] < arr[i] && dp[i] < dp[j]+arr[i])
      {
        dp[i] = dp[j] + arr[i];
      }
    }
    ans = max(ans, dp[i]);
  }
  cout<<ans;
  return 0;
}
    }
    ans = max(ans, dp[i]);
  }
  cout<<ans;
  return 0;
}