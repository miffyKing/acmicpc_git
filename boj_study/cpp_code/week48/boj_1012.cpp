#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

int main()
{
  int t;
  int m, n, k;

  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> m >> n >> k;
    int arr[52][52];
    int isvisited[52][52];
    memset(isvisited, 0, sizeof(arr));
    memset(arr, 0, sizeof(isvisited));
    int x, y;

    for (int idx = 0; idx < k; idx++)
    {
      cin >> x >> y;
      arr[x][y] = 1;
    }

    int cnt = 0;
    queue< pair<int, int> > q;
    for (int ii = 0; ii < m; ii++)
    {
      for (int jj = 0; jj < n; jj++)
      {
        if (arr[ii][jj] == 1 && isvisited[ii][jj] == 0)
        {
          cnt++;
          q.push(make_pair(ii, jj));

          isvisited[ii][jj] = 1;
          while (!q.empty())
          {
            pair<int, int> cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
              int nX = cur.first + dirX[dir];
              int nY = cur.second + dirY[dir];
              if (nX < 0 || nX >= m || nY < 0 || nY >= n)
                continue;
              if (isvisited[nX][nY] > 0)
                continue;
              if (arr[nX][nY] == 0)
                continue;
              isvisited[nX][nY] = 1;
              q.push(make_pair(nX, nY));
            }
          }
        }
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}