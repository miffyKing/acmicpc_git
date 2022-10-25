
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int visited[502][502];
int table[502][502];
int maxval = -1;
int xcor[4] = { -1, 0, 1, 0};
int ycor[4] = {0, 1, 0, -1};
int main()
{
    int n ,m;
    
    cin>>n>>m;
    for(int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>table[i][j];
        }
    }
    int numpic =0;
    for(int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            queue <pair<int,int>> q;
            if (table[i][j] == 1 && visited[i][j] != 1)
            {
                int pic_cnt = 1;
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                while(!q.empty())
                {
                    pair <int, int> cur = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int curX = cur.first + xcor[i];
                        int curY = cur.second + ycor[i];
                        if (curX < 0 || curX >=n || curY < 0 || curY >= m) continue;
                        if (visited[curX][curY] == 1 || table[curX][curY] == 0) continue;
                        q.push(make_pair(curX, curY));
                        visited[curX][curY] = 1;
                        pic_cnt++;
                    }
                }
                if ( pic_cnt > maxval)
                    maxval = pic_cnt;
                numpic++;
            }
        }
    }
    if (maxval == -1) maxval = 0;
    cout<< numpic << '\n' << maxval << '\n';
    return 0;
}
