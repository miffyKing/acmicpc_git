#include <iostream>

using namespace std;

int main()
{
  int s,t,d;
  cin>>s>>t>>d;
  
  int meet = d/(s*2);
  int fly = meet*t;
  cout<<fly;

}