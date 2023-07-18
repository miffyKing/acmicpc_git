#include <iostream>

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
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (isused[i][j] == 1)
          sum += arr[i][j];
      }
    }

    ans = max(ans, sum);
    return ;
  }
  for (int i =row; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (isused[i][j] == 0  )
      {
        if (i >= 1 && isused[i-1][j]) continue;
        if (i < n -1 && isused[i+1][j]) continue;
        if (j >= 1 && isused[i][j-1]) continue;
        if (j < m -1 && isused[i][j+1]) continue;
        isused[i][j] = 1;
        func(i,j, lim+1);
        isused[i][j] = 0;
      }
    }
  }
}

int main()
{
  cin>>n>>m>>k;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin>>arr[i][j];
    }
  }

  func(0,0, 0);

  cout<<ans<<"\n";
  return 0;
}