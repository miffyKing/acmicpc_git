#include <iostream>
#include <vector>

using namespace std;

int visited[500002] = {0,};
vector<int> lst[500002];

long sum = 0;

void dfs(int cur, int cnt)
{
    if (lst[cur].size() == 1 && cur != 1)
    {
        sum += cnt;
        return;
    }
    for (int i = 0; i < lst[cur].size(); i++)
    {
        if(visited[lst[cur][i]] ==0 )
        {
            visited[lst[cur][i]] = 1;
            dfs(lst[cur][i], cnt + 1);
            visited[lst[cur][i]] = 0;
        }
    }
}
int main()
{
    int n;
    int a, b;
    cin>>n;
    
    for (int i = 0; i < n-1; i++)
    {
        cin>>a>>b;
        lst[a].push_back(b);
        lst[b].push_back(a);
    }
    
    visited[1] = 1;
    dfs(1,0);
    
    if (sum % 2 == 1)
        cout<<"Yes\n";
    else
        cout<< "No\n";
    
    return 0;
}
