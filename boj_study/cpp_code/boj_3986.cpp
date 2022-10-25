#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    int cnt = 0;
    cin>>n;
    for(int i = 0; i< n; i++)
    {
        string input;
        stack <int> s;
        cin>>input;
        for(int i = 0; i< input.size(); i++)
        {
            if (s.empty() == 1)
            {
                s.push(input[i]);
            }
            else if (s.top() == input[i])
            {
                s.pop();
            }
            else{
                s.push(input[i]);
            }
        }
        if (s.empty() == 1)
            cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}
