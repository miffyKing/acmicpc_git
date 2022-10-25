#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int dp[100004];
//int visited[100004];
vector<int> node[100004];

void dfs_func(int cur);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    
    cin>>n>>m;
    for(int i =1 ; i<= n; i++)
    {
        int upman;      //상사
        cin>>upman;
        if(upman == -1){}
        else
        {
            node[upman].push_back(i);       //이거 없어도 되나 싶다.
        }
    }
    int worker_i, w;
    for(int j =1 ; j<= m; j++)
    {
        
        cin>>worker_i >> w;
        dp[worker_i] += w;
   
    }
    dfs_func(1);
    
    for(int i =1; i<=n; i++)
    {
        cout<<dp[i]<< ' ';
    }
    cout<<'\n';
    
    return 0;
}

void dfs_func(int cur)
{
    for(int i =0; i < node[cur].size(); i++)
    {
        dp[node[cur][i]] += dp[cur];            //어차피 자기보다 밑에있는 건 다 칭찬받으니까
        dfs_func(node[cur][i]);
    }
}

//내가 시간초과 낸 코드..
/*
 #include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <iostream>

 using namespace std;

 int dp[100004];
 //int visited[100004];
 vector<vector<int>> node;

 int dfs_func(int cur, int w);

 int main()
 {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     
     int n, m;
     
     cin>>n>>m;
     node.resize(n+1);

     for(int i =1 ; i<= n; i++)
     {
         int upman;
         cin>>upman;
         if(upman == -1){}
         else
         {
             node[upman].push_back(i);       //이거 없어도 되나 싶다.
         }
     }
     for(int j =0 ; j< m; j++)
     {
         int worker_i, w;
         cin>>worker_i >> w;
         dfs_func(worker_i, w);
    
     }
     
     for(int i =1; i<=n; i++)
     {
         cout<<dp[i]<< ' ';
     }
     cout<<'\n';
     
     return 0;
 }

 int dfs_func(int cur, int w)
 {
     for(int i =0; i < node[cur].size(); i++)
     {
         int next_tmp = node[cur][i];
         dfs_func(next_tmp, w);
     }
     dp[cur] += w;
     return dp[cur];
 }


 */
