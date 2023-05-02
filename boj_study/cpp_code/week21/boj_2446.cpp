#include <iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;
  for (int i = n; i>0; i--)
  {
    int val = i*2-1;
    for (int j = 0; j < n-i; j++)
    {
      cout<<" ";
    }
    for (int j = 0; j < val; j++)
    {
      cout<<"*";
    }
    cout<<"\n";
  }
  if (n != 1)
  {
    for (int i = 2; i <= n; i++)
    {
      int val = i*2-1;
      for (int j = 0; j < n-i; j++)
      {
        cout<<" ";
      }
      for (int j = 0; j < val; j++)
      {
        cout<<"*";
      }
      cout<<"\n";
    }

  }
  

  return 0;
}