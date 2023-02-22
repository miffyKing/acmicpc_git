#include <iostream>
#include <vector>

using namespace std;

int dp[10001];

int main()
{
    int n,k, tmp;
    vector<int> coin;
    vector<int> answer_hoobo;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        coin.push_back(tmp);
    }
    
    
    for (int i = 0; i <= 10000; i++)
    {
        dp[i] = 10002;
    }
    dp[0] = 0;
    
    
    for (int i = 0; i <= coin.size(); i++)
    {
        int index = coin[i];
        while (index <= k)
        {
            dp[index] = min(dp[index], dp[index - coin[i]] + 1);
            index = index + 1;
        }
    }
    
//    for (int i = 1; i <= k; i++)
//    {
//        cout<<dp[i] << " ";
//    }
//    cout<<"\n";
    if(dp[k] == 10002)
    {
        cout<<-1<<"\n";
        return 0;
    }
    cout<<dp[k]<<"\n";
    
    
    return 0;
}
