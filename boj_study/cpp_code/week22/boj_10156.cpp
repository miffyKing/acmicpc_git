#include <iostream>

using namespace std;

int main()
{
  int a, b, c;

  cin>>a>>b>>c;

  int sum = a*b;
  if (sum - c <= 0)
  {
    cout<< 0;
    return 0;
  }
  cout<< sum - c;

}