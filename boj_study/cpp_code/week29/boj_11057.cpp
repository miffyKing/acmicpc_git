#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long dp[1001][12];

int main()
{
    int n;
    
    cin>>n;
    for(int i =0; i<=9; i++ )
        dp[1][i] = 1;
    
    for(int i = 2; i<= n; i++)
    {
        for(int j = 0; j<= 9; j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%10007;
        }
    }
 
    
    long ans = 0;
    for(int i =0; i< 10; i++)
        ans+=dp[n][i];
    
    cout<<ans%10007<<'\n';
    return 0;
}
