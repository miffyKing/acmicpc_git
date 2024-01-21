#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

long long gcd = 0;

void euclide(long long a, long long b)//큰거 작은거
{
  long long left = a%b;
  if (left != 0)
    euclide(b, left);
  if (left == 0)
   gcd = b; 
}

int main()
{
  long long a,b;
  cin>>a>>b;

  euclide(max(a,b), min(a,b));
  string ans = "";
  for (int i= 0; i < gcd; i++)
    ans+="1";
  cout<<ans<<"\n";
}