#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1002];
int dp[1002];

int main()
{
  int n;
  int maxval = -1;
  cin>>n;
  for (int i = 0; i< n; i++)
  {
    cin>>arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
    {
      if (arr[i] > arr[j] )
      {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    maxval = max(dp[i], maxval);
  }
  cout<<maxval<<"\n";
  return 0;
}