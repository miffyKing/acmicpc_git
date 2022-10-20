#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    vector <int> array;
    stack <pair<int,int>> s;
    vector <pair<int,int>> answer;
    int tmp;
    
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>tmp;
        array.push_back(tmp);
    //    s.push(tmp);
    }
    for(int i = 0; i< n; i++)
    {
        if(s.empty()== 1)
            s.push({array[i], i});
        else
        {
            if (array[i] > s.top().first)
            {
                while (s.top().first < array[i])
                {
                    //cout<<"!!!!\n";
                    answer.push_back({s.top().second, array[i]});
                    s.pop();
                    if (s.empty() == 1)
                        break;
                }
                s.push({array[i], i});
            }
            else
            {
                s.push({array[i], i});
            }
            
        }
    }
    if (s.empty()!= 1)
    {
        while(s.empty() != 1)
        {
            answer.push_back({s.top().second, -1});
            s.pop();
        }
    }
    
    sort(answer.begin(), answer.end());

    for(int i = 0; i< n; i++)
    {
        cout<< answer[i].second<< ' ';
    }
    cout<<'\n';
}
