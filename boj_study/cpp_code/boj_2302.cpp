#include <iostream>
#include <vector>

using namespace std;

long long int dp[42];
int main()
{
    int n, m;
    vector<int> vips;
    long long int ans = 1;

    cin>>n;
    cin>>m;
    vips.push_back(0);
    if (n == m)
    {
        cout<<"1\n";
        return 0;
    }
    for(int i = 0; i < m; i++)
    {
        int tmp;
        cin>>tmp;
        vips.push_back(tmp);
    }
    vips.push_back(n+1);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i  = 4; i <=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    for (int i = 1; i< vips.size(); i++)
    {
        int diff = vips[i] - vips[i-1] -1;
        ans *= dp[diff];
    }
    cout<<ans<<"\n";
    return 0;
}