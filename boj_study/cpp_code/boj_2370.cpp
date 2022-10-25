#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include<queue>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>
//#include <string.h>

using namespace std;

int n,c;
//int spot[10002][2];
vector<pair<int,int>> spot;
//vector<pair<int,int>> spot2;
int new_spot[20004] = {-1};

vector<int> table;
vector<int> numbers;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    int tmp1,tmp2;
    for(int i =0; i< n; i++)
    {
        cin>>tmp1>>tmp2;
        spot.push_back(make_pair(tmp1, tmp2));
        numbers.push_back(tmp1);
        numbers.push_back(tmp2);
    }
    //int k = 0;
    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
    
    for(int i =0; i<n ;i++)
    {
        spot[i].first = (lower_bound(numbers.begin(), numbers.end(), spot[i].first) - numbers.begin());
        spot[i].second = (lower_bound(numbers.begin(), numbers.end(), spot[i].second) - numbers.begin());
    }
    int cnt = 1;
    
    for(int i =0; i<n; i++)
    {
        for(int j = spot[i].first; j<= spot[i].second; j++)
        {
            new_spot[j] = cnt;
        }
        cnt++;
    }
    int ans = 0;
    bool check[20005] = {false};
    
    for(int i =0; i< 20003;i++)
    {
        if(new_spot[i] != 0 && !check[new_spot[i]])
        {
            check[new_spot[i]] = true;
            ans++;
        }
    }
    cout<<ans;
}

