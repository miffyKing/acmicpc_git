#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool check_sosu(long long int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

long long int get_min_sosu(long long int n)
{
    while (1)
    {
        if (check_sosu(n) == true)
        {
            break;
        }
        n++;
    }
    return n;
}

int main()
{
    int tc;

    cin>>tc;

    for (int i = 0; i < tc; i++)
    {
        long long int n;
        cin>>n;
        if (n == 1 || n == 0)
        {
            cout<<2 <<"\n";
            continue;
        }
        cout << get_min_sosu(n) << "\n";
    }
    return 0;
}