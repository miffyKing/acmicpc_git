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

bool compare(const pair<int, int> a, const pair<int ,int> b)
{
    return a.first < b.first;
    
}

pair<int,int> arr[1000002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int n;
    
    cin>>t;
    for(int x =0; x< t; x++)
    {
        cin>>n;
        int min_val = 100002;
        int count =0;
        for(int i =0; i< n; i++)
        {
            cin>>arr[i].first>>arr[i].second;
        }
        sort(arr, arr+n);
        
        for(int i =0; i< n; i++)
        {
            min_val = min(min_val, arr[i].second);
            if(arr[i].second == min_val)
            {
                count++;
            }
            
        }
        cout<<count<<'\n';
    }

}
