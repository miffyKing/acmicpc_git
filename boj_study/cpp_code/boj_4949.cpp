#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
    string input;
    
    while (1)
    {
        getline(cin, input);
        int flag = 0;
        if(input == ".")
            break;
        else
        {
            stack <int> s;
            
            for(int i = 0; i< input.size(); i++)
            {
                if (input[i] == '(')
                    s.push('(');
                else if (input[i] == '[')
                    s.push('[');
                else if (input[i] == ')')
                {
                    if (s.empty()==1)
                    {
                        cout<<"no"<<'\n';
                        flag = 1;
                        break;
                    }
                    if (s.top() == '(')
                        s.pop();
                    else{
                        cout<<"no"<<'\n';
                        flag =1;
                        break;
                    }
                }
                else if(input[i] == ']')
                {
                    if (s.empty()==1)
                    {
                        cout<<"no"<<'\n';
                        flag = 1;
                        break;
                    }
                    if (s.top() == '[')
                        s.pop();
                    else{
                        cout<<"no"<<'\n';
                        flag =1;
                        break;
                    }
                }
            }
            if (s.empty() != 1)
            {
                if (flag == 0)
                    cout<<"no\n";
            }
            else if (flag == 0)
                cout<<"yes\n";
        }
    }
    return 0;
}
