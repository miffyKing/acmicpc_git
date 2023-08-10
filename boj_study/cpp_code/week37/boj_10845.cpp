#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    queue<int> q;
    cin>>n;
    for(int i = 0; i< n; i++)
    {
        string input;
        int number;
        cin>>input;
        if (input == "push")
        {
            cin>>number;
            q.push(number);
        }
        else if (input == "pop")
        {
            if (q.empty() == 1)
            {
                cout<<"-1\n";
                continue;
            }
            else
                cout<<q.front()<<'\n';
            q.pop();
        }
        else if (input == "size")
        {
            if (q.empty() == 1)
                cout<<"0\n";
            else
                cout<<q.size()<<'\n';
        }
        else if (input == "empty")
        {
            if (q.empty()== 1)
                cout<<"1\n";
            else
                cout<<"0\n";
        }
        else if (input == "front")
        {
            if (q.empty() == 1)
                cout<<"-1\n";
            else
                cout<<q.front()<<'\n';
        }
        else if (input == "back")
        {
            if (q.empty() == 1)
                cout<<"-1\n";
            else
                cout<<q.back()<<'\n';
        }
    }
    return 0;
}
