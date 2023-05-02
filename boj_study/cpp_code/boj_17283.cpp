#include <iostream>

using namespace std;

int main()
{
  int l,r;
  cin>>l>>r;
  float total = 0;
  int cnt = 2;

  while(1)
  {
    
    float  newsize = (float)l*(float)((float)r/100);
    l = (int)newsize;
    if (l <= 5)
      break;
    total += cnt*(int)newsize;
    cnt*=2;
  }
  cout<<total<<"\n";
  return 0;

}