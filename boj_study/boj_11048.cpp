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

int arr[1004][1004];
int dp[1004][1004];
int n,m;
void dp_func(int n, int m)
{
    int ret;
    
    for(int i = 1; i <=n; i++)
    {
        for(int j =1; j <=m; j++)
        {
           // cout<< dp[i-1][j] << ' ' << dp[i][j-1] << ' ' << dp[i-1][j-1] <<'\n';
            ret = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
            //ret = max(ret, dp[i-1][j-1]);
            dp[i][j] = ret + arr[i][j];

          // cout<<i<< ' ' << j <<  ' ' << dp[i][j] <<"  max is  " << ret << '\n';
            
            
        }
    }
    cout<<dp[n][m]<<'\n';
    //return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin>>n>>m;
    
   // memset(dp, 0, sizeof(dp));
    
    
    for(int i =1; i<=n;i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>arr[i][j];
        }
    }
    //dp[1][1] = arr[1][1];           //없어도 될듯
    
    dp_func(n,m);
    
  //  cout<<'\n';
  /*
    for(int i=1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    //cout<< dp[n][m]<<'\n';
}

