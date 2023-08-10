#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  
  cin>>n;

  int ans = 0;

  for (int i = 1; i <= n; i*=10)
  {
    ans += n-i+1;
  }
  cout<<ans<<"\n";
  return 0;
}