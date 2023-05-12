#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int dp[1002];

int main()
{
  int n;
  cin>>n;
  vector<int>arr;
  
  long long int sum = 0;
  for(int i = 0; i <n; i++)
  {
    int tmp;
    cin>>tmp;
    arr.push_back(tmp);
  }
  
  for (int i = 0; i < n; i++)
  {
    dp[i] = arr[i];
    for (int j = 0; j < i; j++)
    {
      if (arr[j] < arr[i] && dp[i] < dp[j]+arr[i])
      {
        dp[i] = dp[j] + arr[i];
      }
    }
  }

  sort(dp+0, dp+n);
  cout<<dp[n-1];
  return 0;
}