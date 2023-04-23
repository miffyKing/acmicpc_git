#include <iostream>

using namespace std;

int main()
{
  int p[4];
  for(int i  = 0; i < 4; i++)
  {
    cin>>p[i];
  }
  int x,y,z;
  cin>>x>>y>>z;
  for (int i = 0; i<4; i++)
  {
    if(p[i] == x)
    {
      cout<<i+1;
      return 0;
    }
  }
  cout<< 0;


  return 0;
}