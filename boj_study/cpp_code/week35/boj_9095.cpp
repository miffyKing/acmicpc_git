#include <iostream>

using namespace std;

int cnt = 0;

void func(int n)
{
  if (n == 0)
  {
    cnt++;
    return ;
  }

  if (n - 1 >= 0)
    func(n-1);
  if (n - 2 >= 0)
    func(n-2);
  if (n - 3 >= 0)
    func(n-3);
}

int main()
{
  int t;
  cin>>t;

  for (int i = 0; i <t; i++)
  {
    int n;
    cin>>n;
    func(n);
    cout<<cnt <<"\n";
    cnt = 0;
  }  
  return 0;
}