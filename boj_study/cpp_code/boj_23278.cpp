#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
  float n,l,h;
  vector<int> lst;

  cin>>n>>l>>h;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin>>tmp;
    lst.push_back(tmp);
  }
  sort(lst.begin(), lst.end());

  double sum = 0;
  int cnt =0;
  for (int i = l; i < n-h; i++)
  {
    sum += lst[i];
    cnt++;
  }
  double ans = (double)sum/(double)cnt;
  cout.precision(15);
  cout<< sum/cnt;
  //printf("%f\n", sum/cnt); 
  return 0;
}