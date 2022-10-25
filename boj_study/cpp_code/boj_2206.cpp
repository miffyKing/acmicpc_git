#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include<queue>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>
//#include <string.h>

int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};

using namespace std;

int n,m;
int table[1002][1002];
int tmp_table[1002][1002];
//int cnt;
int min_val = 1000002;


void dfs_func()
{
    int cnt = 1;
    queue<pair<int,int>> q;
    
    q.push(make_pair(0,0));
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k =0; k< 4; k++)
        {
            if(x + dir_x[k] >=0 && x + dir_x[k] < n && y+dir_y[k] >= 0 && y+dir_y[k] < m)
            {
                if(tmp_table[x+dir_x[k]][y+dir_y[k]] == 0)
                {
                    q.push(make_pair(x+dir_x[k], y+dir_y[k]));
                    cnt++;
                }
            }
            if(x+dir_x[k] == n-1 && y+dir_y[k] == m-1)
            {
                min_val = min(min_val, cnt);
                return;
            }
            
        }
    }
    
}
void table_copy(int x, int y)
{
    for(int i =0; i< n; i++)
    {
        for(int j =0; j <  m ; j++)
        {
            tmp_table[i][j] = table[i][j];
        }
    }
    tmp_table[x][y] = 0;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string tmp;
    cin>>n>>m;
    cin.ignore();
    
    for(int i =0;i <n; i++)
    {
        for(int j =0; j <m; j++)
        {
            char tmp;
            cin>>tmp;
            if(tmp== '0')
                table[i][j] = 0;
            else
                table[i][j] =1;
                
        }
        cin.ignore();
    }
    
    for(int i =0; i< n; i++)        //1개씩 벽없는 테이블 만들어서 bfs시작하자
    {
        for(int j =0; j <m; j++)
        {
            if(table[i][j] == 1)
            {
                table_copy(i, j);
                dfs_func();
                
            }
        }
    }
    cout<<min_val<<'\n';
    
}
