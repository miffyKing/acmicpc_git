#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<pair<int, int> > range;

int main()
{
  ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
  int n;
  cin>>n;
  for (int i = 0; i < n ; i++)
  {
    int from, to;
    cin>>from >> to;
    range.push_back(make_pair(from , to));
  }
  sort(range.begin(), range.end());

  long long ans = 0;
  int left = INT_MIN;
  int right = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    if (range[i].first <= right)
      right = max(right, range[i].second);
    else
    {
      ans += (right - left);
      left = range[i].first;
      right = range[i].second;
    }
  }
  ans += (right - left);
  cout<<ans<<"\n";
  return 0;
}