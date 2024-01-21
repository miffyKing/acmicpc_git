#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

int n, m;
int arr[1002][1002];
int isVisited[1002][1002];
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};
queue< pair<int, int> > q;

int main()
{
  int m, n;

  cin >> m >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
      if (arr[i][j] == 1)
      {
        isVisited[i][j] = 1;
        q.push(make_pair(i, j));
      }
    }
  }

  while (!q.empty())
  {
    
    int curX = q.front().first;
    int curY = q.front().second;

    //cout<< curX << " " << curY << "\n";
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int newX = curX + dirX[i];
      int newY = curY + dirY[i];

      if (arr[newX][newY] > 0 || arr[newX][newY] == -1)
        continue;
      if (isVisited[newX][newY] > 0)
        continue;
      if (newX < 0 || newX >= n || newY < 0 || newY >= m)
        continue;

      isVisited[newX][newY] = isVisited[curX][curY] + 1;
      q.push(make_pair(newX, newY));
    }
  }

  int minVal = -1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (isVisited[i][j] == 0 && arr[i][j] != -1)
      {
        cout << -1 << "\n";
        return 0;
      }
      else if (isVisited[i][j] > 0)
      {
        minVal = max(minVal, isVisited[i][j]);
      }
    }
  }
  cout << minVal-1 << "\n";
  return 0;
}