#include <string>
#include <vector>
#include <iostream>

using namespace std;

int isvisited[202];

void dfs(int cur, vector<vector<int>> computers, int n)
{
    if (isvisited[cur] == 1)
        return;
    isvisited[cur] = 1;
    
    for (int i = 0; i < n; i++)
    {
        if (computers[cur][i] == 1 && isvisited[i] == 0)
            dfs(i, computers, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (isvisited[i] == 0)
        {
            dfs(i, computers, n);
            cnt++;
        }
    }

    return cnt;
}