#include <iostream>

using namespace std;

int main()
{
  int n;
  long long dp[92];
  cin>>n;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  dp[4] = 3;
  dp[5] = 5;
  dp[6] = 8;

  for (int i = 7; i <= n; i++)
  {
    dp[i] = dp[i-1] + dp[i-2];
  }
  cout<<dp[n];
  //1000 1001 1010
  //10000 10010 10100  10001 10101
  //100000 100100 101000 100010 101010 100001 100101 101001  
  return 0;
}