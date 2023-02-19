#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

string dp[10002];

string string_add(string x, string y)
{
    int num;
    int carry = 0;
    string result;
 
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
 
    while (x.length() < y.length()) {
        x += '0';
    }
    while (x.length() > y.length()) {
        y += '0';
    }
 
    for (int i = 0; i < x.length(); ++i) {
        num = (x[i] - '0' + y[i] - '0' + carry) % 10;
        result += to_string(num);
        carry = (x[i] - '0' + y[i] - '0' + carry) / 10;
    }
    if (carry != 0) {
        result += to_string(carry);
    }
 
    reverse(result.begin(), result.end());
 
    return result;
}


int main()
{
    int n;
    
    cin>>n;
    dp[0] = "0";
    dp[1] = "1";
    dp[2] = "1";
    for (int i = 3; i <= n; i++)
    {
        dp[i] = string_add(dp[i-1], dp[i-2]);
    }
    
  
    
    cout<<dp[n]<<"\n";
    
    return 0;
}
