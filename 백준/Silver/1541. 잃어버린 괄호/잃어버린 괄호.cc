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
  //  cout<<buffer.size()<<'\n';
    while(n > 0)
    {
        //cout<<"!!!!!\n";
        answer -= buffer.top();
        
        //cout<<"case 2 and tmp is " << buffer.top() << '\n';
        buffer.pop();
        n--;
    }
}
int main()
{
    string input;
    vector<int> numbers;
    vector<char> booho;
    //stack<int> buffer;
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
          //          cout<<"case 3 : and tmp is " << tmp << '\n';
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
         //           cout<<"case 1 : and tmp is " << tmp << '\n';
                    answer += tmp;
                    tmp = 0;
                }
                else
                {
                    buffer.push(tmp);
              //      cout<<"case 4 and tmp is " << tmp << '\n';
                    tmp = 0;
                }
            }
            
        }
        else
        {
            tmp = 10*tmp + (input[i] - '0');
        }
    }
    if(minus_flag == 1)
    {
  //      cout<<"end with m flag \n";
        answer -= tmp;
    //    cout<<"answer is " << answer << '\n';
        empty_stack();
        
    }
    else
    {
  //      cout<<"end with no m flag\n";
        answer += tmp;
        while(buffer.empty() != 1){
            answer += buffer.top();
            
    //        cout<<"case 5 and tmp is " << buffer.top() << '\n';
            buffer.pop();
        }
    }
        
    cout<<answer << '\n';
    return 0;
}
