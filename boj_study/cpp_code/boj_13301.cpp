#include<iostream>
#include <vector>

using namespace std;

int main()
{
    long long dp[80];
    
    dp[1] = 4;
    dp[2] = 6;
    dp[3] = 10;
    dp[4] = 16;
    int n;
    
    cin>>n;
    if (n <= 4)
    {
        cout<<dp[n];
        return 0;
    }
    for (int i = 5; i<= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n];
    return 0;
}
