#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long dp[100002] = {0,};
int main()
{

  int n;
  vector<long long> arr;

  cin>>n;
  for (int i = 0; i <n; i++)
  {
    int tmp;
    cin>>tmp;
    arr.push_back(tmp);
  }
  dp[0] = arr[0];
  for (int i = 1; i < n; i++)
  {
    dp[i] = max(dp[i-1] + arr[i], arr[i]);
  }
  //   for(int i = 0; i< n; i++)
  // {
  //   cout<<dp[i]<< " ";
  // }
  // cout<<"\n";
  sort(dp+0, dp+n);

  cout<<dp[n-1]<<"\n";

  return 0;
}