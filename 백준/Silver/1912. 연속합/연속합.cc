#include <iostream>
#include <algorithm>
#include <utility>
#include <math.h>
using namespace std;

long long dp[100002];

int main()
{
  
  int n;
  int arr[100002];
  cin>>n;
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i];
  }
  long long max_Val = arr[0];
  dp[0] = arr[0];
  for (int i = 1; i < n; i++)
  {
    dp[i] = arr[i];
    if (dp[i] < dp[i-1] + arr[i])
    {
      dp[i] = dp[i-1] + arr[i];
    }

    max_Val = max(dp[i], max_Val);
  }
  cout<<max_Val;
  return 0;
}