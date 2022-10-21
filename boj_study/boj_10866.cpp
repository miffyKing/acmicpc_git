#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    deque<int> dq;
    
    cin>>n;
    string order;
    int number;
    for(int i = 0; i< n; i++)
    {
        cin>>order;
        if (order == "push_front")
        {
            cin>>number;
            dq.push_front(number);
        }
        else if (order == "push_back")
        {
            cin>>number;
            dq.push_back(number);
        }
        else if (order == "pop_front")
        {
            if (dq.empty()== 1)
            {
                cout<<"-1\n";
                continue;
            }
            cout<<dq.front()<<'\n';
            dq.pop_front();
        }
        else if (order == "pop_back")
        {
            if (dq.empty()== 1)
            {
                cout<<"-1\n";
                continue;
            }
            cout<<dq.back()<<'\n';
            dq.pop_back();
        }
        else if (order == "size")
        {
            cout<<dq.size()<<'\n';
        }
        else if (order == "empty")
        {
            cout<<dq.empty()<<'\n';
        }
        else if (order == "front")
        {
            if (dq.empty() == 1)
                cout<<"-1\n";
            else
                cout<<dq.front()<<'\n';
        }
        else if (order == "back")
        {
            if (dq.empty() == 1)
                cout<<"-1\n";
            else
                cout<<dq.back()<<'\n';
        }
    }
    return 0;
}
