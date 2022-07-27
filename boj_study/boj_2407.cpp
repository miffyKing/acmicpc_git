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
//#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n, m;
    long long int ans, i;
    
    cin>>n>>m;
    ans = 1;
    for(i = n; i > n-m; i--)
    {
        ans *= i;
    }
    for (i = 1; i <= m; i++)
    {
        ans /= i;
    }
    cout << ans;
    
    return (0);
}
