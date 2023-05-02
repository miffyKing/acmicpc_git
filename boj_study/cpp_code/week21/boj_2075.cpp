#include <iostream>
#include <queue>

using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
  int n;
  cin>>n;
   int x;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n*n; i++)
  {
    cin>>x;
    pq.push(x);
    if (pq.size() > n) pq.pop();     
  }
  cout<<pq.top();
}
  