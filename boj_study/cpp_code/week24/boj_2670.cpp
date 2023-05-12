#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
  int n;
  vector<double> arr;
  vector<double> dp;
  cin>>n;
  for (int i = 0; i < n; i++)
  {
    double tmp;
    cin>>tmp;
    arr.push_back(tmp);
  }
  dp.push_back(arr[0]);
  for(int i = 1; i < n; i++)
  {
    dp.push_back(max(dp[i-1]*arr[i], arr[i]));    
  }
  sort(dp.begin(), dp.end());

  cout << fixed, cout.precision(3);
  //printf("%.3f\n", dp[n-1]);
  cout<<dp[n-1];

  return 0;
}