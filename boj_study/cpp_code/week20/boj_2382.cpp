#include <iostream>

using namespace std;

int main()
{
  long long n,m;
  cin>>n>>m;
  n /=2;
  m /= 2;
  if (n > m)
  {
    cout<<m;
  } else
  {
    cout<<n;
  }
  
  return 0;
}