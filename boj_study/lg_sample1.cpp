#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
using namespace std;

vector<int> pi;
vector<int> si;
vector<int> cur_pos;
int main()
{
    
    int n , t;
    int tmp_p, tmp_s;
    cin>>n>>t;
    
    for(int i =0; i< n; i++)
    {
        cin>>tmp_p>>tmp_s;
        pi.push_back(tmp_p);
        si.push_back(tmp_s);
        cur_pos.push_back(tmp_p +  (tmp_s*t));
    }
    for(int i =n-1; i>=1 ; i--)
    {
        if(cur_pos[i] < cur_pos[i-1])
        {
            cur_pos[i-1] = cur_pos[i];
        }
    }
    set <int> group;
    
    for(int i =0; i<n; i++)
    {
        group.insert(cur_pos[i]);
    }
    cout<<group.size();
}
