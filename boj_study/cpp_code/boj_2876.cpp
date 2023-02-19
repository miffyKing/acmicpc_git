#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int table[100002][2] = {0,};
int dp[100002][6] = {0,};

int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        table[i][0] = n1;
        table[i][1] = n2;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if(table[i][0] == j || table[i][1] == j)
            {
                dp[i][j] = dp[i-1][j]+1;
            }
        }
    }

    int maxval[n+1];
    

    return 0;
}
