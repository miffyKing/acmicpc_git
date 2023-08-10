#include <iostream>

using namespace std;

int v[10][10];
int n;
int ans = 1e9;
bool ch[11] = {
    false,
};

void go(int start, int index, int cnt, int sum)
{
  if (cnt == n)
  {
    if (v[index][start] == 0)
      return;
    if (ans > sum + v[index][start])
      ans = sum + v[index][start];
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (ch[i] == true || v[index][i] == 0)
      continue;
    ch[i] = true;
    go(start, i, cnt + 1, sum + v[index][i]);
    ch[i] = false;
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> v[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    ch[i] = true;
    go(i, i, 1, 0);
    ch[i] = false;
  }
  cout << ans << "\n";
  return 0;
}