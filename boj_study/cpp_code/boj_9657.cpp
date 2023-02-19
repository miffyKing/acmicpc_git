#include <iostream>
#include <vector>

using namespace std;

int dp[1002];

int main()
{
    int n;
    cin>>n;
    dp[1] = 0; // 상근
    dp[2] = 1;  //ㅊㅇ
    dp[3] = 0;  //ㅅㄱ
    dp[4] = 0;  //ㅅㄱ
    
    dp[5] = 0; //ㅅㄱ
    dp[6] = 0; // ㅅㄱ
    dp[7] = 1; //ㅊㅇ   6,4,3 이 모두 0이면 1임.
    
    for (int i = 8; i<=n; i++)
    {
        if (dp[i-1] == 0  && dp[i-3] == 0 && dp[i-4] == 0)
        {
            dp[i]  = 1;
        }else
            dp[i] = 0;
    }
    if (dp[n] == 0)
    {
        cout<<"SK\n";
    }
    else
    {
        cout<<"CY\n";
    }
    
    return 0;
}
