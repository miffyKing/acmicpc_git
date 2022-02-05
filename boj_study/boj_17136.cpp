#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>
//#include <string.h>


using namespace std;

int table[11][11];
int onecnt =0;              //처음에 주어진 1의 개수
int paper_cnt =0;           //붙인 색종이의 개수
int ret = 0x7fffffff;
int use[6] = {0,5,5,5,5,5};

bool available(int sero, int garo, int size)
{
    int tmp =0;
    if(use[size] == 0)                                      //그 사이즈 색종이를 5장 다 사용했으면 안되노
        return false;
    if(sero + size >11 || garo + size > 11)                 //영ㅇ역 범위를 넘어가면 터지고
        return false;
    
    
    for(int i =sero; i < sero+size; i++)                  //3x3짜리를 예로 1의 합이 9가 안되면 터지고
        {
            for(int j = garo; j<garo+size; j++)
            {
                if(table[i][j] == 1)
                    tmp++;
            }
        }
        if(tmp == size*size) return true;
        else return false;
    
}
void dfs_func(int depth, int y, int x)
{
    if(onecnt == 0)
    {
        ret = min(ret, depth);
        return;
    }
   // cout<<"????\n";
    for(int i = y; i<= 10; i++)
    {
        for(int j=x; j<=10; j++)
        {
            if(table[i][j] == 1)
            {
                for(int k = 5; k>=1; k--)
                {
                    if(available(i,j,k) )
                    {
                       // cout<< "Available i, j are " <<i<<' ' << j <<'\n';
                        
                        use[k]--;       //색종이한장 쓰고
                        int sero =i; int garo = j;
                        for(int X = sero; X< sero+k; X++)
                        {
                            for(int Y = garo; Y < garo+k; Y++)
                            {
                                table[X][Y] = 0;
                            }
                        }
                        onecnt = onecnt-(k*k);
                        //이렇게 까지 하면 색종이를 붙인경우니까 1이었던거 0으로 바꿔줌, 총 1의 개수를 줄여줘야함
                        
                        dfs_func(depth+1, i, j+k);                // dfs 돌려줘서 i,j,부터 다시 탐색시작
                        
                        //depth 하나 감소한거에서부터 다시 시작해봐야함
                        onecnt = onecnt+(k*k);                  //다시 원래대로 돌려야지
                        use[k]++;
                        sero =i;  garo = j;
                        for(int X = sero; X< sero+k; X++)
                        {
                            for(int Y = garo; Y <garo+k; Y++)
                            {
                                table[X][Y] = 1;
                            }
                        }
                        
                    }
                    
                }
                return;
            }
        }
        x =0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i =1; i<= 10; i++)
    {
        for(int j =1; j<= 10; j++)
        {
            cin>>table[i][j];
            if(table[i][j] == 1)
                onecnt++;
        }
    }
    
    dfs_func(0,1,1);
    
    if(ret == 0x7fffffff)
        cout<<-1<<'\n';
    else
        cout<<ret<<'\n';
    
    return 0;

}

