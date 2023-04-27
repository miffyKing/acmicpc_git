#include <iostream>

using namespace std;

int main()
{
  int a,b,c,d,e,f;

  cin>>a>>b>>c>>d>>e>>f;
  int sum = a*3 + b*2 +c ;
  int sum2 = d*3 + e*2 + f;
  if (sum > sum2) {
    cout<<"A\n";
    return 0;
  } else if (sum < sum2){
    cout<<"B\n";
    return 0;
  } else 
  {
    cout<<"T\n";
  }
  
  return 0;
}