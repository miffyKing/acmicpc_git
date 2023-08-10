#include <iostream>
#include <math.h>
using namespace std;

int dp_inc[1002];
int dp_dec[1002];

int main()
{
  int n;
  int arr[1002];
  int arr2[1002];
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    cin>>arr[i];
    arr2[n-i-1] = arr[i];
  }

  for (int i = 0; i < n; i++)
  {
    dp_inc[i] = 1;
    dp_dec[i] = 1;
    for (int j = 0; j < i; j++)
    {
      if(arr2[j] < arr2[i] && dp_dec[i] <= dp_dec[j])
      {
        dp_dec[i] = dp_dec[j] + 1 ;
      }
      if(arr[j] < arr[i] && dp_inc[i] <= dp_inc[j])
      {
        dp_inc[i] = dp_inc[j] + 1;
      }
    }
  }
  int dp_total[1002];

  int ans = -1;
  
  for (int i = 0; i < n; i++)
  {
    dp_total[i] = dp_inc[i] + dp_dec[n-i-1];
    ans = max(ans, dp_total[i]);
  }

  cout<< ans-1<<"\n";

  // for (int i = 0; i < n ; i++)
  // {
  //   cout<<dp_inc[i] <<" ";
  // }
  // cout<<"\n";
  // for (int i = n-1; i >= 0 ; i--)
  // {
  //   cout<<dp_dec[i] <<" ";
  // }

  // cout<<"\n";
  return 0;
}