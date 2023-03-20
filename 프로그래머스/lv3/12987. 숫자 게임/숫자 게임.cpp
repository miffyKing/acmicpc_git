#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = -1;
    vector<pair<int,int>> total;
    for(int i = 0; i < A.size(); i++)
    {
        total.push_back({A[i], 0});
        total.push_back({B[i], 1});
    }
    sort(total.begin(), total.end());

    deque<int> st; 
    int cnt = 0;
    for (int i = 0; i < total.size(); i++)
    {
        if (total[i].second == 1) //B팀
        {
            //여기서 스택 사이즈를 비교를 해서 뺄수 있으면 맨 밑 스택을 빼자.
            if (st.size() != 0)
            {
                int comp = st.back();
                //st.pop_back();
                //st.pop_back();
                if (comp != total[i].first)
                {
                    st.pop_back();
                   cnt++; 
                }  

            }
        }
        else
        {
            st.push_front(total[i].first); //A팀
        }
    }

    answer = cnt;
    cout<<cnt;


    return answer;
}