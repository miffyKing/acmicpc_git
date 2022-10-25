#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>
//#include <string.h>

using namespace std;

bool compare(const tuple<int, int,int> a, const tuple<int ,int ,int> b)
{
    if(get<1>(a) == get<1>(b))
        return get<0>(a) < get<1>(b);
    else return get<1>(a) < get<1>(b);
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector <tuple <int ,int ,int >> time;
    int tmp1,tmp2;
    int ans =10000000;
    cin>> n;
    for(int i =0; i< n; i++)
    {
        cin>>tmp1>>tmp2;
        time.push_back(make_tuple(tmp1, tmp2, tmp2-tmp1));
    }
    sort(time.begin(), time.end(), compare);
    for(int i = n-1; i >=0; i--)
    {
        ans = min(ans, get<1>(time[i]));
        ans -= get<0>(time[i]);
    }
    if(ans >= 1)
        cout<<ans;
    else
        cout<<-1;
 
}
