#include <iostream>

using namespace std;

int main()
{
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  
  int cnt = 0;
  if( a< 0)
  {
    a*= -1;
    cnt += (a*c);
    
    cnt += d;
    cnt += (b*e);
    cout<<cnt<<"\n";
  } 
  else
  {
    cnt = 0;
    if (a == 0)
    {
      cnt += d;
    }
    cnt += (b-a)*e;
    cout<<cnt<<"\n";
  }
    
  return 0;
}
