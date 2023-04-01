#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  int minburger;
  minburger = min(a,b); 
  minburger= min(minburger, c);
  int mindrink;
  mindrink = min(d,e);
  cout<< minburger + mindrink - 50;
  return 0;
}