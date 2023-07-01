#include <iostream>
#include <vector>
#include <utility>
#include <memory.h>

using namespace std;

int main()
{
  int n,m;
  int arr[303][303];
  int sum[303][303];
  memset(arr, 0, sizeof(int)* 90009);
  memset(sum, 0, sizeof(int)* 90009);
  cin>>n>>m;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    { 
      cin>>arr[i][j];
    }
  }
  
  for (int i = 1; i <= n ; i++)
  {
    for (int j =1; j<=m; j++)
      sum[i][j] = sum[i-1][j] + sum[i][j-1] + arr[i][j] - sum[i-1][j-1];  
  }


  int k;
  cin>>k;
  for (int idx = 0; idx <k; idx++)
  {
    int i,j,x,y;
    cin>>i>>j>>x>>y;
    cout<< sum[x][y] - sum[i-1][y] - sum[x][j-1] + sum[i-1][j-1]<<"\n";

  }


  return 0;
}