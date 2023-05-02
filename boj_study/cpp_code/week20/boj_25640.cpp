#include <iostream>
#include <string>

using namespace std;

int main()
{
  string j;
  int n;
  cin>>j;
  cin>>n;
  int cnt = 0;
  for (int i = 0; i <n; i++)
  {
    string tmp;
    cin>>tmp;
    if (j[0] == tmp[0] && j[1] == tmp[1] && j[2] == tmp[2]
    && j[3] == tmp[3])
    {cnt++;}
  }
  cout<<cnt;
    return 0;
}