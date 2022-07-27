#include <iostream>
#include <utility>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string.h>

using namespace std;

string s,t;

string dp_func(string cur);

int main()
{
    cin>>s ;
    cin>>t;
    
    while(s.size() != t.size())
    {
        char last_one;
        last_one = t[t.size() -1];
        t.pop_back();
        if(last_one == 'B')
            reverse(t.begin(), t.end());
    }
    if(s == t)
        cout<<1;
    else
        cout<<0;
    
    return 0;
}
