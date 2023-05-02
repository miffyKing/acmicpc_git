#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <limits>

using namespace std;

int main()
{
  int n;
  vector<long long> arr;

  cin>>n;
  for (int i = 0; i < n; i++)
  {
    long long tmp;
    cin>>tmp;
    arr.push_back(tmp);
  }
  sort(arr.begin(), arr.end());
  int start = 0;
  int end = n-1;
  pair<int,int> min_pair;
  long long min_val = 2000000000;
  for (int i = 0; i < n; i++)
  {
    if (start >= end)
    {
      break;
    }
    if ( abs(arr[start] + arr[end]) < min_val)
    {
      min_pair.first = arr[start];
      min_pair.second = arr[end];
      min_val = abs(arr[start] + arr[end]);
    }
    if (abs(arr[start+1] + arr[end]) > abs(arr[start] + arr[end-1]))
    {
      end--;
    } else 
    {
      start++;
    }
  }
  cout<<min_pair.first << " " << min_pair.second<<"\n";
  return 0;
}