//
//  boj_5014.cpp
//  boj_study
//
//  Created by 조병화 on 2022/08/24.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int visited[1000002] = {0,};
queue <int> q;

int main()
{
    int f,s,g,u,d;
    //F층 까지 있으니까 그 만큼의 visited 배열을 만들고,
    //F 이상으로는 못가게 제한을 해주어야 함.
    //G층에서 시작해서 U만큼 내려가고, D 만큼 올라가도록 해서, 결국 2진 트리처럼 구성이 되겠지?
    // 그 경우 visited 에다가 몇번 째 이동인지를 체크해주고, 이미 방문한 지점이면 continue ? 아님 대소비교 -> 대소비교가 낫겠노
    // 다 탐색을 하고 왔는데도 S층의 visited가 -1이면 계단타염
    // visited 값을 대소비교해서 더 작은 값으로 그때그때 업데이트 해주자!
    cin>>f>>s>>g>>u>>d;
    int step = 1;
    q.push(s); visited[s] = step;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        if (cur == g)
        {
            cout<< visited[g] - 1 <<'\n';
            return 0;
        }
        int next;
        next = cur + u;
        
        if (next <= f && visited[next] == 0) {
            q.push(next);
            visited[next] = visited[cur] + 1;
        }
        next = cur - d;
        if (next > 0 && visited[next] == 0 ) {
            q.push(next);
            visited[next] = visited[cur] + 1;
        }
    }
    cout <<"use the stairs\n";
    return 0;
}
