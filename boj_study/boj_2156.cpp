#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[10002];
int podo[10002];
int main()
{
    cin>>n;
    for(int i = 1; i<=n; i++)
        cin>>podo[i];
    dp[1] = podo[1];
    dp[2] = podo[1]+podo[2];
    for(int i=3;i<=n;i++) {
        dp[i] = max(dp[i-3] + podo[i] + podo[i-1], dp[i-2] + podo[i]);
        dp[i] = max(dp[i-1], dp[i]);
    }
    cout<<dp[n]<<'\n';
    return 0;
}
