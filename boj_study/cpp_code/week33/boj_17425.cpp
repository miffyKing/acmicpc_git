#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  int c;
    
  cin >> t;

  for (int idx = 0; idx < t; idx++)
  {
    
    long long ans =0 ;
    cin>>c;
    
    for (int i = 1; i <= c; i++)
    {
      ans += ((c/i)*i);
    }
    cout<<ans<<"\n";

  }
  return 0;
}