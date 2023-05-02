#include <iostream>

using namespace std;

int main()
{
  int n,w,h,l;
  cin>>n>>w>>h>>l;
  
  int sero = w/l;
  int garo = h/l;
  if (sero*garo > n)
  {
    cout<<n;
    return 0;
  } else 
  {
    cout<<sero*garo;
    return 0;
  }

  return 0;
}