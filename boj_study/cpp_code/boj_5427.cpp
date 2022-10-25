
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int tc;
    cin>>tc;
    for(int idx = 0;idx < tc; idx++)
    {
        cin >>n>>m;
        string table[1002];
        int dist1[1002][1002];
        int dist2[1002][1002];
        //배열들 전부다 -1로 초기화
        for(int j1 = 0; j1< m; j1++)
        {
            fill(dist1[j1], dist1[j1] +n , -1);
            fill(dist2[j1], dist2[j1] +n , -1);
        }
        for(int j2 = 0; j2 < m; j2++)
            cin>> table[j2];
        queue <pair<int,int>> q1;   //사람
        queue <pair<int,int>> q2;   //불
        //불이 퍼지게 되는 시간 테이블 bfs로 일단 완성
        for(int i = 0; i < m; i++)
        {
            
            for(int j = 0; j < n; j++)
            {
                if (table[i][j] == '*')
                {
                    q2.push(make_pair(i, j));
                    dist2[i][j] = 0;
                }
                if (table[i][j] == '@')
                {
                    q1.push(make_pair(i,j));
                    dist1[i][j] = 0;
                }
            }
        }
        while(!q2.empty())
        {
            //cout<<1<<'\n';
            pair<int, int> cur = q2.front();
            q2.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= m || ny< 0 || ny >=n) continue;
                if (dist2[nx][ny] >= 0 || table[nx][ny] == '#') continue;
                dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
                q2.push(make_pair(nx,ny));
            }
        }
        //상근이가 이동하는 시간 테이블 bfs로 완성
        int flag = 0;
        while (!q1.empty())
        {
            if (flag == 1)
                break;
            pair<int,int> cur = q1.front();
            q1.pop();
            for(int dir = 0; dir< 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                {
                    cout<< dist1[cur.first][cur.second] + 1<<'\n';
                    flag = 1;
                    continue;
                }
                if (dist1[nx][ny] >= 0 || table[nx][ny] == '#') continue;
                if (dist2[nx][ny] != -1 && dist2[nx][ny] <= dist1[cur.first][cur.second] + 1) continue;
                dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
                q1.push(make_pair(nx,ny));
            }
        }
        if (flag != 1)
            cout<<"IMPOSSIBLE\n";
    }
    // 상근이 조건 (1) 이동하려는 테이블에 시간 넣을 때 (cur +1) 이 시간이 불 bfs 테이블이랑 같거나 크면 continue,
    //(2) 이미 방문한 위치면 continue, 0 > 이거나 n,m < 이면 continue.
    // bfs 방문 표시 꼭 하기.
}
