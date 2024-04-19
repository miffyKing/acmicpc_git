#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// priority_queue<int> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        q2(scoville.begin(), scoville.end());
    int cnt = 0;
    
    while(1)
    {
        if (q2.size() >= 2)
        {
            int num1 = q2.top();
            q2.pop();
            int num2 = q2.top();
            q2.pop();
            if (num1 < K|| num2 < K)
            {
                q2.push(num1 + num2 *2);
                cnt++;
            }
            else
                break;
        }
        else
            break;
    }
    if (q2.top() < K)
        return -1;
    return cnt;
}