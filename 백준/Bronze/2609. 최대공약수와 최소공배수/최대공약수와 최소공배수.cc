#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int a,b;

  cin>>a>>b;
  int orig_a = a;
  int orig_b = b;

  //유클리드 호제법
  while(b>0)
  {
    int tmp = a;
    a= b;
    b = tmp%b;
  }
  int gcd = a;
  
  int lcm = (orig_a*orig_b)/gcd;

  cout<<gcd << "\n" << lcm << "\n";
  return 0;
}