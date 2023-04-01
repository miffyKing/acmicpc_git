#include <iostream>

using namespace std;

int main()
{
  int a;
  int sum = 0;
  for(int i = 0; i < 4; i++)
  {
    cin>>a;
    sum += a;

  }
  cout << sum / 60 <<"\n";
  cout << sum % 60;
  return 0;
}