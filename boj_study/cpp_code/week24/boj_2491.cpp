#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> arr;
  int n,tmp;
  vector<int> dp1;
  vector<int> dp2;
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    cin>>tmp;
    arr.push_back(tmp);
  }
  dp1.push_back(1);
  dp2.push_back(1);
  //dp2[0] = 1;
  int max1 = -1;
  for (int i = 1; i < n; i++)
  {
    if(arr[i] >= arr[i-1])
    {
      dp1.push_back(dp1[i-1] + 1);
    } 
    else {
      dp1.push_back(1);
    }

    if(arr[i] <= arr[i-1])
    {
      dp2.push_back(dp2[i-1] + 1);
    } 
    else {
      dp2.push_back(1);
    }
  }

  sort(dp1.begin(), dp1.end());
  sort(dp2.begin(), dp2.end());

  if (dp1[n-1] > dp2[n-1])
  {
    cout<<dp1[n-1];
  } else 
  {
    cout<<dp2[n-1];
  }
  //dp1[n-1] > dp2[n-1] ? cout<< dp1[n-1] : cout<<dp2[n-1];

  return 0;
}