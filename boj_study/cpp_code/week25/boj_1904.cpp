#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[1000001];

int main()
{
  int n;
  cin>>n;

  dp[1] = 1;
  dp[2] = 2;
  //00, 11
  dp[3] = 3;//홀수일 땐  
  // 001 100 111
  dp[4] = 5;


  if (n <= 4)
  {
    cout<<dp[n];
    return 0;
  }
  for (int i = 5; i<= n; i++)
  {
    dp[i]= (dp[i-1] + dp[i-2])%15746;
  }
  cout<<dp[n];
  //0000, 0011, 1100, 1111, 1001

  return 0;
}