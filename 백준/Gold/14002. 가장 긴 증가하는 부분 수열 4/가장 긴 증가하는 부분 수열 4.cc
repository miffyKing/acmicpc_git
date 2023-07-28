#include <iostream>
#include <vector>
#include <algorithm>
#include <algorithm>

using namespace std;
vector<int> lst[1002];
int main()
{
  int n;
  int arr[1002];
  int dp[1002];
  int max_val = -1;
  int max_idx= -1;
  cin>>n;
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i];
  }
  //lst[0].push_back(arr[0]);
  for (int i = 0; i < n; i++)
  {
    dp[i] = 1;
    lst[i].push_back(arr[i]);
    for (int j = 0; j < i; j++)
    {
      if(arr[i] > arr[j])
      {
        if(dp[i] > dp[j] + 1)
        {
          dp[i] = dp[i];
        }
        else
        {
          dp[i] = dp[j]+1;
          
          lst[i].clear();
          lst[i] = lst[j];
          // for(int k = 0; k < lst[j].size(); k++)
          // {
          //   lst[i].push_back(lst[j][k]);
          // }
          lst[i].push_back(arr[i]);
        }
      }
      // cout<< "i is  " << i << "and current lst is ...\n" ;
      // for(int idx = 0; idx < lst[i].size(); idx++)
      // {
      //   cout<<lst[i][idx] << " ";
      // } cout<<"\n";
    }
    max_val = max(max_val, dp[i]);
    if(max_val == dp[i])
    {
      max_idx = i;
    }
  }
  cout<<max_val<<"\n";

  //cout<<"max idx is " << max_idx<<"\n";  
  if(lst[max_idx].size() == 0)
  {
    cout<<arr[max_idx]<<"\n";
    return 0;
  }
  for (int i  =0 ; i < lst[max_idx].size(); i++)
  {
    cout<<lst[max_idx][i] << " ";
  }cout<<"\n";
  return 0;
}
