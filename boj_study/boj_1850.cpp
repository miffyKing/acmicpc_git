#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long int euclidean(long long int a, long long int b)
{
    long long int r = a % b;
    if(r== 0)
        return b;
    return euclidean(b,r);
}

int main()
{
    long long int a, b;
    cin>>a>>b;
    long long int gcd = 1;
    long long int result = euclidean(a, b); //유클리드 호제법on
    for (int i = 0; i < result; i++)
        cout<<"1";
    return 0;
}
