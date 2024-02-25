#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

vector<pair<int,int>> arr;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> st;
    
    for (int i = numbers.size() - 1; i >= 0; i--)
    {
        while(1)
        {
            if (st.empty())
            {
                answer.push_back(-1);
                //st.pop();
                break;
            }
            if (st.top() > numbers[i])
            {
                answer.push_back(st.top());
                //st.pop();
                break;
            }
            else
                st.pop();
        }
        st.push(numbers[i]);
    }
    vector<int> reverseAnswer;
    for (int i = 0; i < numbers.size(); i++)
    {
        reverseAnswer.push_back(answer[numbers.size()-i-1]);
    }
    
    return reverseAnswer;
}