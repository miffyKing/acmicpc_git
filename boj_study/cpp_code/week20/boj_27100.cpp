#include <iostream>

using namespace std;

int main()
{
  int n;
  int a,b,c;

  cin>>n;
  cin>>a>>b>>c;
  int cnt =0;
  if (a > n){
    cnt+= n;
  } else 
  {
    cnt += a;
  }
  
  if (b > n){
    cnt+= n;
  } else 
  {
    cnt += b;
  }

  if (c > n){
    cnt+= n;
  } else 
  {
    cnt += c;
  }
  cout<<cnt<<"\n";
  return 0;
}