#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
#include <climits>


using namespace std;

int main()
{
  int n;
  vector<int> house;
  long long sum = 0;
  cin>>n;
  for(int i =0 ; i <  n; i ++)
  {
    int tmp;
    cin>>tmp;
    house.push_back(tmp);
  }  
  sort(house.begin(), house.end());
  cout<<house[(n-1)/2];
  return 0;
}