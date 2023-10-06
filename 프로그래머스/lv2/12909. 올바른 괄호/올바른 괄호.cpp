#include<string>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack <int> st;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(0);
        else if (s[i] == ')')
        {
            if (st.empty())
                return false;
            else 
                st.pop();
            
        }
    }
    if (!st.empty())
        return false;
    return true;    
    // return answer;
}