#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int n;
int arr[202];
int dp[202];
int result;

int main()
{
  cin>>n; 
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i];
  }
  dp[0] = 1;
  //memset(dp, 1 ,sizeof(int)*202);
  for (int i = 0; i < n; i++)
  {
    dp[i]  = 1;
    for (int j = 0; j < i; j++)
    {
      if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
        dp[i] = dp[j]+1;
    }
    result = max(result, dp[i]);
  }
  cout<<n - result<<"\n";
  return 0;
}
