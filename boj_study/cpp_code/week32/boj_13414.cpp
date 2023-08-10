#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    string tmp;
    unordered_map <string, int> list;
    //map 에 넣으면서 find해서 있으면 그 때마다 그 인덱스 값을 바꿔준다.
    //map 이 정렬이 가능하다면? -> 이미 정렬되어서 나올 것임.
    cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        cin>>tmp;
        if(list.find(tmp) != list.end())    //찾은 경우
        {
            list.erase(tmp);
            list.insert({tmp, i});
        }
        else
            list.insert({tmp, i});
    }
    vector<pair<int,string>> answer;
    for(auto iter = list.begin(); iter != list.end(); iter++)
    {
        //cout<<"    " <<iter->first << ' ' << iter->second<<'\n';
        answer.push_back(make_pair(iter->second, iter->first));
    }
    sort(answer.begin(), answer.end());
    if (n < answer.size())
    {
        for(int i = 0; i< n; i++)
        {
            cout<< answer[i].second << '\n';
        }
    }
    else
    {
        for(int i = 0; i <answer.size(); i++)
            cout<<answer[i].second << '\n';
    }
    
    
    return 0;
}
