
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long b , long long c)
{
    //b가 홀수면 ,
    if (b == 0)
        return a%c;
    long long val = pow(a, b/2, c);
    if (b%2 == 0) return val;
    return val * a % c;
}
int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    cout<<pow(a,b,c);
}
