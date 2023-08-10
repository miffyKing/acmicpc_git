#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>

using namespace std;

int n,m,k;
int isused[12][12];
int arr[12][12];
int lst[12];
int ans = -2147483648;

void func(int row, int col, int lim)
{
  if (lim == k)
  {
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
      sum += lst[i];
    }
    ans = max(ans, sum);
    return ;
  }
  for (int i =row; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      if (isused[i][j] == 0  )
      {
        if (i > 1 && isused[i-1][j]) continue;
        if (i < n && isused[i+1][j]) continue;
        if (j > 1 && isused[i][j-1]) continue;
        if (j < m && isused[i][j+1]) continue;
        isused[i][j] = 1;
        lst[lim] = arr[i][j];
        func(i,j, lim+1);
        isused[i][j] = 0;
      }
    }
  }
}

int main()
{
  cin>>n>>m>>k;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin>>arr[i][j];
    }
  }

  func(1,1, 0);

  cout<<ans<<"\n";
  return 0;
}