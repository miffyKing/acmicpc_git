#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    string tmp1, tmp2;
    map <string,string> list;
    
    cin>>n>>m;
    for(int i = 0; i<n; i++)
    {
        cin>>tmp1>>tmp2;
        list.insert({tmp1, tmp2});
    }
    
    for(int i = 0; i< m; i++)
    {
        cin>>tmp1;
        cout<< list[tmp1]<<'\n';
        
    }
    
    return 0;
}
