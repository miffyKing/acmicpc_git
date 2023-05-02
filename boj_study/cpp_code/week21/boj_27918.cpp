#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  vector<int> table;
  int a= 0;
  int b= 0;
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    char tmp;
    cin>>tmp;
    if (tmp == 'D')
    {
      a++;
    } else 
    {
      b++;
    }
    if (a-b == 2 || a-b == -2)
    {
      cout<<a<<":"<<b;
      return 0;
    }
  }
  cout<<a<<":"<<b<<"\n";
  return 0;
}