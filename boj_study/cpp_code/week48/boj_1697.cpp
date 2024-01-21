#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

int n, k;
int isvisited[200002];
int arr[200002];
queue<int> q;

int main()
{
  cin >> n >> k;

  isvisited[n] = 1;
  q.push(n);

  while (!q.empty())
  {
    if (q.front() == k)
    {
      cout << isvisited[k] - 1 << "\n";
      break;
    }
    int cur = q.front();
    q.pop();

    for (int i = 0; i < 3; i++)
    {
      if (cur + 1 < 200002 && isvisited[cur + 1] == 0)
      {
        q.push(cur + 1);
        isvisited[cur + 1] = isvisited[cur] + 1;
      }

      if (cur - 1 >= 0 && isvisited[cur - 1] == 0)
      {
        q.push(cur - 1);
        isvisited[cur - 1] = isvisited[cur] + 1;
      }

      if (cur * 2 < 200000 && isvisited[cur * 2] == 0)
      {
        q.push(cur * 2);
        isvisited[cur * 2] = isvisited[cur] + 1;
      }
    }
  }

  return 0;
}