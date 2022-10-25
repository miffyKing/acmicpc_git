#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include<queue>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>
//#include <string.h>

using namespace std;

int n,k;
vector <string> words;
int alphabet[26];
int ans=-1;

int get_max()
{
    int cnt =0;
    for(int i =0; i<n; i++)
    {
        string str = words[i];
        bool flag = true;
        for(int j =0; j< str.length(); j++)
        {
            if(alphabet[str[j] - 'a'] == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
            cnt++;
                
    }
    return cnt;
    
}
void dfs_func(int idx, int cnt)
{
    if(cnt == k)
    {
        int cur_max = get_max();
        ans = max(cur_max, ans);
        return;
    }
    for(int i = idx; i < 26; i++)
    {
        if(alphabet[i] == 1) continue;
        alphabet[i] = 1;
        dfs_func(i, cnt+1);
        alphabet[i] =0 ;                    //알파벳들을 골랐다
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>k;
    if(k < 5)
    {
        cout<< 0;
        return 0;
    }
    for(int i =0; i<n ;i++)
    {
        string tmp;
        cin>>tmp;
        words.push_back(tmp);
    }
    alphabet['a' - 'a' ] = 1;
    alphabet['n' - 'a' ] = 1;
    alphabet['t' - 'a' ] = 1;
    alphabet['i' - 'a' ] = 1;
    alphabet['c' - 'a' ] = 1;
    k-=5;
    
    dfs_func(0,0);

    cout<<ans;
}
