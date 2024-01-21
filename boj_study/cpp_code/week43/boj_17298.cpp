#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int n;
stack<int> s;
int ans[1000001];
int seq[1000001];

int main()
{
  cin>>n;
  for (int i = 0; i < n; i++)
    cin>>seq[i];
  for (int i = n; i >= 0; i--)
  {
    while( !s.empty() && s.top() <= seq[i])
      s.pop();
    if (s.empty()== true)
      ans[i] = -1;
    else 
      ans[i] = s.top();
    s.push(seq[i]);

  }
  for (int i = 0; i  <n; i++)
    cout<<ans[i] << " ";
  return 0;
}