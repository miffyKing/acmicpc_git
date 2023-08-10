#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[2188][2188];
int ans[3];

bool check_same(int x, int y, int len)
{
  int tmp = arr[x][y];
  for (int i = x; i < x + len; i++)
  {
    for (int j = y; j < y + len; j++)
    {
      if (tmp != arr[i][j])
      {
        return false;
      }
    }
  }
  return true;
}

void func(int i, int j, int n)
{
  if (n == 1)
  {
    if (arr[i][j] == -1)
      ans[0]++;
    if (arr[i][j] == 0)
      ans[1]++;
    if (arr[i][j] == 1)
      ans[2]++;
    return;
  }

  if (check_same(i, j, n) == true)
  {
    if (arr[i][j] == -1)
      ans[0]++;
    if (arr[i][j] == 0)
      ans[1]++;
    if (arr[i][j] == 1)
      ans[2]++;
    return;
  }

  for (int x = 0; x < 3; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      func(i + x * (n / 3), j + y * (n / 3), n / 3);
    }
  }
}

int main()
{

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }
  if (check_same(0, 0, n) == true)
  {
    if (arr[0][0] == -1)
      cout << 1 << "\n"
           << 0 << "\n"
           << 0 << "\n";
    if (arr[0][0] == 0)
      cout << 0 << "\n"
           << 1 << "\n"
           << 0 << "\n";
    if (arr[0][0] == 1)
      cout << 0 << "\n"
           << 0 << "\n"
           << 1 << "\n";
    return 0;
  }

  func(0, 0, n);

  cout << ans[0] << "\n"
       << ans[1] << "\n"
       << ans[2] << "\n";

  return 0;
}