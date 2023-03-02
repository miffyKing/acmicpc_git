#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[4002][4002];
int max_val = 0;
int main()
{
    string a, b;
    cin>>a;
    cin>>b;
    
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
            {
                if (i >= 1 && j >= 1)
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    max_val = max(dp[i][j], max_val);
                    
                } else
                {
                    dp[i][j] = 1;
                    max_val = max(dp[i][j], max_val);
                }
            }
            else
            {
                dp[i][j] = 0;
            }
            
            
        }
    }
    cout<<max_val<<"\n";
    return 0;
}
