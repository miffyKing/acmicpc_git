#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    pair<int,int> ans;
    int start = 0;
    int end = 0;
    int length = sequence.size();
    int partial_sum = sequence[0];
    
    ans = make_pair(1000000,1000000);  //길이와 종료지점 pair
    
    cout<< length;
    
    while (end != length)
    {
        //cout<< start << " " << end << " " << partial_sum << "\n";
        
        if (partial_sum == k)
        {
            //cout<<start << " " << end <<"\n";
            if (end - start < ans.first)
            {
               // cout<<"!!!!\n";
                ans.first = end - start;
                ans.second = start;
            }
            partial_sum -= sequence[start];
            start++;
            //continue;
        }
        
        if (partial_sum < k)
        {
            end++;
            partial_sum += sequence[end];
        }
        else if (partial_sum > k)
        {
            partial_sum -= sequence[start];
            start++;
        }
        
    }
    
    answer.push_back(ans.second);
    answer.push_back(ans.second + ans.first);
    return answer;
}