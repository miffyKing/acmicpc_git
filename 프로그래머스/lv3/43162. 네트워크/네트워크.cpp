#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue <int> q;
int visited[202] = {0,};
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    // 처음부터 시작해서, 1인 애들을 전부다 큐에 넣었다가 팝해주면서 시작점에서 이어진 애들 전부 다 체크, visited 해놓기
    // visited 안 된 점을 또 큐에 푸시하고 같은 동작반복
    // for문을 컴퓨터 사이즈 만큼 돌리고, 그안에서 dfs 반복하면 될거같음.
    int cnt = 0;
    for(int i = 0; i< computers.size(); i++)
    {   // 컴퓨터 개수만큼 for문 돌면서
        if (visited[i] == 0) //방문안한 점일 때는 그 점을 푸쉬하고 거기서부터 이어진 간선을 전부 dfs 로 찾아냄.
        {
            q.push(i);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int j = 0; j < computers.size(); j++)
                {
                    if (computers[cur][j] == 1 && visited[j] == 0)
                    {
                        q.push(j);
                        visited[j] = 1;
                    }
                }
                
            }
            cnt++;
        }
    }
    return cnt;
}