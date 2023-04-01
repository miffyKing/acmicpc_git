#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    int garo = k/m;
    int sero = k - m*(k/m);
    cout<< garo << ' ' << sero << "\n";
    return 0;
}