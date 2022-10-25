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

int dp[502][502];

int dp_func(int l, int r)
{
    int ret = 0;
    if(l == r) return 0;
    if(dp[l][r] ) return
    
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    cin>>n;
    for(int i =0; i< n; i++)
    {
        cin>>matrix[i][0]>>matrix[i][1];
    }
    
    dp_func(0, n-1);
    
    return 0;
}
