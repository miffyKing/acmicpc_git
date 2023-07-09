#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;


long long ans = 0;


int main()
{
  int n;
  cin>>n;
  for (int i = 1; i <=n; i++)
  {
    ans += ((n/i)*i);
  }
  
  cout<<ans<<"\n";
  return 0;
}