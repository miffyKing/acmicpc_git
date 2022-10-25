#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

set<string> group;

void get_parsed(string s, int size)
{
    for(int i = 0; i< s.size()-size+1; i++)
    {
        string tmp;
        tmp = s.substr(i, size);
        group.insert(tmp);
    }
}
int main()
{
    string s;
    
    cin>>s;
    for(int i = 1; i <= s.size(); i++)
    {
        get_parsed(s, i);
    }
    cout<<group.size()<<'\n';
    return 0;
}
