#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int table[1002][1002];
int visited[1002][1002];
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};
queue<pair<int,int> >q;

int main()
{
    int n, m;
    
    cin>>m>>n;
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< m; j++)
        {
            cin>>table[i][j];
            if (table[i][j] == 1){
                q.push(make_pair(i,j));
            }
            if (table[i][j] == 0)
                visited[i][j] = -1;
        }
    }
    while (!q.empty())
    {
        pair<int,int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++)
        {
            int newX = cur.first + dirx[i];
            int newY = cur.second + diry[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
          //  if (table[newX][newY] == 1 || table[newX][newY] == -1) continue;
            if (visited[newX][newY] >= 0) continue;
            visited[newX][newY] = visited[cur.first][cur.second]+1;
            q.push(make_pair(newX, newY));
        }
    }
    int maxval = 0;
    for(int i =0; i< n; i++)
    {
        for(int j =0; j <m ;j++)
        {
            if(visited[i][j] == -1)
            {
                cout<< -1;
                return 0;
            }
            maxval = max(maxval, visited[i][j]);
        }
    }
  cout<<maxval<<'\n';
    //return 0;
    
   // return (0);
}
