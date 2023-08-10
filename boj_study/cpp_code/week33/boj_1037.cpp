#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int cnt;
  vector<int> arr;
  cin>>cnt;
  for (int i = 0; i < cnt; i++)
  {
    int tmp;
    cin>>tmp;
    arr.push_back(tmp);

  }
  sort(arr.begin(), arr.end());
  cout<<arr[0]*arr[cnt-1];
  return 0;
}