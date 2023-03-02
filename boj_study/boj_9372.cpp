#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    
    for (int idx = 0; idx < tc; idx++)
    {
        int n,m;
        int a,b;
        cin>>n>>m;
        for (int i = 0; i < m; i++)
        {
            cin>>a>>b;
        }
        cout<<n-1<<"\n";
    }
    return 0;
}
