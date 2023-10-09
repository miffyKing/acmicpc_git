#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include<queue>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int>s;
    for(int i =0; i < progresses.size(); i++)
    {
        int left_progress =  100 - progresses[i];
        int left_days = left_progress/speeds[i];
        if(left_progress % speeds[i] != 0)
        {
            left_days++;
        }
        
        if(s.empty())
        {
            s.push_back(left_days);   
        }
        else if(s.front() < left_days)
        {
            int cnt =0;
            while(!s.empty())
            {
                s.pop_back();
                cnt++;
            }
            answer.push_back(cnt);
            s.push_back(left_days);
        }
        else
        {
            s.push_back(left_days);
        }
        
    }
    
    if( ! s.empty() )
    {
        int cnt =0;
        while(!s.empty())
        {
            s.pop_back();
            cnt++;
        }
        answer.push_back(cnt);
    }
    
    
    /*
    cout<< "ANSWER SIZE " << answer.size()<<'\n';
    for(int i =0; i< answer.size(); i++)
    {
        cout<<answer[i]<< ' ';
    }
    */
    
    
    return answer;
}