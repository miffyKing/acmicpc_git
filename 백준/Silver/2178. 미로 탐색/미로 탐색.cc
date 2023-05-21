#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int table[102][102];
int visited[102][102];
queue<pair<int,int>>q;
int dirx[4] = {0, -1, 0 , 1};
int diry[4] = {1, 0, -1, 0};

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0; i< n; i++)
    {
        string tmp;
        cin>>tmp;
        for(int j = 0; j < m ; j++)
        {
            table[i][j] = tmp[j] - '0';
        }
    }
    q.push(make_pair(0,0));
    visited[0][0] = 1;
    while(!q.empty())
    {
        pair<int,int> cur = q.front(); q.pop();
        for(int i = 0; i <4; i++)
        {
            int newX = cur.first + dirx[i];
            int newY = cur.second + diry[i];
            if (table[newX][newY] == 0 || visited[newX][newY] >= 1) continue;
            if (newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
            visited[newX][newY] = visited[cur.first][cur.second] + 1;
            q.push(make_pair(newX, newY));
        }
    }
    cout<<visited[n-1][m-1];
    return 0;
}
