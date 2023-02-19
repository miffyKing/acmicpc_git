#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int dp[2002][2002];
int numbers[1002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>numbers[i];
        dp[i][i] = 1;
        if (i > 1 && numbers[i-1] == numbers[i])
        {
            dp[i-1][i] = 1;
        }
    }
    for (int i = 2; i <= n- 1; i++)
    {
        for (int j =1 ; i +j <= n; j++)
        {
            if (numbers[j] == numbers[i+j] && dp[j+1][i+j-1] == 1)
            {
                dp[j][i+j] = 1;
            }
        }
    }

    int tc;
    cin>>tc;
    for (int i = 0; i < tc; i++)
    {
        int n1, n2;
        cin>>n1 >> n2;
        cout<<dp[n1][n2]<<"\n";
    }
    
    
    return 0;
}

//  1 2 1 3 1 2 1
//1 1 0 0 0 0 0 0
//2 0 1 0 0 0 0 0
//1 1
//3
//1
//2
//1

