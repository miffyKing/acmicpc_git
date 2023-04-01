#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> arr;
  int a,b,c;
  cin>>a>>b>>c;

  arr.push_back(a);
  arr.push_back(b);
  arr.push_back(c);
  sort(arr.begin(), arr.end());
  if (a == b && b == c)
  {
    cout<<10000 + a*1000;
    return 0;
  }
  else if (a==b && b != c)
  {
    cout<<1000 + a*100;
    return 0;
  }
  else if (a==c && c != b)
  {
    cout<<1000 + a*100;
    return 0;
  }
  else if (c==b && c != a)
  {
    cout<<1000 + b*100;
    return 0;
  }
  else
  {
    cout<<arr[2] * 100;
return 0;
  }
  return 0;
}