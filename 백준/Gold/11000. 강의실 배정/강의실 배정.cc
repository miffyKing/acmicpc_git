#include <iostream>
#include <queue>
#include <vector>
#include <utility>
// #include <priority_queue>
#include <algorithm>
using namespace std;

int main()
{
  priority_queue <int, vector<int>, greater<int> > pq;
  vector<pair<int, int> > arr;
  int n;
  cin>>n;
  for (int i = 0; i < n; i++)
  {
    int a,b;
    cin>>a>>b;
    arr.push_back(make_pair(a,b));
  }
  sort(arr.begin(), arr.end());
  pq.push(arr[0].second);
  for (int i = 1; i < n; i++)
  {
    pq.push(arr[i].second);
    if (pq.top() <= arr[i].first)
      pq.pop();
  }
  cout<<pq.size();
  return 0;
}