#include <iostream>

using namespace std;

int main()
{

  int a, b;
  int n;
  cin>>n;
  for (int i = 0; i <n; i++)
  {
    cin>>a>>b;
    cout<<"Case #" << i+1<<  ": " << a << " + " <<  b << " = " << a+b <<"\n";   
  }
  
}