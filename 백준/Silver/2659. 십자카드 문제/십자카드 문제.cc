#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

bool containzero(int num)
{
  string a = to_string(num);
  if(a[0] == '0' || a[1] == '0' || a[2] == '0' || a[3] == '0')
  {
    return true;
  }
  return false;

}

bool isclocknum(int number)
{
  int a = number/1000;
  int b = number%1000 / 100;
  int c = number%100/10;
  int d = number%10;
  //cout<<a<<" " <<b << " " << c << " " << d << "\n";
  vector<int> num;
  num.push_back(0);
  num.push_back(0);
  num.push_back(0);
  num.push_back(0);
  num[0] = a * 1000 + b * 100 + c * 10 + d;
  num[1] = b * 1000 + c * 100 + d * 10 + a;
  num[2] = c * 1000 + d * 100 + a * 10 + b;
  num[3] = d * 1000 + a * 100 + b * 10 + c;
  sort(num.begin(), num.end());
  if (number == num[0])
  {
    return true;
  }
  return false;
}

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  // abcd, bcda cdab dabc
  vector<int> num;
  num.push_back(0);
  num.push_back(0);
  num.push_back(0);
  num.push_back(0);
  num[0] = a * 1000 + b * 100 + c * 10 + d;
  num[1] = b * 1000 + c * 100 + d * 10 + a;
  num[2] = c * 1000 + d * 100 + a * 10 + b;
  num[3] = d * 1000 + a * 100 + b * 10 + c;
  sort(num.begin(), num.end());
  // for (int i = 0; i < 4; i++)
  // {
  //   cout << num[i] << "\n";
  // }
  // int minval = num[0]%100;
  int cnt = 0;

  for (int i = 1111; i < num[0]; i++)
  {
    if (containzero(i) == true)
    {
      continue;
    }
    if (isclocknum(i) == true)
    {
      cnt++;
    }
  }

  cout << cnt+1;

  return 0;
}
