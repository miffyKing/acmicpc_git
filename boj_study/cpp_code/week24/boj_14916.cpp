#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  int arr[100002];

  cin>>n;

  if (n ==1 || n == 3)
  {
    cout<<"-1";
    return 0;
  }

  arr[2] = 1;
  arr[4] = 2;
  arr[5] = 1;
  arr[6] = 3;
  arr[7] = 2;
  arr[8] = 4;
  

  for (int i = 9; i <= n; i++)
  {
    arr[i] = min(arr[i-2], arr[i-5]) + 1;
   // cout<< "I is "<< i << "   :  " << arr[i] <<"\n";
  }
  cout<<arr[n];
  return 0;
}