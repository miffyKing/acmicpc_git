#include <iostream>

using namespace std;

int main()
{
  long long r,c,n;

  cin>>r>>c>>n;

  long long sero,garo;
  if(r%n == 0)
  {
    sero = r/n;
  } else {
    sero = (r/n)+1;
  }

  if (c%n == 0)
  {
    garo = c/n;
  } else {
    garo = (c/n)+1;
  }
  cout<<sero*garo;
  return 0;
}