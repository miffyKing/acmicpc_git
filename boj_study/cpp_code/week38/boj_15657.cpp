#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n,m;
int arr[10];
int ans[10];

void func(int cur)
{
  if (cur == m)
  {
    for (int i = 1; i<=m; i++)
    {
      cout<<ans[i] << " ";
    }cout<<"\n";
    return ;
  }

  for (int i = 0; i < n; i++)
  {
    if (arr[i] >= ans[cur])
    {
      ans[cur+1] = arr[i];
      func(cur+1);
      ans[cur+1] = 0;
      
    }
  }
}

int main()
{
  cin>>n>>m;
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i];
  }
  sort(arr, arr+n);


  func(0);
  return 0;
}