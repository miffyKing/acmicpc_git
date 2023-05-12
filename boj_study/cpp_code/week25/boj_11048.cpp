#include <iostream>
#include <algorithm>

using namespace std;

int table[1002][1002];
int dp[1002][1002];

int main()
{
  int n,m;
  cin>>n>>m;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin>>table[i][j];
    }
  }
  
  
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      int cur_max;
      int first_cmp = max(dp[i-1][j-1], dp[i][j-1]);
      int sec_cmp = max(first_cmp, dp[i-1][j]) ;
      dp[i][j] = sec_cmp + table[i][j];
      //cout<<"dp[][]" << i << " " << j << " :  " << dp[i][j]<<"\n"; 
    }
  }
  cout<<dp[n][m]<<"\n";
  return 0;
}