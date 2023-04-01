#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
     int max_val = -1;
  for (int i = 0; i < 2; i++)
  {
    int a;
    int sum = 0;
 
    for (int j = 0; j < 4; j++)
    {
      cin>>a;
      sum+=a;
    }
    max_val = max(max_val, sum);   
  }
  cout<<max_val<<"\n";
}