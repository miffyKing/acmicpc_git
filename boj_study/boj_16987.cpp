
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxval = -1;
int visited[100002][4];
int sero;

vector<vector<int>> land2;

 void func(int s, int g, int score)
{
    if(s == sero-1)
    {
        if (maxval < score + land2[s][g])
            maxval =score + land2[s][g];
        return;
    }
    cout<<"!!!!!!!!!!!!!!!!!!!!!\n";
    score += land2[s][g];
    cout<<"land2[s][g] is : " << land2[s][g]<<'\n';
    for(int i =0;i<4; i++)
    {
        if (i == g)
            continue;
        func(s+1, i, score);
    }
}

int main()
{
    vector<vector<int>>land;
    land.push_back({1,2,3,5});
    land.push_back({5,6,7,8});
    land.push_back({4,3,2,1});
    int answer = 0;
    sero = 3;
    for(int i = 0; i< land.size(); i++)
        land2.push_back(land[i]);
    //if(i=0;i<4;i++) 해서 현재있는 자리 바로 밑 말고는 다 호출.. 백트래킹
    vector<int> ans;
    //cout<<"!!!\n";
    func(0,0,0);
    func(0,1,0);
    func(0,2,0);
    func(0,3,0);
    
   // sort(ans.begin(), ans.end());
    //answer = ans[0];
    cout<<maxval;
    return answer;
}
