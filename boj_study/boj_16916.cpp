#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>
//#include <string.h>

using namespace std;

vector<int> makeTable(string pattern) {
    vector<int> table(pattern.size(), 0);

    for (int i = 1, j = 0; i < pattern.size(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

bool KMP(string text, string pattern) {
    vector<int> table = makeTable(pattern);

    for (int i = 0, j = 0; i < text.size(); i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (text[i] == pattern[j]) {
            if (j == pattern.size() - 1) {
                return true;
                j = table[j];
            } else {
                j++;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    string p;
    cin>>s;
    cin>>p;
    
    if(KMP(s, p)){
        cout<<1;
        
    }
    else{
        cout<< 0;
    }
    
}
