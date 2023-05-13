#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int dp[1002];
int main()
{
  int n;
  vector<int> arr;
  cin>>n;
  arr.push_back(0);
  for(int i = 0; i < n; i++)
  {
    int tmp;
    cin>>tmp;
    arr.push_back(tmp);
  }

  for (int i = 1; i <= n; i++)
  {
    dp[i] = 1;
    for (int j= 1; j<i; j++)
    {
      if (arr[i] > arr[j])
      {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
  }
  sort(dp+0, dp+n+1);
  cout<<dp[n];
  return 0;
}