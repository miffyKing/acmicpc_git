#include <iostream>

using namespace std;

int main()
{
  int n, a,b;
  int cnt = 0;
  cin>>n>>a>>b;

  while(1)
  {
    if (a == b)
    break;
    a -= (a/ 2);
    b -= (b /2 );
    cnt++;
  }
  cout<<cnt<<"\n";
  return 0;
}