#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack <int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,tmp;
    vector <int> lists;
    
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>tmp;
        lists.push_back(tmp);
    }
    long long answer = 0;
    for(int i = 0; i < n; i++)
    {
        
        while(!s.empty()  && s.top() <= lists[i])
            s.pop();
        answer +=s.size();
        s.push(lists[i]);
    }
    cout<<answer<<'\n';
    //맨 뒤에서부터 스택에 넣으면서
    
    return 0;
}
