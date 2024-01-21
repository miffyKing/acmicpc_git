#include <iostream>
#include <queue>
#include <utility>
#include <math.h>

using namespace std;

int n, m;
int isVisited[102][102];
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};
int arr[102][102];
int minVal = 10000;

void dfs(pair<int, int> cur)
{

  queue<pair<int, int> > q;
  q.push(cur);

  while (!q.empty())
  {
    int curX = q.front().first;
    int curY = q.front().second;
    if (curX == n - 1 & curY == m - 1)
    {
      minVal = min(minVal, isVisited[curX][curY]);
    }
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int newX = curX + dirX[i];
      int newY = curY + dirY[i];

      if (isVisited[newX][newY] > 0 )
        continue;
      if (arr[newX][newY] == 0)
        continue;
      if (newX < 0 || newX >= n || newY < 0 || newY >= m)
        continue;

      isVisited[newX][newY] = isVisited[curX][curY] + 1;
      q.push(make_pair(newX, newY));
      
    }
  }
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < m; j++)
    {
      arr[i][j] = tmp[j] - '0';
    }
  }
  isVisited[0][0] = 1;
  dfs(make_pair(0, 0));
  cout<<minVal <<"\n";
  return 0;
}