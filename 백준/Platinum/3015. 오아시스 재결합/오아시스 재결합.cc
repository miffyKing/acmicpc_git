#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n, tmp;
    vector<long long> array;
    stack <pair<long long,long long >> s;
  //  vector<pair<int,int>> answer;
    long long answer = 0;
    cin>>n;
    for(int i =0; i< n; i++)
    {
        cin>>tmp;
        while(!s.empty() && tmp > s.top().first)
        {
            answer += s.top().second;
            s.pop();
        }
        if (s.empty())
            s.push({tmp, 1});
        else
        {
            if (s.top().first == tmp)
            {
                long long cur = s.top().second;
                s.pop();
                if (!s.empty()) answer++;
                answer += cur;
                s.push({tmp, cur+1});
            }
            else
            {
                answer += 1;
                s.push({tmp, 1});
            }
        }
    }
    cout<<answer << '\n';
    //
}
