#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
    int n, m;
    map <string, string> names;
    map <string, set<string>> groups;
    
    cin >> n >> m;
    for(int i = 0; i< n; i++)
    {
        string g_name;
        string tmp;
        set <string> tmp_set;
        int g_nums;
        cin>>g_name;
        cin>>g_nums;
        for(int j =0; j< g_nums; j++)
        {
            cin>>tmp; //    애들 이름
            names.insert({tmp, g_name});
            tmp_set.insert(tmp);
        }
        groups.insert({g_name,tmp_set});
    }
    for(int i = 0; i< m; i++)
    {
        string q;
        int o_z;
        cin>> q;
        cin>>o_z;
        if (o_z == 1)
        {
            auto found = names.find(q);
            cout<<found->second<<'\n';
        }
        else if (o_z == 0)
        {
            set<string> found = groups.find(q)->second;
            for(auto iter = found.begin(); iter != found.end(); iter++)
                cout<<*iter<<'\n';
        }
    }
    return 0;
}
