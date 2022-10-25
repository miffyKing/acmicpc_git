#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;

stack<int> buffer;
long long answer = 0;

void empty_stack()
{
    int n = (int)buffer.size();
    while(n > 0)
    {
        answer -= buffer.top();
        buffer.pop();
        n--;
    }
}
int main()
{
    string input;
    vector<int> numbers;
    int minus_flag = 0;
    cin>>input;
    int tmp = 0;
    
    for(int i = 0; i< input.size(); i++)
    {
        if(input[i] == '-' || input[i] == '+')
        {
            if(input[i] == '-')
            {
                if(minus_flag == 0)
                {
                    answer += tmp;
                    tmp  =0;
                    minus_flag = 1;
                }
                else
                {
                    buffer.push(tmp);
                    minus_flag = 1;
                    empty_stack();
                    tmp = 0;
                }
            }
            else if (input[i] == '+')
            {
                if(minus_flag == 0)
                {
                    answer += tmp;
                    tmp = 0;
                }
                else
                {
                    buffer.push(tmp);
                    tmp = 0;
                }
            }
        }
        else
            tmp = 10*tmp + (input[i] - '0');
    }
    if(minus_flag == 1)
    {
        answer -= tmp;
        empty_stack();
    }
    else
    {
        answer += tmp;
        while(buffer.empty() != 1){
            answer += buffer.top();
            buffer.pop();
        }
    }
    cout<<answer << '\n';
    return 0;
}
