#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int x, y, w, h;
  vector<int> arr;
  cin >> x >> y >> w >> h;

  arr.push_back(x);
  arr.push_back(y);
  int a, b;
  a = w - x;
  b = h - y;
  arr.push_back(a);
  arr.push_back(b);

  sort(arr.begin(), arr.end());
  cout << arr[0];
  return 0;
}