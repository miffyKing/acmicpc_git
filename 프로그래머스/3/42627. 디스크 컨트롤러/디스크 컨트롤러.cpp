// #include <string>
// #include <vector>
// #include <queue>
// #include <iostream>


// using namespace std;

// priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> lst;

// int solution(vector<vector<int>> jobs) {
//     int answer = 0;
    
//     for (int i = 0; i < jobs.size(); i++)
//     {
//         lst.push(make_pair(jobs[i][0], jobs[i][1]));
//     }
//     int curTime = 0;
    
//     float spentTime =0;
    
//     while (!lst.empty())
//     {
        
//         pair<int,int> tmp = lst.top();
//         lst.pop();
//         if (curTime < tmp.first)
//         {
//             curTime = tmp.first;
//         }
//         curTime = curTime + tmp.second;
//         cout<< (curTime - tmp.first) << "\n";
//         spentTime += (curTime - tmp.first);
//     }
    
//     spentTime /= jobs.size();
//     return (int)spentTime;
// }

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    // 작업을 요청 시간 기준으로 오름차순 정렬
    sort(jobs.begin(), jobs.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 처리 시간 오름차순 정렬
    int curTime = 0, i = 0, total = 0;

    while (i < jobs.size() || !pq.empty()) {
        // 현재 시간 이하로 요청된 모든 작업을 우선순위 큐에 추가
        while (i < jobs.size() && jobs[i][0] <= curTime) {
            pq.push({jobs[i][1], jobs[i][0]}); // {처리 시간, 요청 시간}
            i++;
        }
        
        if (!pq.empty()) {
            // 대기 중인 작업 중 가장 짧은 작업 처리
            curTime += pq.top().first; // 현재 시간 업데이트
            total += curTime - pq.top().second; // 총 대기 시간 업데이트
            pq.pop();
        } else if (i < jobs.size()) {
            // 대기 중인 작업이 없으면, 다음 작업의 요청 시간으로 시간을 업데이트
            curTime = jobs[i][0];
        }
    }
    
    // 평균 대기 시간 계산
    return total / jobs.size();
}
