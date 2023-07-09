#include<iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int eratos[1000001];

void get_sosu()
{
  for (int i = 2; i <= 1000000; i++)
  {
    eratos[i] = i;
  }
  for (int i = 2; i <= sqrt(1000000); i++)
  {
    if (eratos[i] == 0)
      continue;
    for (int j = i*i; j <= 1000000; j += i)
      eratos[j] = 0;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  get_sosu();
  while(1)
  {
    cin>>n;
    if(n == 0)
      return 0;
    for (int i = 2; i < n-1; i++)
    {
      if (eratos[i] != 0 && eratos[n-i]!= 0)
      {
        cout<<n << " = " << i << " + " << n-i << "\n";
        break;
      }
    }

  }
  return 0;
}