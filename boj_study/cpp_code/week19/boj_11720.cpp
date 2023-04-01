#include <iostream>

using namespace std;

int main()
{
  int n;
  string a;
  int sum = 0;
  cin>>n;
  cin>>a;
  for (int i = 0; i < n; i++)
  {
    sum += (a[i] - '0');
  }
  cout<<sum<<"\n";
  return 0;
}