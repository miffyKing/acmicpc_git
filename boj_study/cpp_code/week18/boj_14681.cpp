#include <iostream>

using namespace std;

int main()
{

  int x,y;
  cin>>x;
  cin>>y;
  if(x >0 && y > 0)
  {
    cout<<1;
    return 0;
  }
  if(x < 0 && y > 0)
  {
    cout<<2;
    return 0;
  }
  if(x <0 && y < 0)
  {
    cout<<3;
    return 0;
  }
  if(x >0 && y < 0)
  {
    cout<<4;
    return 0;
  }

}