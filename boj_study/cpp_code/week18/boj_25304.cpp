#include <iostream>

using namespace std;

int main()
{

  long long x;
  int n;
  long long a ,b;
  cin>>x;
  cin>>n;
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    cin>>a>>b;
    ans += a*b;
  }
  if (x == ans)
  {
    cout<<"Yes";
    return 0;
  }
  cout<<"No";
  return 0;
}