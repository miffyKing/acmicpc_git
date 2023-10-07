#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<pair<long long ,long long>> meetings;
    
    cin>>n;
    for(int i = 0; i< n; i++)
    {
        int tmp1, tmp2;
        cin>>tmp1>>tmp2;
        meetings.push_back({tmp2, tmp1});           //끝, 시작 시간 순으로 집어넣음.
    }
    sort(meetings.begin(), meetings.end());
    int idx = 0;
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (idx > meetings[i].second) continue;
        cnt++;
        idx = meetings[i].first;
    }
    cout<<cnt<<'\n';
    return 0;
}
