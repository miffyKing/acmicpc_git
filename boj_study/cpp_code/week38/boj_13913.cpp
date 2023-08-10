#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int visited[100005] = {
    0,
};
// vector<int> lst[100002];
int parent[100002];

int main()
{
  int n, k;
  cin >> n >> k;

  queue<pair<int, int>> q;
  q.push(make_pair(n, 0));
  // visited[n] = 1;

  while (!q.empty())
  {
    pair<int, int> cur = q.front();
    q.pop();

    visited[cur.first] = 1;

    if (cur.first == k)
    {
      cout << cur.second << "\n";

      vector<int> ans_lst;
      int new_val = cur.first;
      ans_lst.push_back(new_val);
      for (int i = 0; i < cur.second; i++)
      {
        ans_lst.push_back(parent[new_val]);
        new_val = parent[new_val];
      }
      for (int i = cur.second; i >= 0; i--)
      {
        cout << ans_lst[i] << " ";
      }
      return 0;
    }

    if (cur.first - 1 >= 0 && cur.first - 1 <= 100000)
    {
      if (visited[cur.first - 1] == 0)
      {
        visited[cur.first - 1] = 1;

        parent[cur.first - 1] = cur.first;

        q.push(make_pair(cur.first - 1, cur.second + 1));
      }
    }

    if (cur.first + 1 >= 0 && cur.first + 1 <= 100000)
    {
      if (visited[cur.first + 1] == 0)
      {
        visited[cur.first + 1] = 1;

        parent[cur.first + 1] = cur.first;

        q.push(make_pair(cur.first + 1, cur.second + 1));
      }
    }

    if (cur.first * 2 >= 0 && cur.first * 2 <= 100000)
    {
      if (visited[cur.first * 2] == 0)
      {
        visited[cur.first * 2] = 1;

        parent[cur.first * 2] = cur.first;

        q.push(make_pair(cur.first * 2, cur.second + 1));
      }
    }
  }
  return 0;
}