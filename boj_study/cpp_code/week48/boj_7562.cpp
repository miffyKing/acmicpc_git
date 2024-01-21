#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#include <string.h>

using namespace std;

int dirX[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dirY[8] = {1, -1, 2, -2, -2, 2, 1, -1};

int main()
{
  int tc;
  cin >> tc;

  for (int t = 0; t < tc; t++)
  {
    int chessSize;
    int fromx, fromy;
    int tox, toy;
    int arr[303][303];
    int isvisited[303][303];
    memset(arr, 0, sizeof(arr));
    memset(isvisited, 0, sizeof(isvisited));
    cin >> chessSize;
    cin >> fromx >> fromy;
    cin >> tox >> toy;

    queue< pair<int, int> > q;
    q.push(make_pair(fromx, fromy));
    isvisited[fromx][fromy] = 1;

    while (!q.empty())
    {
      pair<int, int> cur = q.front();
      q.pop();

      if (cur.first == tox && cur.second == toy)
      {
        cout << isvisited[tox][toy] - 1 << "\n";
        break;
      }

      for (int i = 0; i < 8; i++)
      {
        int newX = cur.first + dirX[i];
        int newY = cur.second + dirY[i];

        if (isvisited[newX][newY] != 0)
          continue;
        if (newX < 0 || newX >= chessSize || newY < 0 || newY >= chessSize)
          continue;

        isvisited[newX][newY] = isvisited[cur.first][cur.second] + 1;
        q.push(make_pair(newX, newY));
      }
    }
  }
  return 0;
}