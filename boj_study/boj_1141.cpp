#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<string> lst(n);
    vector<bool> check(n, true);
    for (int i = 0; i <n; i++)
    {
        cin>>lst[i];
    }
    
    sort(lst.begin(), lst.end());
    
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (lst[j].substr(0, lst[i].size()) == lst[i])
            {
                check[i] = false;
                break;
            }
        }
    }
    
    int ans = 0;
    for (auto i : check)
    {
        if(i)
            ans++;
    }
    cout<<ans<<"\n";
    
    
    return 0;
}
