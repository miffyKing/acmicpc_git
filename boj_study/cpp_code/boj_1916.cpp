#include <iostream>
#include <vector>
#include <queue>

using namespace std;



vector<pair<int,int>> table[1002];

int main()
{
    int n, m;
    
    cin>>n;
    cin>>m;  

    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin>>from>>to>>cost;
        table[from].push_back(make_pair(to,cost));
        table[to].push_back(make_pair(to, cost));
    } //맵의 정보들을 테이블에 담음.
    
    int start, dest;
    cin>>start>>dest;

    int table[1002];
    for (int i = 0; i<=n; i++)
    {
        table[i] = 1e9+10;
    }

    priority_queue<pair<int,int>> pq;
    pq.push({0, start});

    while(!pq.empty())
    {
        auto cur = pq.top(); 
        pq.pop();
        
        if(table[cur.first] != cur.first) continue;     //
        
        for (auto nxt : table[cur.first])
        {
            if()
        }

    }



    return 0;
}