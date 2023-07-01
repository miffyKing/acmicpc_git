#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{ 
  int n;
  
  cin>>n;
  int dp[n+1];
  dp[1] = 3;
  dp[2] = 7;
  dp[3] = 17;
  for (int i = 4; i <=n; i++)
  {
    dp[i] = (dp[i-1]*2 + dp[i-2])%9901;
  }
  cout<<dp[n]<<"\n";


  return 0;
}