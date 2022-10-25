#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<tuple<int,int,int>> planets;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        planets.push_back(make_tuple(a,b,c));
    }

}
