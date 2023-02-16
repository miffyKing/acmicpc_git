#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> dp(10000);
int table[10000003];
    

int main()
{
    int n, tmp;
    vector<int> price;

    cin>>n;
    price.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin>>tmp;
        price.push_back(tmp);
    }

    dp[0] = 0;
    for (int i = 1; i <= n; i++) //일단 1개 팩으로 n개 다 살때의 경우 초기화
    {
        dp[i] = price[1]*(i);
    }

    for (int i = 1; i <= n ;i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] = max(dp[j - i] + price[i] , dp[j]); //기존 j 의 dp와 비교..
        }

    }

    cout<< dp[n] <<"\n";
    return 0;
}