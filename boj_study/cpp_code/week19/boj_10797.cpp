#include <iostream>

using namespace std;

int main()
{
  int a;
  cin>>a;
  int tmp;
  int cnt = 0;
  for (int i = 0; i < 5; i++)
  {
    cin>>tmp;
    if (a == tmp)
    {
      cnt++;
    }
  }
  cout<<cnt<<"\n";
}