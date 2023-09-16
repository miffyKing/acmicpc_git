#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>

// 가능 경로가 여러개일 경우 알파벳 순서가 앞서는 경로를 먼저 출력하라. -> bfs?
// 방문 못하는 경우는 안주어진다고 하니 그냥 dfs 로 풀어도 되지 않을까?
// dfs 는 재귀를 이용하자.

using namespace std;

bool check = false;
vector<string> answer;
int visited[100000002];

void dfs(string cur, vector<vector<string>> tickets, int cnt)
{
    if (cnt == tickets.size())
    {
        check = true;
        //return ; 
    }
    
    answer.push_back(cur);
    for (int i = 0; i < tickets.size(); i++)
    {
        if (visited[i] == 0 && tickets[i][0] == cur)
        {
            visited[i] = 1;
            dfs(tickets[i][1], tickets, cnt+1);
            if (check == false)
            {
                
                answer.pop_back();
                visited[i] = 0;
            }
            
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    

    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, 0);
    
    return answer;
}