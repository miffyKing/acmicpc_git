#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


queue<pair<int, int>> qfire;
queue<pair<int, int>> qhuman;
int xdir[4] = {-1, 0, 1, 0};
int ydir[4] = {0, 1, 0, -1};
int fdist[1002][1002];
int hdist[1002][1002];

int table[1002][1002];
int main()
{
    //불, 지훈이 각각에 대해 bfs 를 돌리는데, 불먼저 돌려서 그 dist 값을 배열하나에 저장
    //이후 지훈이가 갈수있는걸 bfs로 진행하면서 불이 먼저 도달한 경우에는 못가니까 continue
    int r, c;
    cin>>r>>c;
    for(int i = 0; i < r; i++)
    {
        string tmp;
        cin>>tmp;
        for(int j = 0; j < c; j++)
        {
            table[i][j] = tmp[j];
            fdist[i][j] = -1;
            hdist[i][j] = -1;
            if(tmp[j] == 'F')
            {
                qfire.push(make_pair(i,j));
                fdist[i][j] = 0;
            }
            if(tmp[j] == 'J')
            {
                qhuman.push(make_pair(i,j));
                hdist[i][j] = 0;
            }
        }
    }
    while (!qfire.empty())
    {
        auto cur = qfire.front();
        qfire.pop();
        for(int i =0; i< 4; i++)
        {
            int curX = cur.first + xdir[i];
            int curY = cur.second + ydir[i];
            if (curX < 0 || curX >= r || curY < 0 || curY >= c) continue;
            if (fdist[curX][curY] >= 0) continue;
            if (table[curX][curY] == '#') continue;
            fdist[curX][curY] = fdist[cur.first][cur.second] + 1;
            qfire.push(make_pair(curX, curY));
        }
    }
    
    while(!qhuman.empty())
    {
        auto cur = qhuman.front();
        qhuman.pop();
        for(int i =0; i<4; i++)
        {
            int curX = cur.first + xdir[i];
            int curY = cur.second + ydir[i];
            if (curX < 0 || curX >= r || curY < 0 || curY >= c)
            {
                cout<<hdist[cur.first][cur.second] + 1<< '\n';
                return 0;
            }
            if (hdist[curX][curY] >= 0)
                continue;
            if (table[curX][curY] == '#')
                continue;
            if (hdist[cur.first][cur.second] + 1 >= fdist[curX][curY] && fdist[curX][curY] != -1)
                continue;
        
            hdist[curX][curY] = hdist[cur.first][cur.second] + 1;
            qhuman.push(make_pair(curX, curY));
        }
    }
    int ans = 0;
    for (int i = 0; i< c; i++)
    {
        if (hdist[0][i] != 0)
            ans = max(ans, hdist[0][i]);
        if (hdist[r-1][i] != 0)
            ans = max(ans,hdist[r-1][i]);
    }
    for (int i = 0; i < r; i++)
    {
        if (hdist[i][0] != 0)
            ans = max(ans, hdist[i][0]);
        if (hdist[i][c-1] != 0)
            ans = max(ans, hdist[i][c-1]);
    }

    if (ans ==0 )
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    cout<<ans<<'\n';
    return 0;
}
