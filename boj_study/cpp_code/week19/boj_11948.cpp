#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < 4; i++)
  {
    int tmp;
    cin>>tmp;
    a.push_back(tmp);
  }
  int tmp;
  cin>>tmp;
  b.push_back(tmp);
  cin>>tmp;
  b.push_back(tmp);

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  cout<< a[3] +a[2] + a[1] + b[1];
}