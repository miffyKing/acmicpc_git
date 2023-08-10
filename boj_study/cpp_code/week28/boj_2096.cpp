#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int dpmax[3];
int dpmin[3];
int main()
{
  
  cin>>n;
  int a,b,c;
   cin>>a>>b>>c;
   dpmax[0] = a;
   dpmin[0] = a;
   dpmax[1] = b;
   dpmin[1] = b;
   dpmax[2] = c;
   dpmin[2] = c;
  

  for (int i = 1; i <n; i++)
  {
    int tmp0, tmp1;

    int preva = a;
    int prevb = b;
    int prevc = c;
  
    cin>>a>>b>>c;
    tmp0 = dpmin[0];
    tmp1 = dpmin[1];
    dpmin[0] = min(dpmin[0],dpmin[1]) + a;
    dpmin[1] = min(dpmin[2], min(tmp0,dpmin[1])) + b;
    dpmin[2] = min(tmp1,dpmin[2]) + c;

    tmp0 = dpmax[0];
    tmp1 = dpmax[1];
    dpmax[0] = max(dpmax[0],tmp1) + a; 
    dpmax[1] = max(dpmax[2], max(tmp0,tmp1)) + b;
    dpmax[2] = max(tmp1,dpmax[2]) + c;

  }
  sort(dpmin, dpmin+3);
  sort(dpmax, dpmax+3);

  cout<<dpmax[2] << " "  << dpmin[0] <<"\n";
  return 0;
}