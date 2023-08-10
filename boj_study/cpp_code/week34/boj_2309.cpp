#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
  vector<int> arr;
  int sum_all = 0;
  for (int i = 0; i < 9; i++)
  {
    int tmp;
    cin>>tmp;
    sum_all+=tmp;
    arr.push_back(tmp);
  }
  sort(arr.begin(), arr.end());

  for (int i = 0; i <9; i++)
  {
    
    for (int j = i+1; j < 9; j++)
    {
      if (sum_all - arr[i] - arr[j] == 100)
      {
        for (int idx = 0; idx < 9; idx++)
        {
          if (idx != i && idx != j)
            cout<<arr[idx]<<"\n";
        }
        return 0;
      }
    }
  }
  return 0;
}