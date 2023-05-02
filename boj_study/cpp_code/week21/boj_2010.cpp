#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    cnt += (tmp - 1);
  }
  cout << cnt + 1;
}