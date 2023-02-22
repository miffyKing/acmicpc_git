#include<iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    
    cin>>n;
    
    int dp[5005];
    for (int i = 0; i <= 5000; i++)
    {
        dp[i] = 5000;
    }
    
    dp[3] = 1;
    dp[5] = 1;
    
    for (int i = 3; i <= n; i+=3)
    {
        dp[i] = i/3;
    }
    for (int i = 5; i <= n; i++)
    {
        dp[i] = min(dp[i], dp[i-5] + 1);
    }
    

    if (dp[n] == 5000)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<dp[n]<<"\n";
    
    
    return 0;
}
