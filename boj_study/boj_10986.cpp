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

long long int sum[1000001];
long long int cnt[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int m;
    cin>>n>>m;
    int tmp;
    long long int result =0;
    for(int i =1; i<=n; i++)
    {
        cin>>tmp;
        tmp%= m;
        
        sum[i] = (sum[i-1] + tmp)%m;  
        if(sum[i] == 0) result++;
        cnt[sum[i]]++;
        
    }
    
    for(int i =0; i< m ;i++)
    {
        /*
        if(cnt[i] == 1)
            result++;*/
      
        result += (cnt[i] * (cnt[i]-1))/2;
        
    }
    cout<<result;
    
}
