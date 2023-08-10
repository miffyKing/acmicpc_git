#include <iostream>


using namespace std;

int main()
{
  int n;
  int k = 0;

  while(cin>>n)
  {
    int ans = 1;
    k = 1;

    while(1)
    {
      if (ans % n == 0)
        break;
      else
      {
        k++;
        ans = ans*10 + 1;
        ans %= n;
      }
    }  
    cout<< k <<"\n";
  }
  return 0;
}