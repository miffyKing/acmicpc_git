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


using namespace std;

int min_val = 100;
int n,m;
int table[10][10];
int tmp_table[10][10];
int counter =0;
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, -1, 0, 1};
int ans= -1;
void count_virus()
{
    int spreaded[8][8];
    queue <pair<int, int>> q;
    
    //memcpy(spreaded, tmp_table, sizeof(int)*n*m);
    for(int i =0; i< n; i++)
    {
        for(int j =0; j< m; j++)
        {
            spreaded[i][j] = tmp_table[i][j];
        }
    }
    for(int i =0; i<n; i++)
    {
        for(int j =0; j <m; j++)
        {
            if(spreaded[i][j] == 2)
            {
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i =0; i<4; i++)
        {
            int new_x = x +dir_x[i];
            int new_y = y + dir_y[i];
            if(new_x>=0 && new_y>= 0 && new_x <n && new_y < m)
            {
                if(spreaded[new_x][new_y] == 0)
                {
                    spreaded[new_x][new_y] = 2;
                    q.push(make_pair(new_x, new_y));
                }
            }
        }
        
    }
    
    int cnt = 0;
    for(int i =0; i< n; i++)
    {
        for(int j =0; j< m ; j++)
        {
            if(spreaded[i][j] == 0)
                cnt++;
        }
    }
    ans = max(ans, cnt);
    
}
void select_three(int cnt)
{
    if(cnt == 3)
    {
        count_virus();
        return;
       // virus();
    }
    for(int i = 0; i< n; i++)
    {
        for(int j=0;j<m; j++)
        {
            if(tmp_table[i][j] ==0)
            {
                tmp_table[i][j] = 1;
                select_three(cnt+1);
                tmp_table[i][j] =0;
            }
        }
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j< m; j++)
        {
            cin>>table[i][j];
        }
    }
   // cout<<"씨발\n";
    //memcpy(tmp_table, table,sizeof(int)*m*n);

    
    for(int i =0; i< n; i++)
    {
        for(int j =0; j<m; j++)
        {
            if(table[i][j] == 0)
            {
                //memcpy(tmp_table, table,sizeof(int)*m*n);
                for(int x =0; x < n; x++)
                {
                    for(int y =0; y< m; y++)
                    {
                        tmp_table[x][y] = table[x][y];
                    }
                }
                tmp_table[i][j] = 1;
                select_three(1);
                tmp_table[i][j] = 0;
            }
        }
    }
    cout<<ans;
    return 0;
}

