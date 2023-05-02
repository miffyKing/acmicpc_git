#include <iostream>

using namespace std;

int main()
{
  long long cnt = 0;
  long long tmp = 0;
  while(1)
  {
    cin>>tmp;
    if (tmp == -1)
    {
      break;
    }
    cnt+=tmp;
    
  }
  cout<<cnt;
  return 0;
}