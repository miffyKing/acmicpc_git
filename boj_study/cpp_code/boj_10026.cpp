#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int get_cnt_bycolor(char tmp);
int get_cnt_bycolor2(char tmp);


char table[102][102];
char table2[102][102];
int n;
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1,0,-1, 0};

int main()
{
    string input;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>input;
        for (int j =0; j< n; j++)
        {
            table[i][j] = input[j];
            table2[i][j] = input[j];
            if (input[j] == 'G')
            {
                table2[i][j] = 'R';
            }
        }
    }
    
    int cnt_normal = 0;
    
    cnt_normal += get_cnt_bycolor('R');
    cnt_normal += get_cnt_bycolor('G');
    cnt_normal += get_cnt_bycolor('B');

    int cnt_normal2 = 0;
    
    cnt_normal2 += get_cnt_bycolor2('R');
    cnt_normal2 += get_cnt_bycolor2('B');

    cout<<cnt_normal << " " << cnt_normal2 << '\n';
    
    return 0;
}

int get_cnt_bycolor2(char target)
{
    queue <pair<int,int>>q;
    int visited2[102][102] = {0};
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table2[i][j] == target && visited2[i][j] == 0)
            {
                q.push({i,j});
                cnt++;
            
                while (!q.empty())
                {
                    pair<int,int> cur= q.front();
                    q.pop();
                    for(int i = 0; i < 4; i++)
                    {
                        int c_x = cur.first + dir_x[i];
                        int c_y = cur.second + dir_y[i];
                        if (c_x < 0 || c_x >= n || c_y < 0 || c_y >=n)continue;
                        if (visited2[c_x][c_y] == 1 || table2[c_x][c_y] != target) continue;
                        visited2[c_x][c_y] = 1;
                        q.push({c_x, c_y});
                    }
                }
            }
        }
    }
 
    return cnt;
}

                
int get_cnt_bycolor(char target)
{
    queue <pair<int,int>>q;
    int visited[102][102] = {0};
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] == target && visited[i][j] == 0)
            {
                q.push({i,j});
                cnt++;
                
                while (!q.empty())
                {
                    pair<int,int> cur= q.front();
                    q.pop();
                    for(int i = 0; i < 4; i++)
                    {
                        int c_x = cur.first + dir_x[i];
                        int c_y = cur.second + dir_y[i];
                        if (c_x < 0 || c_x >= n || c_y < 0 || c_y >=n)continue;
                        if (visited[c_x][c_y] == 1 || table[c_x][c_y] != target) continue;
                        visited[c_x][c_y] = 1;
                        q.push({c_x, c_y});
                    }
                }
            }
        }
    }
 
    return cnt;
}

