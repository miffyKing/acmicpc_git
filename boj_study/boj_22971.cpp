#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


int dp[5002];

int main()
{
    int n, tmp;
    vector<int> scores;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        scores.push_back(tmp);
    }
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ( scores[i] > scores[j])  //더 크니까 부분수열 만들기 가능
            {
                dp[i] += dp[j];
                dp[i]%=998244353;
            }
        }
        dp[i]++;
        dp[i]%=998244353;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<dp[i] << " ";
    }cout<<"\n";


    return 0;
}
