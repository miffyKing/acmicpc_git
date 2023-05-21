#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int table[1000002];
int visited[1000002];

int main()
{
    int f,s,g,u,d;
    queue<int> q;
    
    cin>>f>>s>>g>>u>>d;
    
    q.push(s);
    visited[s] = 1;
    
    while (!q.empty())
    {
        //cout<<q.front()<<'\n';
        int cur = q.front();
        q.pop();
        
        if (cur + u > 0 && cur + u <= f && visited[cur + u] == 0)
        {
            visited[cur+u] = visited[cur] + 1;
            q.push(cur + u);
        }
        
        if (cur - d > 0 && cur - d <= f && visited[cur - d] == 0 )
        {
            visited[cur-d] = visited[cur] + 1;
            q.push(cur - d);
        }
    }
    if (visited[g] == 0)
    {
        cout<< "use the stairs\n";
        return 0;
    }
    cout<< visited[g] - 1<<'\n';
    
}
