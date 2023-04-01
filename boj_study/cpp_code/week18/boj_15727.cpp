#include<iostream>
using namespace std;

int main()
{
  long long n;
  cin>>n;
  long long jump = n/5;
  if (n%5 == 0)
  {
    cout<<jump;
    return 0;
  }
  cout<<jump + 1;
  return 0; 
}