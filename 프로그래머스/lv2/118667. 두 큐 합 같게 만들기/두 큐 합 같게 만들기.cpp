#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    vector<int> total;
    long long sum  = 0;
    for (int i = 0; i < queue1.size(); i++)
    {
        sum += queue1[i];
        total.push_back(queue1[i]);
    }
    for (int i = 0; i < queue2.size(); i++)
    {
        sum += queue2[i];
        total.push_back(queue2[i]);
    }
    if (sum % 2 == 1)
    {
        return -1;
    }
    int begin = 0;
    int end = queue1.size();
    
    long long halfsum1 = 0;
    long long halfsum2 = 0;
    
    for (int i = 0;i < queue1.size(); i++)
    {
        halfsum1 += total[i];
    }
    for (int i = queue1.size(); i < queue1.size()*2; i++)
    {
        halfsum2 += total[i];
    }
    
    cout<<halfsum1 << " " << halfsum2 << "\n";
    
    int cnt = 0;
    for (int i = 0; i < queue1.size() * 3; i++)
    {
        if (halfsum1 == halfsum2)
        {
            return cnt;
        }
        if (end == total.size())
        {
            end = 0;
        }
        if (halfsum1 < halfsum2)
        {
            halfsum1 += total[end];
            halfsum2 -= total[end];
            end++;
            cnt++;
        }
        else
        {
            halfsum1 -= total[begin];
            halfsum2 += total[begin];
            begin++;
            cnt++;
        }
    }
    
    //sum 을 정확히 절반으로 나누는 경우를 찾자.
    
    return answer;
}