
#include <stdio.h>
#include <iostream>
#include <vector>
//#include <pair>

using namespace std;

int table[5][5];
int isused[5][5];
int buffer[10];
pair<int,int> buffer2[10];
int cnt = 0;
int dirx[4] = {0, 1, 0, -1};
int diry[4] = {1, 0, -1, 0};

void func(int x, int y, int cur)
{
    //x, y 에 대해 상하좌우에 대해서 전부다 func를 호출한다. cur++ .
    //cur가 7에 달했을 때 이다솜이 4개 이상인 경우 cnt증가시켜줌.
    if (x < 0 || x >=5 || y < 0 || y >= 5)
        return;
    if (cur == 7)
    {
       // cout<<"!!!!\n";
        int s_cnt = 0;
        for(int i = 0; i< 7; i++)
        {
            //cout<<buffer[i] << ' ';
           // cout<< buffer2[i].first << ' ' << buffer2[i].second << '\n';
            if(buffer[i] == 2)
                s_cnt++;
        }
        if(s_cnt >= 4)
        {
            for(int i = 0; i< 7; i++)
            {
                cout<< buffer2[i].first << ' ' << buffer2[i].second << '\n';
            }
            cnt++;
            cout<<'\n';
        }
        return;
    }
    if(isused[x][y] != 1)
    {
        for(int i = 0; i< 4; i++)
        {
            isused[x][y] = 1;
            buffer[cur] = table[x][y];
            buffer2[cur].first = x;
            buffer2[cur].second = y;
            
            func(x+dirx[i], y+diry[i], cur+1);
            isused[x][y] = 0;
        }
    }
}


int main()
{
    char tmp;
    for(int i = 0; i< 5; i++)
    {
        for(int j = 0; j< 5; j++)
        {
            cin>>tmp;
            if(tmp == 'Y')
                table[i][j] = 1;
            else if(tmp == 'S')
                table[i][j] = 2;
        }
    }
    
    for(int i = 0; i< 5; i++)
    {
        for(int j = 0; j< 5; j++)
        {
            func(i, j, 0);
        }
    }
    
    cout<<cnt << '\n';
    return 0;
}
