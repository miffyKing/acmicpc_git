#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int dp[100004];
int visited[100004];
vector<int> node[100004];

int dfs_func(int spot);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,r,q;
    int u,v;
    
    cin>>n>>r>>q;
    
    for(int i = 0; i<n-1; i++)
    {
        cin>>u>>v;
        node[u].push_back(v);
        node[v].push_back(u);       //각 노드에 이어진 선에 이어줌
    }
    /*      //지금 노드에는 자기자신 포함해서 하나씩 더 저장되어있는 상태임 --> 그냥 했던거같앙
    for(int i =1; i<=n; i++)
    {
        cout<<node[i].size() << ' ';
    }
    cout<<'\n';*/
    for(int i =1; i <= n; i++)
    {
        dp[i] = 1;                  //1번 부터 dp값을 1로 초기화 (dp 배열에는 자기자신 포함
                                    //하위 노드 개수를 저장할거에용
    }
    
    dfs_func(r);                    //r부터 dfs 돌리기 시작
    /*
    for(int i = 1; i <=n; i++)
    {
        cout<<dp[i]<< ' ' ;
    }cout<<'\n';*/
    
    for(int i =0; i< q; i++)
    {
        int tmp;
        cin>>tmp;
        cout<<dp[tmp]<<'\n';
    }
    return 0;
}


int dfs_func(int spot)
{
    if(visited[spot]) return dp[spot];
    visited[spot] = 1;              //방문한거 체크
    
    for(int i =0; i< node[spot].size(); i++)
    {
        int next_spot_tmp = node[spot][i];
        if(visited[next_spot_tmp] == 1) continue;         //다음 탐색후보가 visited된 상태면 pass
        dp[spot] = dp[spot] +dfs_func(next_spot_tmp);
    }
    return dp[spot];
}
