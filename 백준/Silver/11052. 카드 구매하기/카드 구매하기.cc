#include <iostream>

using namespace std;


int n;
int arr[1002];
int dp[1002];

int main()
{
  cin>>n;

  for (int i = 1; i <= n ; i++)
  {
    cin>>arr[i];
  }

  for (int i = 1; i <= n; i++)
  {
    dp[i] = arr[1]*i;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = i; j <=n; j++)
    {
      dp[j] = max(dp[j-i] + arr[i], dp[j]);
    }
  }
  cout<<dp[n]<<"\n";


  return 0;
}