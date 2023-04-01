#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,long long>> v[5002];
int visited[5002] = {0,};
long long max_val = 0;

void dfs(int x, long long p)
{
    for (int i = 0; i < v[x].size(); i++)
    {
        if (visited[v[x][i].first] == 0 )
        {
            visited[v[x][i].first] = 1;
            dfs(v[x][i].first, p + v[x][i].second);
        }
    }
    max_val = max(max_val, p);
    return;
}

int main()
{
    int n;
    cin>>n;
    for (int i =0; i < n-1; i++)
    {
        int a,b;
        long long c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    //visited[1] = 1;
    dfs(1, 0);
    cout<< max_val<<"\n";
    return 0;
}
