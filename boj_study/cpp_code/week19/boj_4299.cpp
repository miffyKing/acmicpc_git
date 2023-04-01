#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  float hap, cha;
  cin>>hap >> cha;
  float a, b;
  a = (hap + cha) /2;
  b = (hap - cha)/ 2;
  
  //cout<<a<< ' ' << b <<" !!!! \n";
  if (a- (int)a == 0 || b - (int)b == 0)
  {
    if (a < 0 || b < 0)
    {
      cout<< "-1";
      return 0;
    }
    if (a>b)
    {
      cout<<a << ' ' << b;
      return 0;
    } else 
    {
      cout<<b << ' ' << a;
    }
    
  }
  else{
    cout<<-1;
  }
  

}