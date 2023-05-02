#include <iostream>

using namespace std;

int main()
{
  int n;
  int a,b;

  cin>>n;
  cin>>a>>b;

  a /= 2;
  if (n < a+b)
  {
    cout<<n;
  } else 
  {
    cout<<a+b;
  }
  return 0;
}