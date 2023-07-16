#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  vector<int> arr;
  for (int i = 0; i < 9; i++)
  {
    int tmp;
    cin>>tmp;
    arr.push_back(tmp);
  }
  sort(arr.begin(), arr.end());

  for (int i = 0; i <9; i++)
  {
    for (int j = i+1; j < 9; j++)
    {
      int sum = 0;
      for (int k = 0; k < 9; k++)
      {
        if (k != i && k != j)
        {
          sum += arr[k];
        }
      }
      if (sum == 100)
      {
        // cout<<"!!!!\n";

        for (int idx = 0; idx < 9; idx++)
        {
          if (idx != i && idx != j)
          {
            cout<<arr[idx]<<"\n";
          } 
        }
        return 0;
      }
    }
  }
  
  return 0;
}