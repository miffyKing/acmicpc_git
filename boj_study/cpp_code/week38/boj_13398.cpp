#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int arr[100002];
int dp[100002][2];

int main()
{
  cin>>n;
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i];
  }

  int maxval = arr[0];
  
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = dp[i][1] = arr[i];
    if(i == 0) continue;
    dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
    dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
    
    int tmp_max = max(maxval, dp[i][0]);
    maxval = max(tmp_max, dp[i][1]);
  }
  
  cout<<maxval<<"\n";
  return 0;
}