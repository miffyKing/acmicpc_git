#include <iostream>

using namespace std;

int arr[1000002];
long long dp[1000002];

int main()
{
  int t;
  cin>>t;
  
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  dp[4] = 7;
  
  for (int i = 5; i <= 1000000; i++)
  {
    dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
  }
  for (int i = 0; i < t; i++)
  {
    long long n;
    cin>>n;
    cout<<dp[n]<<"\n";
  

  }
  return 0;
}