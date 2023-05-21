#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int visited[100001];
int n, k;
queue<int> q;

int main()
{
  cin >> n >> k;
  visited[n] = 1;
  q.push(n);
  if (n == k)
  {
    cout << 0 << "\n";
    return 0;
  }

  while (!q.empty())
  {
    int cur = q.front();
    // q.pop();
    int new_pos;
    if (cur == k)
    {
      cout << visited[cur] << "\n";
      return 0;
    }
    new_pos = cur * 2;
    if (new_pos <= 100000 && visited[new_pos] == 0)
    {
      visited[new_pos] = visited[cur];
      q.push(new_pos);
    }
    new_pos = cur - 1;
    if (new_pos >= 0 && visited[new_pos] == 0)
    {
      visited[new_pos] = visited[cur] + 1;
      q.push(new_pos);
    }
    new_pos = cur + 1;
    if (new_pos <= 100000 && visited[new_pos] == 0)
    {
      visited[new_pos] = visited[cur] + 1;
      q.push(new_pos);
    }
    q.pop();
  }

  return 0;
}