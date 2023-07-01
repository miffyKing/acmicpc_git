#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int tmp;
  vector<long long int> arr;

  int n,m;
  cin>>n>>m;
  for (int i = 0; i <n; i++)
  {
    cin>>tmp;
    arr.push_back(tmp);
  }
  for (int i = 0; i < m; i++)
  {
    sort(arr.begin(), arr.end());
    long long int sum = arr[0] + arr[1];
    arr[0] =sum;
    arr[1] = sum;
  }
  long long int sum = 0;
  for(int i = 0; i <n; i++)
  {
    sum += arr[i];
  }
  cout<<sum;


  return 0;
}
