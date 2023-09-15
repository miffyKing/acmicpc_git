#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

int isvisited[102][102];
int x_dir[4] = {0, -1, 0, 1};
int y_dir[4] = {1, 0, -1, 0};
int ans = INT_MAX;
int n, m;
bool changeflag = false;
queue<pair<pair<int,int>, int>> q;
    
int solution(vector<vector<int>> maps) // maps를 참조로 받음
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    
    pair<int, int> cur;
    cur = make_pair(0, 0);
    
    q.push(make_pair(cur, 0));
    
    int cnt  = 0;
    
    while (!q.empty())
    {
        //cout<<"!!!!\n";
        pair<int,int> cur = q.front().first;
        int parent_cnt = q.front().second;
        int cur_x = cur.first;  int cur_y = cur.second;
        q.pop();
        
        if (cur_x == n-1 && cur_y == m-1)
        {
            changeflag = true;
            cnt = parent_cnt;
            break;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int new_x = cur_x + x_dir[i];
            int new_y = cur_y + y_dir[i];
            if (new_x < 0 || new_x >= n || new_y < 0 || new_y >=m) continue;
            if (maps[new_x][new_y] == 0) continue;
            
            if (isvisited[new_x][new_y] == 0)
            {
                
                isvisited[new_x][new_y] = 1;
                //cnt = parent_cnt+1;
                q.push(make_pair(make_pair(new_x, new_y) , parent_cnt+1));
            }
        }
        
    }
    
    
    if (changeflag == false)
    {
       // cout << -1;
        return -1;
    }
    else
    {
        return cnt + 1;
    }
}





