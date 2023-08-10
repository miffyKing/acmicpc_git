#include <iostream>
#include <math.h>

using namespace std;

int dp[1002];

int main()
{
  int n;
  int arr[1002];

  cin>>n;
  for(int i = n-1; i >= 0; i--)
  {
    cin>> arr[i];
  }
  int ans = -1;
  if (n == 1)
  {
    cout<<1;
    return 0;
  }
  dp[0] = 1;
  for (int i = 1 ; i < n; i++)
  {
    dp[i] = 1;
    for(int j = 0; j < i; j++)
    {
      if(arr[j] < arr[i])
      {
        //cout<<"!! i is   :  " << i << "\n";
        if (dp[i] > dp[j])
          continue;
        dp[i] = dp[j]+1;
        //if(dp[i] < dp[j])
        //  dp[i] = dp[j] + 1;
      }
    }
    
    ans = max(ans, dp[i]);
  }
  cout<<ans<<"\n";
  return 0;
}