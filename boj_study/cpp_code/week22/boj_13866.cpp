#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
  vector<int> arr;
  for (int i = 0; i < 4; i++){
    int tmp;
    cin>>tmp;
    arr.push_back(tmp);
  }
  cout << abs((arr[3]+arr[0]) - (arr[1]+arr[2])); 
  return 0;
}