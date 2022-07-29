#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include<queue>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    int i;
    long long tmp = 0;
    long long ans = 0;
    int flag_minus = 0;
    cin>>input;
    i = 0;
    
    while (input[i])
    {
        if (input[i] == '-')
        {
            flag_minus = 1;
        }
        else if (input[i] == '+')
        {
           if (flag_minus == 1)
           {
               input[i] = '-';
           }
        }
        i++;
    }
    i = 0;
    int prev_booho = 0; //0이 +, 1이 -
    while (input[i])
    {
        if (input[i] == '-')
        {
            if(prev_booho == 1)
                ans -= tmp;
            else
                ans += tmp;
            tmp = 0;
            prev_booho = 1;
        }
        else if (input[i] == '+')
        {
            if(prev_booho == 1)
                ans -= tmp;
            else
                ans += tmp;
            tmp = 0;
            prev_booho = 0;
        }
        else
        {
            tmp *=10;
            tmp += input[i] - '0';
        }
        i++;
    }
    if(prev_booho == 1)
        ans -= tmp;
    else
        ans += tmp;
    cout<<ans;
    return (0);
}

