#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1002];

int main()
{
  int n;
  vector<int> arr;
  cin>>n;
  arr.push_back(0);
  for(int i = 1; i<=n; i++)
  {
    int tmp;
    cin>>tmp;
    arr.push_back(tmp);
  }
  int max_val = -1;
  
  dp[0] = 0;
  dp[1] = arr[1];
  for (int i = 1; i<=n; i++)
  {
    int here = 0;
    dp[i] = 1;
    for (int j = 1; j <i; j++)
    {
      if (arr[i] > arr[j])
        dp[i] = max(dp[i], dp[j]+1);
    }
    max_val = max(max_val, dp[i]);
  }
  // sort(dp+0, dp+n);
  // cout<<dp[n];
  cout<<max_val<<"\n";
  return 0;
}