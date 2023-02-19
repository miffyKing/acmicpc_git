#include <iostream>
#include <vector>

using namespace std;

long long dp[102];

int main()
{
    long long n,tc;
    cin>>tc;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;
    dp[9] = 7;
    dp[10] = 9;
    
    for (int idx= 0; idx < tc; idx++)
    {
        cin >> n;
        for (int i = 11; i <= n; i++)
        {
            dp[i] = dp[i-2] + dp[i-3];
        }
        cout<<dp[n]<<"\n";
    }
    
}
