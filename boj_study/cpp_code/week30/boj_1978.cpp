#include <iostream>

using namespace std;

int arr[1002];

void get_sosu()
{
  for (int i = 2; i <= 40; i++)
  {
    int j = i * i;
    while (j <= 1000)
    {
      arr[j] = 1;
      j += i;
    }
  }
}

int main()
{
  get_sosu();
  arr[1] = 1;

  int n;
  cin >> n;

  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    if (arr[tmp] == 0)
      cnt++;
  }
  cout << cnt << "\n";
}