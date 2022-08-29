
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <math.h>

using namespace std;

int main()
{
    int n;
    string name, action;
    unordered_set <string> m;
    
    cin >> n;
    for(int i = 0; i< n; i++)
    {
        cin >> name >> action;
        if (action == "enter" && m.find(name) == m.end())
            m.insert(name);
        else if (action == "leave" && m.find(name) != m.end())
            m.erase(name);
    }
    vector <string> ans(m.begin(), m.end());
    sort(ans.begin(), ans.end(), greater<>());
    for (auto x : ans) cout << x<<'\n';
}
