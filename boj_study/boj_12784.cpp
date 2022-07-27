#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

//int dp[100004];
int visited[100004];
vector<pair<int,int>> node[100004];
vector<int> dynamite;

int dfs_func(int cur, int cost);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int T_num, island_n, bridge_m;
    int s1,s2, d;
    cin>>T_num;
    for(int tc = 0 ; tc < T_num ; tc++)
    {
        
        cin>>island_n>>bridge_m;
  
        memset(node, 0, sizeof(node));
        memset(visited, 0, sizeof(visited));
        for(int  i = 0; i < bridge_m; i++)
        {
            cin>>s1>>s2>>d;
            node[s1].push_back(make_pair(s2, d));
            node[s2].push_back(make_pair(s1, d));       //트리만들고
        }
      
        int tmp = dfs_func(1, 1e9);               //최소값 찍어내
        if(tmp == 1e9)
            cout<<0<<'\n';
        else
            cout<<tmp<<'\n';
    }
    
    return 0;
}

int dfs_func(int cur, int cost)
{
    int ret = cost;
    int child = 0;
    int flag =0;
    visited[cur] = 1;
    for(int i = 0 ; i < node[cur].size(); i++)
    {
        int next_tmp = node[cur][i].first;
        int next_cost = node[cur][i].second;
        
        if(!visited[next_tmp])
        {
            child += dfs_func(next_tmp, next_cost);
            flag = 1;
        }
    }
    if(!flag)
        return ret;
    else
    {
        ret = min(ret, child);
        return ret;
    }
}

