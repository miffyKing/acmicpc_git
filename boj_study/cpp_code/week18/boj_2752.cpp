#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  vector<int> arr;
  arr.push_back(a);
  arr.push_back(b);
  arr.push_back(c);

  sort(arr.begin(), arr.end());
  for (int i = 0; i < 3; i++)
  {
    cout<<arr[i]<< ' ';
  }
  cout<<"\n";
  return 0;
}