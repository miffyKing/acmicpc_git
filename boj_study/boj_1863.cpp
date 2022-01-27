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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int tmp1, tmp2;
    stack<int> s;
    vector<int>arr;
    int cnt =0;
    cin>>n;
    for(int i =0; i<n; i++)
    {
        cin>>tmp1>>tmp2;
        arr.push_back(tmp2);
        
    }
    //s.push(0);
    for(int i =0; i<n ;i++)
    {
        //cin>>tmp1>>tmp2;
        while(!s.empty() && arr[i] < s.top())
        {
            if(s.top())
            {
                cnt++;
            }
            s.pop();
        }
        if(!s.empty() && arr[i] == s.top())
            continue;
        
        s.push(arr[i]);
    
      
    }
    
    //int cnt2=0;
    while(!s.empty())
    {
        if(s.top())
            cnt++;
        s.pop();
        //cnt2++;
    }
   // cnt--;
    cout<<cnt;
    
}
