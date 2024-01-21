#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <queue>
#include <utility>

using namespace std;

// vector<pair<int,int>> 
int isvisited[502][502] = {0,}; 
int arr[502][502];
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, 1, 0, -1};

int n,m;
int maxSize = -1;
void dfs(int i, int j)
{
  queue<pair<int,int> > q;

  int cnt = 1;
  q.push( make_pair(i, j) );
    
  isvisited[i][j] = 1;

  while(!q.empty())
  {
    int curX = q.front().first;
    int curY = q.front().second;
    q.pop();

    for (int cur =0; cur < 4; cur++)
    {
      int newX = curX + dir_x[cur];
      int newY = curY + dir_y[cur];
      if (newX < 0 || newX >= n || newY < 0 || newY >= m ) continue;
      if (isvisited[newX][newY] == 1) continue;
      if (arr[newX][newY] == 1)
      {
        isvisited[newX][newY] = 1;
        q.push(make_pair(newX, newY));
        cnt++;
      }
    }

  }
  maxSize = max(maxSize, cnt);
}

int main()
{
  cin>>n>>m;
  for (int i = 0; i < n; i++)
  {
    for (int j=0; j < m; j++)
    {
      cin>>arr[i][j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (isvisited[i][j] == 0 && arr[i][j] == 1)
      {
        cnt++;
        dfs(i, j);
        
      }
    }
  }
  if (cnt == 0)
  {
    cout<< "0" << "\n" << "0";
    return 0;
    
  }
  cout<< cnt << "\n" << maxSize << "\n";
  return 0;
}