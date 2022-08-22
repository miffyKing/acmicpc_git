//
//  boj_2468.cpp
//  boj_study
//
//  Created by 조병화 on 2022/08/22.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int table[102][102];


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int main()
{
    int n;
    int min = 100;
    int max = 2;
    cin >>n;
    for(int i = 0; i < n ;i++)
    {
        for (int j = 0; j <n ; j++)
        {
            cin>> table[i][j];
            if (table[i][j] < min)
                min = table[i][j];
            if (table[i][j] > max)
                max = table[i][j];
        }
    }
    //일단 테이블에 다 담고,
    //최소값부터 최대값까지 물이 찼을 때의 지역의 개수를 세면서(bfs)
    //안전영역 개수가 최대인걸 계속 갱신해준다.
    int answer = -1;
    for (int idx = min; idx <= max; idx++)
    {
        queue<pair<int,int>>q;
        int visit[102][102];
        for(int i =0; i< 102; i++)
            for(int j = 0; j< 102; j++)
                visit[i][j] = 0;
        int tmp_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (table[i][j] > idx)
                {
                    if (visit[i][j] == 1)
                        continue;
                    tmp_cnt++;
                    visit[i][j] = 1;
                    q.push(make_pair(i,j));
                    while (!q.empty())
                    {
                        pair<int,int> cur = q.front(); q.pop();
                        for (int dir = 0; dir <4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            if (visit[nx][ny] >= 1) continue;
                            if (table[nx][ny] <= idx) continue;
                            visit[nx][ny] = 1;
                            q.push(make_pair(nx,ny));
                        }
                    }
                }
                
            }
        }
        
        if (tmp_cnt > answer)
            answer = tmp_cnt;
        if(answer == 0)
            answer = 1;
    }
    cout<<answer<<'\n';
        ///bfs 진행
    
    return (0);
}
